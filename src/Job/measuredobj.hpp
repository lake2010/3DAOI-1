#ifndef MEASUREDOBJ_HPP
#define MEASUREDOBJ_HPP

#include <iostream>

#include "SDK/rectangle.hpp"

namespace Job
{
    /**
     *  @brief    MeasuredObj
     *                  被测对象：
     *                  类中包含被测对象名、本体信息、上一对象指针和下一对象指针
     *  @author   plato
     *  @version  2.00 2017-11-22 plato
     *                 note:done it
     */
    class MeasuredObj
    {

    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   MeasuredObj: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        MeasuredObj();

        /*
        *  @brief   ~MeasuredObj: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~MeasuredObj();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        std::string name() { return this->m_name; }
        void setName( std::string name ) { this->m_name = name; }

        SDK::Rectangle& body() { return this->m_body; }
        void setBody( SDK::Rectangle body ) { this->m_body = body; }

        MeasuredObj *pNextObj() { return this->m_pNextObj; }
        void setPNextObj( MeasuredObj *pNextObj ) { this->m_pNextObj = pNextObj; }

        MeasuredObj *pPreObj() { return this->m_pPreObj; }
        void setpPreObj( MeasuredObj *pPreObj ) { this->m_pPreObj = pPreObj; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;         // 被测对象名
        SDK::Rectangle m_body;      // 本体信息
        MeasuredObj *m_pNextObj;    // 下一对象指针
        MeasuredObj *m_pPreObj;     // 上一对象指针
    };

}//End of namespace Job

#endif // MEASUREDOBJ_HPP
