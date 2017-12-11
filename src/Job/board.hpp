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
     *  @version  2.00 2017-11-28 plato
     *                 note:done it
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

        std::string name() { return this->m_name; }
        void setName( std::string name ) { this->m_name = name; }

        double sizeX() { return this->m_sizeX; }
        void setSizeX( double sizeX ) { this->m_sizeX = sizeX; }

        double sizeY() { return this->m_sizeY; }
        void setSizeY( double sizeY ) { this->m_sizeY = sizeY; }

        double originX() { return this->m_originX; }
        void setOriginX( double originX ) { this->m_originX = originX; }

        double originY() { return this->m_originY; }
        void setOriginY( double originY ) { this->m_originY = originY; }

        MeasuredObjList& measureObjs() { return this->m_measureObjs; }
        void setMeasureObjs( MeasuredObjList measureObjs ) { this->m_measureObjs = measureObjs; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_name;             // 基板名称
        double m_sizeX;                 // 基板的X方向长度
        double m_sizeY;                 // 基板的Y方向长度
        double m_originX;             // 基板的原点X坐标
        double m_originY;             // 基板的原点Y坐标
        MeasuredObjList m_measureObjs;  // 被测对象集信息
    };

}//End of namespace Job

#endif // BOARD_HPP
