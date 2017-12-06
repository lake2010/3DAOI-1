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

void InspectionData::writeToXml( QDomDocument& job )
{
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
}


