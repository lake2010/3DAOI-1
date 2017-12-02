#include "board.hpp"

using namespace Job;

Board::Board()
{
    // 成员变量初始化
    this->m_name = "";
    this->m_sizeX = 0;
    this->m_sizeY = 0;
    this->m_originalX = 0;
    this->m_originalY = 0;
}

Board::~Board()
{

}

void Board::writeToXml( QDomDocument job,
                        QDomElement root )
{
    // 创建第一个子节点及其子元素（记录基板信息）
    QDomElement child = job.createElement( "Board" );
    // 创建第一个子节点的属性（基板名称、大小、位置）
    child.setAttribute( "Name", QString::fromStdString( name() ) );
    child.setAttribute( "SizeX", sizeX() );
    child.setAttribute( "SizeY", sizeY() );
    child.setAttribute( "OriginalX", originalX() );
    child.setAttribute( "OriginalY", originalY() );
    // 添加节点child作为根节点root的子节点
    root.appendChild( child );

    // 定义一个当前对象指针，赋予列表的头对象指针
    MeasuredObj *pCurrentObj = measureObjs().pHeadObj();
    // 创建列表中所有元素的属性
    while ( pCurrentObj != nullptr )
    {
        // 创建第二个子节点及其子元素（记录被测对象信息）
        QDomElement measuredObj = job.createElement( QString::fromStdString(
                                                     pCurrentObj->name() ) );
        // 创建第二个子节点的属性（被测对象坐标、宽、高）
        measuredObj.setAttribute( "PosX", pCurrentObj->body().posX() );
        measuredObj.setAttribute( "PosY", pCurrentObj->body().posY() );
        measuredObj.setAttribute( "Width", pCurrentObj->body().width() );
        measuredObj.setAttribute( "Height", pCurrentObj->body().height() );
        // 添加节点measuredObj作为子节点child的子节点
        child.appendChild( measuredObj );

        // 当前对象的下一对象替换为当前对象
        pCurrentObj = pCurrentObj->pNextObj();
    }
}
