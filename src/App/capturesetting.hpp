#ifndef CAPTURESETTING_HPP
#define CAPTURESETTING_HPP

#include <QSettings>

namespace App
{
    // 枚举声明图像位数
    enum class ImgBits
    {
        BIT_8,   // 8位
        BIT_16   // 16位
    };

    /**
     *  @brief    CaptureSetting
     *            图像配置：
     *            1.包含读取、加载配置文件功能
     *            2.包含的字段：图像的面阵宽度和高度、图像位数
     *            3.该配置文件为功能相关的重要配置，若配置异常，直接退出程序
     *  @author   plato
     *  @version  1.00 2017-12-03 plato
     *                 note:create it
     */
    class CaptureSetting
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   CaptureSetting:  构造函数
        *  @param   N/A
        *  @return  N/A
        */
        CaptureSetting();

        /*
        *  @brief   ~CaptureSetting: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~CaptureSetting();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   readCaptureSetting:  读取图像配置
        *  @param   path:   待读取的文件路径
        *  @return  N/A
        */
        void readCaptureSetting( const QString& path );

        /*
        *  @brief   load:   加载配置文件
        *  @param   path:   待加载的文件路径
        *  @return  N/A
        */
        void load( const QString& path );

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        int m_imgWidth;         // 图像面阵宽度
        int m_imgHeight;        // 图像面阵高度
        ImgBits m_imgBits;      // 图像位数
    };

}//End of namespace App

#endif // CAPTURESETTING_HPP
