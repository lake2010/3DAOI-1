#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <QSettings>

namespace App
{
    // 枚举声明主题颜色
    enum class Theme
    {
        BLACK,  // 黑色
        WHITE   // 白色
    };

    // 枚举声明语言种类
    enum class Lang
    {
        CN,   // 中文
        EN    // 英文
    };

    // 枚举声明轨道模式
    enum class LaneMode
    {
        DUAL_LANE,   // 双轨
        SIMULATOR,   // 模拟器
        SINGLE_LANE  // 单轨
    };

    // 枚举声明机器类型
    enum class MachineType
    {
        AOI,    // 自动光学检测
        SPI     // 锡膏印刷检测
    };

    /**
     *  @brief    AppSetting
     *                  应用设置：
     *                  1.包含写入、读取、加载配置文件功能
     *                  2.包含的字段：主题、语言种类、轨道模式、
     *                              机器类型、公司名称、程式目录路径
     *                  3.该配置文件为功能相关的非重要配置，不影响程序启动
     *  @author   plato
     *  @version  2.00 2017-12-03 plato
     *                 note:create it
     */
    class AppSetting
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   AppSetting: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        AppSetting();

        /*
        *  @brief   ~AppSetting: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~AppSetting();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   writeAppSetting: 写入配置文件
        *  @param   path: 待写入的文件路径
        *  @return  N/A
        */
        void writeAppSetting( const QString& path );

        /*
        *  @brief   readAppSetting: 读取配置文件
        *  @param   path: 待读取的文件路径
        *  @return  N/A
        */
        void readAppSetting( const QString& path );

        /*
        *  @brief   load: 加载配置文件
        *  @param   path: 待加载的文件路径
        *  @return  N/A
        */
        void load( const QString& path );

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        /*
        *  @brief   jobFolderPath: 程式目录路径
        *  @param   N/A
        *  @return  传入的程式目录路径
        */
        QString jobFolderPath()
        {
            return this->m_jobFolderPath;
        }

        /*
        *  @brief   setJobFolderPath: 设置程式目录路径
        *  @param   jobFolderPath: 传入的程式目录路径
        *  @return  N/A
        */
        void setJobFolderPath( QString jobFolderPath )
        {
            this->m_jobFolderPath = jobFolderPath;
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        Theme m_theme;              // 主题
        Lang m_lang;                // 语言种类
        LaneMode m_laneMode;        // 轨道模式
        MachineType m_machineType;  // 机器类型
        QString m_companyName;      // 公司名称
        QString m_jobFolderPath;    // 程式文件夹路径
    };

}//End of namespace App

#endif // APPSETTING_HPP
