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
     *  @version  1.00 2017-11-22 plato
     *                 note:create it
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

        /*
        *  @brief   name: 被测对象名
        *  @param   N/A
        *  @return  传入的被测对象名
        */
        std::string name()
        {
            return this->m_name;
        }

        /*
        *  @brief   setName: 设置被测对象名
        *  @param   name: 传入的被测对象名
        *  @return  N/A
        */
        void setName( std::string name )
        {
            this->m_name = name;
        }

        /*
        *  @brief   body: 本体信息
        *                 本体中包含X、Y坐标、宽度、高度、角度信息
        *  @param   N/A
        *  @return  传入的本体信息
        */
        SDK::Rectangle& body()
        {
            return this->m_body;
        }

        /*
        *  @brief   setBody: 设置本体的信息
        *  @param   body: 传入的本体信息
        *  @return  N/A
        */
        void setBody( SDK::Rectangle body )
        {
            this->m_body = body;
        }

        /*
        *  @brief   pNextObj: 下一对象指针
        *  @param   N/A
        *  @return  传入的下一对象指针
        */
        MeasuredObj *pNextObj()
        {
            return this->m_pNextObj;
        }

        /*
        *  @brief   setpNextObj: 设置下一对象指针
        *  @param   pNextObj: 传入的下一对象指针
        *  @return  N/A
        */
        void setPNextObj( MeasuredObj *pNextObj )
        {
            this->m_pNextObj = pNextObj;
        }

        /*
        *  @brief   pPreObj: 上一对象指针
        *  @param   N/A
        *  @return  传入的上一对象指针
        */
        MeasuredObj *pPreObj()
        {
            return this->m_pPreObj;
        }

        /*
        *  @brief   setpPreObj: 设置上一对象指针
        *  @param   pPreObj: 传入的上一对象指针
        *  @return  N/A
        */
        void setpPreObj( MeasuredObj *pPreObj )
        {
            this->m_pPreObj = pPreObj;
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;         // 被测对象名
        SDK::Rectangle m_body;      // 本体信息
        MeasuredObj *m_pNextObj;    // 下一对象指针
        MeasuredObj *m_pPreObj;     // 上一对象指针
    };

}//End of namespace Job

#endif // MEASUREDOBJ_HPP
