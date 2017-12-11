#include "capturesetting.hpp"

using namespace std;
using namespace App;
using namespace SDK;

CaptureSetting::CaptureSetting()
{
    // 成员变量初始化
    this->m_imgWidth = 0;
    this->m_imgHeight = 0;
    this->m_imgBits = ImgBits::BIT_8;
}

CaptureSetting::~CaptureSetting()
{

}

void CaptureSetting::readCaptureSetting( const QString& path )
{
    try
    {
        QSettings configFile( path, QSettings::IniFormat );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 读取图像配置文件中的图像面阵宽度，若数据不正常，抛出异常，提示错误信息
        int imgWidth = configFile.value( "Image/ImgWidth" ).toInt();
        if( imgWidth > 0 )
        {
            this->m_imgWidth = imgWidth;
        }
        else
        {
            THROW_EXCEPTION( "读取Image/ImgWidth失败!" );
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 读取图像配置文件中的图像面阵高度，若数据不正常，抛出异常，提示错误信息
        int imgHeight = configFile.value( "Image/ImgHeight" ).toInt();
        if( imgHeight > 0 )
        {
            this->m_imgHeight = imgHeight;
        }
        else
        {
            THROW_EXCEPTION( "读取Image/ImgHeight失败!" );
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 读取图像配置文件中的图像位数，若数据不正常，抛出异常，提示错误信息
        QString imgBits = configFile.value( "Image/ImgBits" ).toString();
        if( "BIT_8" == imgBits )
        {
            this->m_imgBits = ImgBits::BIT_8;
        }
        else if( "BIT_16" == imgBits )
        {
            this->m_imgBits = ImgBits::BIT_16;
        }
        else
        {
            THROW_EXCEPTION( "读取Image/ImgBits失败!" );
        }
        cout << "加载CaptureSetting.ini成功" << endl;
    }
    CATCH_AND_RETHROW_EXCEPTION("图像配置有误！");
}

void CaptureSetting::load( const QString& path )
{
    try
    {               
        if( !QFile::exists( path ) ) // 如果文件不存在，直接抛出异常，提示错误信息
        {
            THROW_EXCEPTION( "CaptureSetting文件读取失败！" );
        }        
        else // 如果文件存在，则读取文件，检查功能配置是否正常
        {           
            readCaptureSetting( path );
        }
    }
    CATCH_AND_RETHROW_EXCEPTION("检测功能不可用，请重新配置！");
}
