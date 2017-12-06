#include <QFile>
#include <QTextStream>

#include "appstartup.hpp"

using namespace App;

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

void AppStartup::loadInspectionData( const QString& path )
{

}

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

