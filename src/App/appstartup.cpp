#include <QDir>
#include <QFile>
#include <QTextStream>

#include "DB/sqlitedb.hpp"

#include "appstartup.hpp"
#include "SDK/customexception.hpp"

using namespace std;
using namespace App;
using namespace SSDK::DB;

AppStartup::AppStartup()
{

}

AppStartup::~AppStartup()
{

}

void AppStartup::loadAppSetting( const QString& path )
{
    this->m_appSetting.load( path );
}

void AppStartup::loadCaptureSetting( const QString& path )
{
    this->m_captureSetting.load( path );
}

void AppStartup::readJobFolder()
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 判断程式文件夹是否存在，不存在则创建默认程式文件夹
    QDir dir( QString::fromStdString( this->m_appSetting.jobFolderPath() ) );
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

    //2.1 如果文件夹下无程式，生成默认程式，打印检测信息并写入xml文件
    //2.2 如果文件夹下有程式，则列举到屏幕，加载用户选择的程式
    QFileInfoList fileInfoList = dir.entryInfoList();
    if ( fileInfoList.empty() )
    {
        //2.1.1 生成检测数据
        Job::InspectionData inspectionData;
        Job::MeasuredObj objs[OBJ_CNT];
        DataGenerator data;
        data.generateData( inspectionData, objs );
        //2.1.2 生成程式
        generateJob( QString::fromStdString(
                     this->m_appSetting.jobFolderPath() ) + "V1",
                     inspectionData );
        //2.1.3 打印数据到屏幕
        cout << endl << "检测信息如下：" << endl;
        inspectionData.print();
        //2.1.4 将数据写入xml文件
        writeToXml( QString::fromStdString(
                    this->m_appSetting.jobFolderPath() ) + "V1.xml",
                    inspectionData );
        cout << "文件夹中无程式，已生成默认程式!" << endl;
    }
    else
    {
        //2.2.1 列举到文件到屏幕
        QFileInfo fileInfo;
        cout << "请输入数字，选择程式:" << endl;
        for ( int i = 0; i < fileInfoList.size(); ++i )
        {
          fileInfo = fileInfoList.at( i );
          cout << i << ": " << fileInfo.fileName().toStdString() << endl;
        }
        //2.2.2 用户输入数字选择程式
        int num = 0;
        while( true )
        {
            cin >> num;
            if( cin && num < fileInfoList.size() && num >= 0 )
            {
                fileInfo = fileInfoList.at( num );
                cout << "success" << endl;
                // loadInspectionData();
                break;
            }
            else
            {
                cout << "无此选项，请重新选择:" << endl;
                cin.clear();    // 清空cin缓冲区
                cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            }
        }
    } // end of if ( fileInfoList.empty() )
}

void AppStartup::generateJob( QString path,
                              Job::InspectionData& inspectionData )
{
    // 创建数据库对象，打开传入路径的数据库
    SqliteDB v1Sqlite;
    v1Sqlite.open( path.toStdString() );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 创建Job表，表中包含字段：Version、LastEditingTime
    string sqlCreate = "CREATE TABLE Job( Version TEXT, LastEditingTime TEXT );";
    v1Sqlite.execute(sqlCreate);
    // 插入各字段对应的数据
    string sqlInsert = "INSERT INTO Job( Version, LastEditingTime ) VALUES(?,?);";
    v1Sqlite.execute( sqlInsert, inspectionData.version(),
                                 inspectionData.lastEditingTime() );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2 创建Board表,表中包含字段：Name、SizeX、SizeY、OriginalX、OriginalY
    sqlCreate = "CREATE TABLE Board( Name TEXT, SizeX REAL, SizeY REAL, OriginalX REAL, OriginalY REAL );";
    v1Sqlite.execute(sqlCreate);

    sqlInsert = "INSERT INTO Board( Name, SizeX, SizeY, OriginalX, OriginalY ) VALUES(?,?,?,?,?);";
    v1Sqlite.execute( sqlInsert,inspectionData.board().name(),
                                inspectionData.board().sizeX(),
                                inspectionData.board().sizeY(),
                                inspectionData.board().originalX(),
                                inspectionData.board().originalY() );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3 创建MeasuredObjs表,表中包含字段：Name、PosX、PosY、Width、Height
    sqlCreate = "CREATE TABLE MeasuredObjs( Name TEXT, PosX REAL, PosY REAL, Width REAL, Height REAL );";
    v1Sqlite.execute(sqlCreate);

    sqlInsert = "INSERT INTO MeasuredObjs( Name, PosX, PosY, Width, Height ) VALUES(?,?,?,?,?);";
    v1Sqlite.prepare(sqlInsert);
    v1Sqlite.begin();

    Job::MeasuredObj *pCurrentObj = inspectionData.board().measureObjs().pHeadObj();
    while ( pCurrentObj != nullptr )
    {
        v1Sqlite.executeWithParms( pCurrentObj->name().data(),
                                   pCurrentObj->body().posX(),
                                   pCurrentObj->body().posY(),
                                   pCurrentObj->body().width(),
                                   pCurrentObj->body().height() );
        //获取下一个检测对象的地址
        pCurrentObj = pCurrentObj->pNextObj();
    }
    v1Sqlite.commit();

    v1Sqlite.close();
}

//void AppStartup::loadInspectionData( const QString& path )
//{

//}

void AppStartup::writeToXml( QString fileName,
                             Job::InspectionData& inspectionData )
{
    // 创建Job文档
    QDomDocument job;

    // 在Job文档下添加检测数据信息
    inspectionData.writeToXml( job );

    // 保存xml文件
    QFile file( fileName );
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
}

