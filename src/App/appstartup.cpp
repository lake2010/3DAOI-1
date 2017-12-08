#include <QDir>
#include <QFile>
#include <QTextStream>

#include "appstartup.hpp"
#include "SDK/customexception.hpp"

using namespace std;
using namespace App;
using namespace Job;
using namespace SDK;
using namespace SSDK::DB;

AppStartup::AppStartup()
{
    // 成员变量初始化
    this->m_appSettingPath = "";
    this->m_captureSettingPath = "";
    this->m_pMeasuredObj = nullptr;
    this->m_jobPath = "";
}

AppStartup::~AppStartup()
{
    // 释放内存空间
    delete [] this->m_pMeasuredObj;
    this->m_pMeasuredObj = nullptr;
}

void AppStartup::loadAppSetting( const QString& path )
{
    this->m_appSetting.load( path );
}

void AppStartup::loadCaptureSetting( const QString& path )
{
    this->m_captureSetting.load( path );
}

void AppStartup::readJobPath()
{
    try
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 判断程式文件夹是否存在，不存在则创建默认程式文件夹
        QDir dir( this->m_appSetting.jobFolderPath() );
        if( !dir.exists() )
        {
            QString filePath = dir.path();
            if( !dir.mkpath( filePath ) )
            {
                THROW_EXCEPTION("程式路径出错！");
            }
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 遍历程式文件夹

        // 将".xml"文件过滤掉
        QStringList filters;
        filters << "*[^xml]";
        dir.setNameFilters( filters );
        dir.setFilter( QDir::Files );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.1 如果文件夹下无程式，生成默认程式
        //2.2 如果文件夹下有程式，则列举到屏幕供用户选择
        QFileInfoList fileInfoList = dir.entryInfoList();        
        if ( fileInfoList.empty() )
        {
            this->m_pMeasuredObj = new MeasuredObj[OBJ_CNT];
            this->m_jobPath = "";
        }
        else
        {
            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //2.2.1 列举到文件到屏幕
            QFileInfo fileInfo;
            cout << "请输入数字，选择程式:" << endl;
            for ( int i = 0; i < fileInfoList.size(); ++i )
            {
                fileInfo = fileInfoList.at( i );
                cout << i << ": " << fileInfo.fileName().toStdString() << endl;
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //2.2.2 用户输入数字选择程式
            int num = 0;
            while( true )
            {
                cin >> num;
                if( cin && num < fileInfoList.size() && num >= 0 )
                {
                    fileInfo = fileInfoList.at( num );
                    break;
                }
                else
                {
                    cout << "无此选项，请重新选择:" << endl;
                    cin.clear();    // 清空cin缓冲区
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
            }
            this->m_jobPath = this->m_appSetting.jobFolderPath()  +
                              fileInfo.fileName();
        } // end of if ( fileInfoList.empty() )
    }
    catch( const CustomException& ex )
    {
        THROW_EXCEPTION( "程式读取失败！" );
    }
}

void AppStartup::generateJob( QString path,
                              InspectionData& inspectionData )
{
    SqliteDB v1Sqlite;
    try
    {
        // 创建数据库对象，打开传入路径的数据库
        v1Sqlite.open( path.toStdString() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 创建Job表，表中包含字段：Version、LastEditingTime
        string sqlCreate = "CREATE TABLE Job( Version TEXT, LastEditingTime TEXT );";
        v1Sqlite.execute( sqlCreate );
        // 插入各字段对应的数据
        string sqlInsert = "INSERT INTO Job( Version, LastEditingTime ) VALUES(?,?);";
        v1Sqlite.execute( sqlInsert, inspectionData.version(),
                                     inspectionData.lastEditingTime() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 创建Board表，表中包含字段：Name、SizeX、SizeY、OriginalX、OriginalY
        sqlCreate = "CREATE TABLE Board( Name TEXT, SizeX REAL, SizeY REAL, OriginalX REAL, OriginalY REAL );";
        v1Sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO Board( Name, SizeX, SizeY, OriginalX, OriginalY ) VALUES(?,?,?,?,?);";
        v1Sqlite.execute( sqlInsert, inspectionData.board().name(),
                                     inspectionData.board().sizeX(),
                                     inspectionData.board().sizeY(),
                                     inspectionData.board().originalX(),
                                     inspectionData.board().originalY() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 创建MeasuredObjs表，表中包含字段：Name、PosX、PosY、Width、Height、Angle
        sqlCreate = "CREATE TABLE MeasuredObjs( Name TEXT, PosX REAL, PosY REAL, Width REAL, Height REAL, Angle REAL );";
        v1Sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO MeasuredObjs( Name, PosX, PosY, Width, Height, Angle ) VALUES(?,?,?,?,?,?);";
        v1Sqlite.prepare( sqlInsert );
        v1Sqlite.begin();

        MeasuredObj *pCurrentObj = inspectionData.board().measureObjs().pHeadObj();
        while ( pCurrentObj != nullptr )
        {
            v1Sqlite.executeWithParms( pCurrentObj->name().data(),
                                       pCurrentObj->body().posX(),
                                       pCurrentObj->body().posY(),
                                       pCurrentObj->body().width(),
                                       pCurrentObj->body().height(),
                                       pCurrentObj->body().angle() );
            //获取下一个检测对象的地址
            pCurrentObj = pCurrentObj->pNextObj();
        }
        v1Sqlite.commit();

        v1Sqlite.close();
    }
    catch( const CustomException& ex )
    {
        if( v1Sqlite.isOpened() )
        {
            v1Sqlite.reset();
            v1Sqlite.close();
        }
        THROW_EXCEPTION( ex.what() );
    }
}

void AppStartup::loadInspectionData( QString path )
{
    SqliteDB sqlite( path.toStdString() );
    try
    {        
        auto isOpened = sqlite.isOpened();
        if( isOpened )
        {
            // 记录程式中被测对象的数量
            string rowQuery = "SELECT COUNT(*) FROM MeasuredObjs";
            sqlite.prepare( rowQuery );
            int objCnt = sqlite.executeScalar<int>( rowQuery );
            //>>>----------------------------------------------------------------------------------------------------------
            //1 读取Job表
            // 读取版本
            string selectedString = "select Version from Job";
            sqlite.prepare( selectedString );
            string version = sqlite.executeScalar<string>( selectedString );

            // 兼容V1版本
            if( version == "V1" )
            {
                version = "V1[兼容模式]";
                convertFromV1( sqlite );
                cout << "版本兼容成功!" << endl;
            }
            this->m_inspectionData.setVersion( version );

            // 读取上次编辑时间
            selectedString = "select LastEditingTime from Job";
            sqlite.prepare( selectedString );
            this->m_inspectionData.setLastEditingTime( sqlite.executeScalar<std::string>( selectedString ) );

            //>>>----------------------------------------------------------------------------------------------------------
            //2 读取Board表
            selectedString = "select * from Board";
            sqlite.prepare( selectedString );
            sqlite.begin();

            while( true )
            {
                sqlite.step();
                if ( sqlite.latestErrorCode() == SQLITE_DONE )
                {
                    break;
                }
                this->m_inspectionData.board().setName( boost::get<string>( sqlite.columnValue(0) ) );
                this->m_inspectionData.board().setSizeX( boost::get<double>( sqlite.columnValue(1) ) );
                this->m_inspectionData.board().setSizeY( boost::get<double>( sqlite.columnValue(2) ) );
                this->m_inspectionData.board().setOriginalX( boost::get<double>( sqlite.columnValue(3) ) );
                this->m_inspectionData.board().setOriginalY( boost::get<double>( sqlite.columnValue(4) ) );
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //3 读取MeasuredObjs表
            selectedString = "select * from MeasuredObjs";
            sqlite.prepare( selectedString );

            this->m_pMeasuredObj = new MeasuredObj[objCnt];
            for (int i = 0; i < objCnt; ++i)
            {
                sqlite.step();

                this->m_pMeasuredObj[i].setName( boost::get<string>( sqlite.columnValue(0) ) );
                this->m_pMeasuredObj[i].body().setPosX( boost::get<double>( sqlite.columnValue(1) ) );
                this->m_pMeasuredObj[i].body().setPosY( boost::get<double>( sqlite.columnValue(2) ) );
                this->m_pMeasuredObj[i].body().setWidth( boost::get<double>( sqlite.columnValue(3) ) );
                this->m_pMeasuredObj[i].body().setHeight( boost::get<double>( sqlite.columnValue(4) ) );
                this->m_pMeasuredObj[i].body().setAngle( boost::get<double>( sqlite.columnValue(5) ) );

                this->m_inspectionData.board().measureObjs().pushTail( this->m_pMeasuredObj[i] );
            }
            sqlite.reset();
            sqlite.close();
        }
        else
        {
            THROW_EXCEPTION("程式加载失败！")
        }
    }
    catch( const CustomException& ex )
    {        
        if( sqlite.isOpened() )
        {
            sqlite.reset();
            sqlite.close();
        }      
        THROW_EXCEPTION( ex.what() );
    }
}

void AppStartup::writeToXml( QString path,
                             InspectionData& inspectionData )
{
    try
    {
        // 创建Job文档
        QDomDocument job;

        // 在Job文档下添加检测数据信息
        inspectionData.writeToXml( job );

        // 保存xml文件
        QFile file( path );
        // 只写模式打开文件
        if ( file.open( QFile::WriteOnly | QFile::Text ) )
        {
            // 输出到文件
            QTextStream outStream( &file );
            // 保存文件，缩进2格
            job.save( outStream, 2 );
            // 关闭文件
            file.close();
        }
        else
        {
            THROW_EXCEPTION( "创建xml文件失败！" );
        }
    }
    catch( const CustomException& ex )
    {
        THROW_EXCEPTION( ex.what() );
    }
}

void AppStartup::convertFromV1( SqliteDB& sqlite )
{
    // 将Job表的版本号改为V2
    string sqlUpdate = "UPDATE Job SET Version='V1[兼容模式]'";
    sqlite.execute( sqlUpdate );

    // 在MeasuredObjs表中添加Angle字段，并设置默认值为0
    string addColumn = "ALTER TABLE MeasuredObjs ADD Angle REAL DEFAULT 0";
    sqlite.execute( addColumn );
}

