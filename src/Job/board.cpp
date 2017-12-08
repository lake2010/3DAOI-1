#include "board.hpp"

#include <iomanip>

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

void Board::writeToXml( QDomDocument& job, QDomElement& root )
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 创建基板信息的节点及其属性，并作为传入的根节点的子节点

    // 创建第一个子节点及其子元素（记录基板信息）
    QDomElement child = job.createElement( QString::fromStdString( name() ) );
    // 创建第一个子节点的属性（基板名称、大小、位置）,精确到小数点后两位
    child.setAttribute( "SizeX", QString::number( sizeX(), 0, 2 ) );
    child.setAttribute( "SizeY", QString::number( sizeY(), 0, 2 ) );
    child.setAttribute( "OriginalX", QString::number( originalX(), 0, 2 ) );
    child.setAttribute( "OriginalY", QString::number( originalY(), 0, 2 ) );
    // 添加节点child作为根节点root的子节点
    root.appendChild( child );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2 循环创建列表中被测对象的节点及其属性，并作为board的子节点

    // 定义一个当前对象指针，赋予列表的头对象指针
    MeasuredObj *pCurrentObj = measureObjs().pHeadObj();
    // 创建列表中所有元素的属性
    while ( pCurrentObj != nullptr )
    {
        // 创建第二个子节点及其子元素（记录被测对象信息）
        QDomElement measuredObj = job.createElement( QString::fromStdString(
                                                     pCurrentObj->name() ) );
        // 创建第二个子节点的属性（被测对象坐标、宽、高）,精确到小数点后两位
        measuredObj.setAttribute( "PosX", QString::number(
                                          pCurrentObj->body().posX(), 0, 2 ) );
        measuredObj.setAttribute( "PosY", QString::number(
                                          pCurrentObj->body().posY(), 0, 2 ) );
        measuredObj.setAttribute( "Width", QString::number(
                                           pCurrentObj->body().width(), 0, 2 ) );
        measuredObj.setAttribute( "Height", QString::number(
                                            pCurrentObj->body().height(), 0, 2 ) );
        // 添加节点measuredObj作为子节点child的子节点
        child.appendChild( measuredObj );

        // 当前对象的下一对象替换为当前对象
        pCurrentObj = pCurrentObj->pNextObj();
    }
}
