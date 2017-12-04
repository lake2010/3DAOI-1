#include <QFile>
#include <QTextStream>

#include "inspectiondata.hpp"

using namespace Job;

InspectionData::InspectionData()
{
    this->m_version = "";
    this->m_lastEditingTime = "";
}

InspectionData::~InspectionData()
{

}

void InspectionData::writeToXml( QString fileName )
{
    // 创建Job文档
    QDomDocument job;

    // 创建根节点及其根元素（记录检测的数据）
    QDomElement root = job.createElement( "InspectionData" );
    // 创建根节点的属性
    root.setAttribute( "Version",
                       QString::fromStdString( version() ) );
    root.setAttribute( "LastEditingTime",
                       QString::fromStdString( lastEditingTime() ) );
    // 在Job文档下添加根节点
    job.appendChild( root );

    // 在Job文档中的根节点下添加基板信息
    board().writeToXml( job, root );

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


