#include <iomanip>

#include "measuredobjlist.hpp"

using namespace std;
using namespace Job;

MeasuredObjList::MeasuredObjList()
{
    // 成员变量初始化
    this->m_size = 0;
    this->m_pHeadObj = nullptr;
    this->m_pTailObj = nullptr;
}

MeasuredObjList::~MeasuredObjList()
{

}

void MeasuredObjList::pushHead( MeasuredObj& newObj )
{
    //1 如果一开始没有对象，则创建一个新对象;
    //2 如果一开始有对象，则加在该对象前面插入新对象
    if ( this->m_pHeadObj == nullptr )
    {
        //1.1 头对象指针和尾对象指针同时指向这个新对象
        this->m_pHeadObj = this->m_pTailObj = &newObj;
    }    
    else
    {
        //2.1 将新对象的下一对象指针指向头对象
        //2.2 将头对象的上一对象指针指向新对象
        //2.3 头对象指针指向新对象
        ( &newObj )->setPNextObj( this->m_pHeadObj );
        this->m_pHeadObj->setpPreObj( &newObj );
        this->m_pHeadObj = &newObj;
    }
    this->m_size++;     // 列表大小加1
}

void MeasuredObjList::pushTail( MeasuredObj& newObj )
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 如果一开始没有对象，则创建一个新对象;
    //2 如果一开始有对象，则加在该对象后面插入新对象
    if ( this->m_pHeadObj == nullptr )
    {
        //1.1 头对象指针和尾对象指针同时指向这个新对象
        this->m_pHeadObj = this->m_pTailObj = &newObj;
    }    
    else
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2.1 将尾对象的下一对象指针指向新对象
        //2.2 将新对象的上一对象指针指向尾对象
        //2.3 尾对象指针指向新对象
        this->m_pTailObj->setPNextObj( &newObj );
        ( &newObj )->setpPreObj( this->m_pTailObj );
        this->m_pTailObj = &newObj;
    }
    this->m_size++;
}

void MeasuredObjList::pullTail()
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 如果一开始没有对象，则结束此函数;
    //2 如果列表中只有一个对象，则删除此对象;
    //3 如果列表中有多个对象
    if ( this->m_pHeadObj == nullptr )
    {
        return;
    }   
    else if ( this->m_size == 1 )
    {
        this->m_pHeadObj = this->m_pTailObj = nullptr;
    }   
    else
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3.1 尾对象的上一对象替换为尾对象
        //3.2 将尾对象的下一对象指针置为nullptr
        this->m_pTailObj = this->m_pTailObj->pPreObj();
        this->m_pTailObj->setPNextObj( nullptr );
    }
    this->m_size--;     // 列表大小减1
}

void MeasuredObjList::print()
{
    // 定义一个当前对象指针，赋予头对象指针
    MeasuredObj *pCurrentObj = this->m_pHeadObj;
    // 打印列表中所有元素
    while ( pCurrentObj != nullptr )
    {
        cout << fixed << setprecision( 2 )    // 精确到小数点后两位
             << pCurrentObj->name() << "\t"
             << "X: " << pCurrentObj->body().posX() << "\t"
             << "Y: " << pCurrentObj->body().posY() << "\t"
             << "Width: " << pCurrentObj->body().width() << "\t"
             << "Height: " << pCurrentObj->body().height() << "\t"
             << endl;
        // 当前对象的下一对象替换为当前对象
        pCurrentObj = pCurrentObj->pNextObj();
    }
    // 打印元素个数，即列表的大小
    cout << "元素个数：" << MeasuredObjList::size() << endl;
}

void MeasuredObjList::clear()
{
    this->m_pHeadObj = this->m_pTailObj = nullptr;
    this->m_size = 0;     // 列表大小置为0
}
