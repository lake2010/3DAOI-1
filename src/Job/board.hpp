#ifndef BOARD_HPP
#define BOARD_HPP

#include <QDomDocument>

#include "measuredobjlist.hpp"

namespace Job
{
    /**
     *  @brief    Board
     *                  基板：
     *                  1.类中包含基板名称、基板的长宽、基板的原点位置、被测对象列表
     *                  2.实现将基板上所有信息写入xml文件的功能
     *  @author   plato
     *  @version  1.00 2017-11-28 plato
     *                 note:create it
     */
    class Board
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   Board: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        Board();

        /*
        *  @brief   ~Board: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~Board();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   writeToXml: 基板信息写入xml文件
        *  @param   job: 创建的Job文档
        *           root: 根节点
        *  @return  N/A
        */
        void writeToXml( QDomDocument& job, QDomElement& root );

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        /*
        *  @brief   name: 基板名称
        *  @param   N/A
        *  @return  传入的基板名称
        */
        std::string name()
        {
            return this->m_name;
        }

        /*
        *  @brief   setName: 设置基板名称
        *  @param   name: 传入的基板名称
        *  @return  N/A
        */
        void setName( std::string name )
        {
            this->m_name = name;
        }

        /*
        *  @brief   sizeX: X方向长度
        *  @param   N/A
        *  @return  传入的X方向长度
        */
        double sizeX()
        {
            return this->m_sizeX;
        }

        /*
        *  @brief   setSizeX: 设置X方向长度
        *  @param   sizeX: 传入的X方向长度
        *  @return  N/A
        */
        void setSizeX( double sizeX )
        {
            this->m_sizeX = sizeX;
        }

        /*
        *  @brief   sizeY: Y方向长度
        *  @param   N/A
        *  @return  传入的Y方向长度
        */
        double sizeY()
        {
            return this->m_sizeY;
        }

        /*
        *  @brief   setSizeY: 设置Y方向长度
        *  @param   sizeY: 传入的Y方向长度
        *  @return  N/A
        */
        void setSizeY( double sizeY )
        {
            this->m_sizeY = sizeY;
        }

        /*
        *  @brief   originalX: 原点X坐标
        *  @param   N/A
        *  @return  传入的原点X坐标
        */
        double originalX()
        {
            return this->m_originalX;
        }

        /*
        *  @brief   setOriginalX: 设置原点X坐标
        *  @param   originalX: 传入的原点X坐标
        *  @return  N/A
        */
        void setOriginalX( double originalX )
        {
            this->m_originalX = originalX;
        }

        /*
        *  @brief   originalY: 原点Y坐标
        *  @param   N/A
        *  @return  传入的原点Y坐标
        */
        double originalY()
        {
            return this->m_originalY;
        }

        /*
        *  @brief   setOriginalY: 设置原点Y坐标
        *  @param   originalY: 传入的原点Y坐标
        *  @return  N/A
        */
        void setOriginalY( double originalY )
        {
            this->m_originalY = originalY;
        }

        /*
        *  @brief   measureObjs: 被测对象集
        *  @param   N/A
        *  @return  传入的被测对象集
        */
        MeasuredObjList& measureObjs()
        {
            return this->m_measureObjs;
        }

        /*
        *  @brief   setMeasureObjs: 设置被测对象集
        *  @param   measureObjs: 传入的被测对象集
        *  @return  N/A
        */
        void setMeasureObjs( MeasuredObjList measureObjs )
        {
            this->m_measureObjs = measureObjs;
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;             // 基板名称
        double m_sizeX;                 // 基板的X方向长度
        double m_sizeY;                 // 基板的Y方向长度
        double m_originalX;             // 基板的原点X坐标
        double m_originalY;             // 基板的原点Y坐标
        MeasuredObjList m_measureObjs;  // 被测对象集信息
    };

}//End of namespace Job

#endif // BOARD_HPP
