#ifndef MEASUREDOBJ_HPP
#define MEASUREDOBJ_HPP

#include <iostream>

#include "SDK/rectangle.hpp"

namespace Job
{
    /**
     *  @brief    MeasuredObj
     *
     *  @author   plato
     *  @version  1.00 2017-11-22 plato
     *                note:create it
     */
    class MeasuredObj
    {

    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   MeasuredObj:  构造函数
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
        *  @brief   name:    被测目标名
        *  @param   N/A
        *  @return  传入的被测目标名
        */
        std::string name()
        {
            return this->m_name;
        }

        /*
        *  @brief   setName: 设置被测目标名
        *  @param   name:    传入的被测目标名
        *  @return  N/A
        */
        void setName( std::string name )
        {
            this->m_name = name;
        }

        /*
        *  @brief   body:    矩形的信息
        *                    信息中包含X、Y坐标、宽度、高度、角度
        *  @param   N/A
        *  @return  传入的矩形信息
        */
        SDK::Rectangle body()
        {
            return this->m_body;
        }

        /*
        *  @brief   setBody: 设置矩形的信息
        *  @param   body:    传入的矩形信息
        *  @return  N/A
        */
        void setBody( SDK::Rectangle body )
        {
            this->m_body = body;
        }

        /*
        *  @brief   pNextMeasuredObj:    后继节点指针
        *  @param   N/A
        *  @return  传入的后继节点指针
        */
        MeasuredObj* pNextMeasuredObj()
        {
            return this->m_pNextMeasuredObj;
        }

        /*
        *  @brief   setpNextMeasuredObj: 设置后继节点指针
        *  @param   pNextMeasureObj:     传入的后继节点指针
        *  @return  N/A
        */
        void setpNextMeasuredObj( MeasuredObj* pNextMeasureObj )
        {
            this->m_pNextMeasuredObj = pNextMeasureObj;
        }

        /*
        *  @brief   pPreMeasuredObj:    前继节点指针
        *  @param   N/A
        *  @return  传入的前继节点指针
        */
        MeasuredObj* pPreMeasuredObj()
        {
            return this->m_pPreMeasuredObj;
        }

        /*
        *  @brief   setpPreMeasuredObj: 设置前继节点指针
        *  @param   pPreMeasureObj:     传入的前继节点指针
        *  @return  N/A
        */
        void setpPreMeasuredObj( MeasuredObj* pPreMeasureObj )
        {
            this->m_pPreMeasuredObj = pPreMeasureObj;
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;                 // 被测目标名
        SDK::Rectangle m_body;              // 矩形的信息
        MeasuredObj* m_pNextMeasuredObj;    // 后继节点指针
        MeasuredObj* m_pPreMeasuredObj;     // 前继节点指针
    };

}//End of namespace Job

#endif // MEASUREDOBJ_HPP
