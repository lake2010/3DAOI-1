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
     *  @version  1.00 2017-12-02 plato
     *                 note:create it
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

        /*
        *  @brief   version: 检测程式的版本
        *  @param   N/A
        *  @return  传入的版本
        */
        std::string version()
        {
            return this->m_version;
        }

        /*
        *  @brief   setVersion: 设置检测程式的版本
        *  @param   version: 传入的版本
        *  @return  N/A
        */
        void setVersion( std::string version )
        {
            this->m_version = version;
        }

        /*
        *  @brief   lastEditingTime: 上一次编辑时间
        *  @param   N/A
        *  @return  传入的上一次编辑时间
        */
        std::string lastEditingTime()
        {
            return this->m_lastEditingTime;
        }

        /*
        *  @brief   setLastEditingTime: 设置上一次编辑时间
        *  @param   lastEditingTime: 传入的上一次编辑时间
        *  @return  N/A
        */
        void setLastEditingTime( std::string lastEditingTime )
        {
            this->m_lastEditingTime = lastEditingTime;
        }

        /*
        *  @brief   board: 基板信息
        *  @param   N/A
        *  @return  传入的基板信息
        */
        Board& board()
        {
            return this->m_board;
        }

        /*
        *  @brief   setBoard: 设置基板信息
        *  @param   board: 传入的基板信息
        *  @return  N/A
        */
        void setBoard( Board board )
        {
            this->m_board = board;
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_version;          // 检测程式的版本
        std::string m_lastEditingTime;  // 上一次编辑时间
        Board m_board;                  // 基板信息
    };

}//End of namespace Job

#endif // INSPECTIONDATA_HPP
