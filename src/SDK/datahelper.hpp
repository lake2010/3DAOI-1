#ifndef DATAHELPER_HPP
#define DATAHELPER_HPP

#include <iostream>

namespace SDK
{
    /**
     *  @brief    DataHelper
     *                  数据助手：
     *                  1.生成随机数
     *                  2.生成当前系统时间
     *  @author   plato
     *  @version  2.00 2017-11-29 plato
     *                 note:create it
     */
    class DataHelper
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   DataHelper: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        DataHelper();

        /*
        *  @brief   ~DataHelper: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~DataHelper();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   generateRandomNum: 生成随机数
        *  @param   N/A
        *  @return  生成的随机数
        */
        static double generateRandomNum();

        /*
        *  @brief   generateTime: 生成时间
        *  @param   N/A
        *  @return  生成的时间
        */
        static std::string generateTime();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    };

}//End of namespace SDK


#endif // DATAHELPER_HPP
