#ifndef DATAGENERATOR_HPP
#define DATAGENERATOR_HPP

#include "SDK/datahelper.hpp"
#include "Job/inspectiondata.hpp"

//1 宏定义对象个数为50，若程式目录下没有文件，则默认生成50个被测对象
//2 宏定义chip类型对象个数为所有对象的40%
//3 宏定义ic类型对象个数为所有对象的60%
#define OBJ_CNT 50
#define CHIP_CNT (OBJ_CNT*0.4)
#define IC_CNT (OBJ_CNT*0.6)

namespace App
{
    /**
     *  @brief    DataGenerator
     *                  数据生成器：
     *                  1.软件的版本信息
     *                  2.上次程式的编辑时间
     *                  3.基板的名称、大小、原点
     *                  4.所有被测对象的名称、坐标位置、大小、角度
     *  @author   plato
     *  @version  2.00 2017-11-29 plato
     *                 note:create it
     */
    class DataGenerator
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   DataGenerator: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        DataGenerator();

        /*
        *  @brief   ~DataGenerator: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~DataGenerator();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   generateData: 生成数据
        *  @param   inspectionData: 传入的检测数据对象
        *           obj[]: 传入的被测对象数组
        *  @return  N/A
        */
        void generateData( Job::InspectionData& inspectionData,
                           Job::MeasuredObj obj[] );

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    };

}//End of namespace App

#endif // DATAGENERATOR_HPP
