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
        *           用于释放内存
        *  @param   N/A
        *  @return  N/A
        */
        ~MeasuredObj();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //访存函数

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 name
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

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 body
        /*
        *  @brief   body:    被测目标的Rectangle类型信息体
        *                    类中包含X、Y坐标、宽度、高度、角度
        *  @param   N/A
        *  @return  传入的Rectangle类型信息体
        */
        SDK::Rectangle body()
        {
            return this->m_body;
        }

        /*
        *  @brief   setBody: 设置被测目标的Rectangle类型信息体
        *  @param   body:    传入的Rectangle类型信息体
        *  @return  N/A
        */
        void setBody( SDK::Rectangle body )
        {
            this->m_body = body;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 pNextMeasuredObj
        /*
        *  @brief   pNextMeasuredObj:    指针指向下一个被测目标
        *  @param   N/A
        *  @return  传入的指针指向下一个被测目标
        */
        MeasuredObj* pNextMeasuredObj()
        {
            return this->m_pNextMeasuredObj;
        }

        /*
        *  @brief   setpNextMeasuredObj: 设置指针指向下一个被测目标
        *  @param   pNextMeasureObj:     传入的指针指向下一个被测目标
        *  @return  N/A
        */
        void setpNextMeasuredObj( MeasuredObj* pNextMeasureObj )
        {
            this->m_pNextMeasuredObj = pNextMeasureObj;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4 pPreMeasuredObj
        /*
        *  @brief   pPreMeasuredObj:    指针指向上一个被测目标
        *  @param   N/A
        *  @return  传入的指针指向上一个被测目标
        */
        MeasuredObj* pPreMeasuredObj()
        {
            return this->m_pPreMeasuredObj;
        }

        /*
        *  @brief   setpPreMeasuredObj: 设置指针指向上一个被测目标
        *  @param   pPreMeasureObj:     传入的指针指向上一个被测目标
        *  @return  N/A
        */
        void setpPreMeasuredObj( MeasuredObj* pPreMeasureObj )
        {
            this->m_pPreMeasuredObj = pPreMeasureObj;
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;                 // 被测目标名
        SDK::Rectangle m_body;              // 被测目标信息体
        MeasuredObj* m_pNextMeasuredObj;    // 指针指向下一个被测目标
        MeasuredObj* m_pPreMeasuredObj;     // 指针指向上一个被测目标
    };

}//End of namespace Job

#endif // MEASUREDOBJ_HPP
