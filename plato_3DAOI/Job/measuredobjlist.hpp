#ifndef MEASUREDOBJLIST_HPP
#define MEASUREDOBJLIST_HPP

#include "Job/measuredobj.hpp"


namespace Job
{
    /**
     *  @brief    MeasuredObjList
     *            双向链表，用于存放被测目标
     *  @author   plato
     *  @version  1.00 2017-11-23 plato
     *                 note:create it
     */
    class MeasuredObjList
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   MeasuredObjList:  构造函数
        *  @param   N/A
        *  @return  N/A
        */
        MeasuredObjList();

        /*
        *  @brief   ~MeasuredObjList: 析构函数
        *           用于释放内存
        *  @param   N/A
        *  @return  N/A
        */
        ~MeasuredObjList();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   pushHead:         在链表头部插入节点
        *  @param   measuredObj:      插入的节点对象
        *  @return  N/A
        */
        void pushHead( MeasuredObj measuredObj );

        /*
        *  @brief   pushTail:         在链表尾部插入节点
        *  @param   measuredObj:      插入的节点对象
        *  @return  N/A
        */
        void pushTail( MeasuredObj measuredObj );

        /*
        *  @brief   pullTail：        移除最后的节点
        *  @param   N/A
        *  @return  N/A
        */
        void pullTail();

        /*
        *  @brief   print：           打印节点内容
        *  @param   N/A
        *  @return  N/A
        */
        void print();

        /*
        *  @brief   clear：           清空所有的元素
        *  @param   N/A
        *  @return  N/A
        */
        void clear();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get&set functions

        /*
        *  @brief   size:    链表大小
        *  @param   N/A
        *  @return  传入的链表大小
        */
        int size() { return this->m_size; }

        /*
        *  @brief   setSize: 设置链表大小
        *  @param   size:    传入的链表大小
        *  @return  N/A
        */
        void setSize( int size ) { this->m_size = size; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_size;                         // 链表大小
        MeasuredObj* m_pHeadNode;           // 链表的头节点指针对象
        MeasuredObj* m_pTailNode;           // 链表的尾节点指针对象

    };

}//End of namespace Job

#endif // MEASUREDOBJLIST_HPP
