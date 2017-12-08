#include <iostream>

#include <QFile>

#include "capturesetting.hpp"
#include "SDK/customexception.hpp"

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

    QSettings configFile( path, QSettings::IniFormat );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 读取图像配置文件中的图像面阵宽度，若数据不正常，抛出异常，提示错误信息
    int imgWidth = configFile.value( "Image/ImgWidth" ).toInt();
    if( imgWidth <= 0 )
    {
        THROW_EXCEPTION( "读取Image/ImgWidth失败!" );
    }
    else
    {
        this->m_imgWidth = imgWidth;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2 读取图像配置文件中的图像面阵高度，若数据不正常，抛出异常，提示错误信息
    int imgHeight = configFile.value( "Image/ImgHeight" ).toInt();
    if( imgHeight <= 0 )
    {
        THROW_EXCEPTION( "读取Image/ImgHeight失败!" );
    }
    else
    {
        this->m_imgHeight = imgHeight;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3 读取图像配置文件中的图像位数，若数据不正常，抛出异常，提示错误信息
    QString imgBits = configFile.value( "Image/ImgBits" ).toString();
    if( imgBits != "BIT_8" && imgBits != "BIT_16" )
    {
        THROW_EXCEPTION( "读取Image/ImgBits失败!" );
    }
    else if( imgBits == "BIT_8" )
    {
        this->m_imgBits = ImgBits::BIT_8;
    }
    else
    {
        this->m_imgBits = ImgBits::BIT_16;
    }
    cout << "加载CaptureSetting.ini成功" << endl;
}

void CaptureSetting::load( const QString& path )
{
    try
    {
        //1 如果文件不存在，直接抛出异常，提示错误信息;
        //2 如果文件存在，则读取文件，检查功能配置是否正常
        if( !QFile::exists( path ) )
        {
            THROW_EXCEPTION( "CaptureSetting文件读取失败！" );
        }        
        else
        {           
            readCaptureSetting( path );
        }
    }
    catch( const CustomException& ex )
    {        
        cout << "检测功能不可用，请重新配置！" << endl;
        THROW_EXCEPTION( ex.what() );
    }
}
