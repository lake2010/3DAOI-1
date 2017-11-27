#include "measuredobjlist.hpp"

using namespace std;
using namespace Job;

MeasuredObjList::MeasuredObjList()
{
    // 成员变量初始化
    this->m_size = 0;
    this->m_pHeadNode = nullptr;
    this->m_pTailNode = nullptr;
}

MeasuredObjList::~MeasuredObjList()
{
    clear();    // 清空链表中所有元素并释放内存
}

void MeasuredObjList::pushHead( MeasuredObj measuredObj )
{
    // 如果一开始没有节点，则创建一个新节点
    if ( this->m_pHeadNode == nullptr )
    {
        MeasuredObj* pNewNode = nullptr;    // 定义一个新节点指针
        pNewNode = new MeasuredObj();       // 创建一个新节点对象
        *pNewNode = measuredObj;            // 将传入的参数赋值给新节点对象
        // 头节点指针和尾节点指针同时指向这个新节点
        this->m_pHeadNode = this->m_pTailNode = pNewNode;
    }
    // 如果一开始有节点，则加在该节点前面插入新节点
    else
    {
        MeasuredObj* pNewNode = nullptr;
        pNewNode = new MeasuredObj();
        *pNewNode = measuredObj;

        // 1.将新节点的后继节点指针指向头节点
        // 2.将头节点的前继节点指针指向新节点
        // 3.头节点指针指向新节点
        pNewNode->setpNext( this->m_pHeadNode );
        this->m_pHeadNode->setpPre( pNewNode );
        this->m_pHeadNode = pNewNode;
    }
    ++this->m_size;     // 链表大小加1
}

void MeasuredObjList::pushTail( MeasuredObj measuredObj )
{
    // 如果一开始没有节点，则创建一个新节点
    if ( this->m_pHeadNode == nullptr )
    {
        MeasuredObj* pNewNode = nullptr;
        pNewNode = new MeasuredObj();
        *pNewNode = measuredObj;
        // 头节点指针和尾节点指针同时指向这个新节点
        this->m_pHeadNode = this->m_pTailNode = pNewNode;
    }
    // 如果一开始有节点，则加在该节点后面插入新节点
    else
    {
        MeasuredObj* pNewNode = nullptr;
        pNewNode = new MeasuredObj();
        *pNewNode = measuredObj;

        // 1.将尾节点的后继节点指针指向新节点
        // 2.将新节点的前继节点指针指向尾节点
        // 3.尾节点指针指向新节点
        this->m_pTailNode->setpNext( pNewNode );
        pNewNode->setpPre( this->m_pTailNode );
        this->m_pTailNode = pNewNode;
    }
    ++this->m_size;
}

void MeasuredObjList::pullTail()
{
    // 如果一开始没有节点，则结束此函数
    if ( this->m_pHeadNode == nullptr )
    {
        return;
    }
    // 如果链表中只有一个节点，则删除此节点
    else if ( this->m_size == 1 )
    {
        delete this->m_pHeadNode;
        this->m_pHeadNode = this->m_pTailNode = nullptr;
    }
    // 如果链表中有多个节点
    else
    {
        // 1.尾节点的前继节点替换为尾节点
        // 2.删除尾节点的后继节点
        // 3.将尾节点的后继节点指针置为nullptr
        this->m_pTailNode = this->m_pTailNode->pPre();
        delete this->m_pTailNode->pNext();
        this->m_pTailNode->setpNext( nullptr );
    }
    --this->m_size;     // 链表大小减1
}

void MeasuredObjList::print()
{
    // 定义一个当前节点指针，赋予头节点指针
    MeasuredObj *pCurrentNode = this->m_pHeadNode;
    // 打印链表中所有元素
    while ( pCurrentNode != nullptr )
    {
        cout << pCurrentNode->name() << " "
             << pCurrentNode->body().angle() << " "
             << pCurrentNode->body().height() << " "
             << pCurrentNode->body().posX() << " "
             << pCurrentNode->body().posY() << " "
             << pCurrentNode->body().width() << endl;
        // 当前节点的后继节点替换为当前节点
        pCurrentNode = pCurrentNode->pNext();
    }
    // 打印元素个数，即链表的大小
    cout << "元素个数：" << MeasuredObjList::size() << endl;
}

void MeasuredObjList::clear()
{
    // 定义一个当前节点和下一个节点，分别赋予头节点指针
    MeasuredObj* pCurrentNode = this->m_pHeadNode;
    MeasuredObj* pNextCurrentNode = this->m_pHeadNode;
    // 删除链表中所有节点
    while ( pNextCurrentNode != nullptr )
    {
        // 1.下一节点的后继节点替换为下一节点
        // 2.删除当前节点
        // 3.当前节点指针指向下一节点
        pNextCurrentNode = pNextCurrentNode->pNext();
        delete pCurrentNode;
        pCurrentNode = pNextCurrentNode;
    }
    this->m_pHeadNode = this->m_pTailNode = nullptr;
    this->m_size = 0;     // 链表大小置为0
}
