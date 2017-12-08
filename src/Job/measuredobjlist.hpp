#ifndef MEASUREDOBJLIST_HPP
#define MEASUREDOBJLIST_HPP

#include "measuredobj.hpp"

namespace Job
{
    /**
     *  @brief    MeasuredObjList
     *                  被测对象列表：
     *                  1.类中使用双向链表结构，可实现对列表中对象头插、尾插、尾删的功能
     *                  2.该类还有记录列表中对象个数、打印对象、清空对象的功能
     *  @author   plato
     *  @version  2.00 2017-11-23 plato
     *                 note:create it
     */
    class MeasuredObjList
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   MeasuredObjList: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        MeasuredObjList();

        /*
        *  @brief   ~MeasuredObjList: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~MeasuredObjList();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   pushHead: 在列表头部插入一个对象
        *  @param   newObj: 插入的新对象
        *  @return  N/A
        */
        void pushHead( MeasuredObj& newObj );

        /*
        *  @brief   pushTail: 在列表尾部插入一个对象
        *  @param   newObj: 插入的新对象
        *  @return  N/A
        */
        void pushTail( MeasuredObj& newObj );

        /*
        *  @brief   pullTail: 移除尾部的一个对象
        *  @param   N/A
        *  @return  N/A
        */
        void pullTail();

        /*
        *  @brief   print: 打印对象内容
        *  @param   N/A
        *  @return  N/A
        */
        void print();

        /*
        *  @brief   clear: 清空所有的对象
        *  @param   N/A
        *  @return  N/A
        */
        void clear();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        /*
        *  @brief   size: 列表大小
        *  @param   N/A
        *  @return  传入的列表大小
        */
        int size() { return this->m_size; }

        /*
        *  @brief   pHeadObj: 列表的头对象指针
        *  @param   N/A
        *  @return  列表的头对象指针
        */
        MeasuredObj *pHeadObj() { return this->m_pHeadObj; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_size;                 // 列表大小
        MeasuredObj *m_pHeadObj;    // 列表的头对象指针
        MeasuredObj *m_pTailObj;    // 列表的尾对象指针
    };

}//End of namespace Job

#endif // MEASUREDOBJLIST_HPP
