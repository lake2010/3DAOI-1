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
     *
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
        *  @brief   writeCaptureSetting:  写入图像配置
        *  @param   path:   待写入的文件路径
        *  @return  N/A
        */
        void writeCaptureSetting( const QString& path );

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
