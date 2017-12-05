#include <iostream>

#include <QFile>

#include "appsetting.hpp"
#include "SDK/customexception.hpp"

using namespace App;
using namespace SDK;

AppSetting::AppSetting()
{
    // 初始化成员变量
    this->m_theme = THEME::BLACK;
    this->m_lang = LANG::CN;
    this->m_laneMode = LANE_MODE::DUALLANE;
    this->m_machineType = MACHINE_TYPE::AOI;
    this->m_companyName = "SciJet";
    this->m_jobFolderPath = "../data";
}

AppSetting::~AppSetting()
{

}

void AppSetting::writeAppSetting( const QString &path )
{
    // 创建默认配置文件，设置默认值
    QSettings configFile( path, QSettings::IniFormat );

    configFile.setValue( "THEME", "BLACK" );
    configFile.setValue( "LANG", "CN" );
    configFile.setValue( "LANE_MODE", "DUALLANE" );
    configFile.setValue( "MACHINE_TYPE", "AOI" );
    configFile.setValue( "COMPANY_NAME", "SciJet" );
}

void AppSetting::readAppSetting( const QString &path )
{
    QSettings configFile( path, QSettings::IniFormat );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 读取配置文件中主题配置，若数据不正常，则写入默认值
    QString theme = configFile.value( "THEME" ).toString();
    if( theme != "BLACK" && theme != "WHITE" )
    {
        configFile.setValue( "THEME", "BLACK" );
    }
    else if( theme == "BLACK" )
    {
        this->m_theme = THEME::BLACK;
    }
    else
    {
        this->m_theme = THEME::WHITE;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2 读取配置文件中语言配置，若数据不正常，则写入默认值
    QString lang = configFile.value( "LANG" ).toString();
    if( lang != "CN" && lang != "EN" )
    {
        configFile.setValue( "LANG", "CN" );
    }
    else if( lang == "CN" )
    {
        this->m_lang = LANG::CN;
    }
    else
    {
        this->m_lang = LANG::EN;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3 读取配置文件中轨道模式配置，若数据不正常，则写入默认值
    QString laneMode = configFile.value( "LANE_MODE" ).toString();
    if( laneMode != "DUALLANE" &&
        laneMode != "SIMULATOR" &&
        laneMode != "SINGLELANE" )
    {
        configFile.setValue( "LANE_MODE", "DUALLANE" );
    }
    else if( laneMode == "DUALLANE" )
    {
        this->m_laneMode = LANE_MODE::DUALLANE;
    }
    else if ( laneMode == "SIMULATOR" )
    {
        this->m_laneMode = LANE_MODE::SIMULATOR;
    }
    else
    {
        this->m_laneMode = LANE_MODE::SINGLELANE;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //4 读取配置文件中机器类型配置，若数据不正常，则写入默认值
    QString machineType = configFile.value( "MACHINE_TYPE" ).toString();
    if( machineType != "AOI" && machineType != "SPI" )
    {
        configFile.setValue( "MACHINE_TYPE", "AOI" );
    }
    else if( machineType == "AOI" )
    {
        this->m_machineType = MACHINE_TYPE::AOI;
    }
    else
    {
        this->m_machineType = MACHINE_TYPE::SPI;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //5 读取配置文件中公司名称配置，若数据不正常，则写入默认值
    QString companyName = configFile.value( "COMPANY_NAME" ).toString();
    if( companyName != "SciJet" && companyName != "Sung" )
    {
        configFile.setValue( "COMPANY_NAME", "SciJet" );
    }
    else
    {
        this->m_companyName = companyName.toStdString();
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //6 读取配置文件中程式目录配置，若数据不正常，则写入默认值
    QString jobFolderPath = configFile.value( "JobFolderPath" ).toString();
    if( jobFolderPath != "../data" )
    {
        configFile.setValue( "JobFolderPath", "../data" );
    }
    else
    {
        this->m_jobFolderPath = jobFolderPath.toStdString();
    }
}

void AppSetting::load( const QString &path )
{
    // 如果文件不存在，创建默认配置文件，写入默认配置
    if( !QFile::exists( path ) )
    {
        writeAppSetting( path );
    }
    // 如果文件存在，则读取配置文件
    else
    {
        readAppSetting( path );
    }
}