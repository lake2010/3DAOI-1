#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <QSettings>

namespace App
{
    // 枚举声明主题颜色
    enum class THEME
    {
        BLACK,  // 黑色
        WHITE   // 白色
    };

    // 枚举声明语言种类
    enum class LANG
    {
        CN,   // 中文
        EN    // 英文
    };

    // 枚举声明轨道模式
    enum class LANE_MODE
    {
        DUALLANE,   // 双轨
        SIMULATOR,  // 模拟器
        SINGLELANE  // 单轨
    };

    // 枚举声明机器类型
    enum class MACHINE_TYPE
    {
        AOI,    // 自动光学检测
        SPI     // 锡膏印刷检测
    };

    /**
     *  @brief    AppSetting
     *
     *  @author   plato
     *  @version  1.00 2017-12-03 plato
     *                 note:create it
     */
    class AppSetting
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   AppSetting:  构造函数
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
        *  @brief   writeAppSetting:  写入配置文件
        *  @param   path:   待写入的文件路径
        *  @return  N/A
        */
        void writeAppSetting( const QString& path );

        /*
        *  @brief   readAppSetting:  读取配置文件
        *  @param   path:   待读取的文件路径
        *  @return  N/A
        */
        void readAppSetting( const QString& path );

        /*
        *  @brief   load:   加载配置文件
        *  @param   path:   待加载的文件路径
        *  @return  N/A
        */
        void load( const QString& path );

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        THEME m_theme;                  // 主题
        LANG m_lang;                    // 语言种类
        LANE_MODE m_laneMode;           // 轨道模式
        MACHINE_TYPE m_machineType;     // 机器类型
        std::string m_companyName;      // 公司名称
        std::string m_jobFolderPath;    // 程式文件夹路径
    };

}//End of namespace App

#endif // APPSETTING_HPP