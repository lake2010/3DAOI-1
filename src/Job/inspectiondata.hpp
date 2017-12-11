#ifndef INSPECTIONDATA_HPP
#define INSPECTIONDATA_HPP

#include "board.hpp"

namespace Job
{
    /**
     *  @brief    InspectionData
     *                  检测数据：
     *                  1.类中包含版本信息、上次编辑时间、基板信息
     *                  2.实现将检测数据写入xml文件的功能
     *  @author   plato
     *  @version  2.00 2017-12-02 plato
     *                 note:done it
     */
    class InspectionData
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   InspectionData: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        InspectionData();

        /*
        *  @brief   ~InspectionData: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~InspectionData();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   writeToXml: 检测数据写入xml文件
        *  @param   job: 创建的Job文档
        *  @return  N/A
        */
        void writeToXml( QDomDocument& job );

        /*
        *  @brief   print: 打印检测数据
        *  @param   N/A
        *  @return  N/A
        */
        void print();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        std::string version() { return this->m_version; }
        void setVersion( std::string version ) { this->m_version = version; }

        std::string lastEditingTime() { return this->m_lastEditingTime; }
        void setLastEditingTime( std::string lastEditingTime ) { this->m_lastEditingTime = lastEditingTime; }

        Board& board() { return this->m_board; }
        void setBoard( Board board ) { this->m_board = board; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_version;          // 检测程式的版本
        std::string m_lastEditingTime;  // 上一次编辑时间
        Board m_board;                  // 基板信息
    };

}//End of namespace Job

#endif // INSPECTIONDATA_HPP
