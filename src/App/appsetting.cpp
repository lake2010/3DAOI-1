#include <iostream>

#include <QFile>

#include "appsetting.hpp"

using namespace std;
using namespace App;

AppSetting::AppSetting()
{
    // 初始化成员变量
    this->m_theme = Theme::BLACK;
    this->m_lang = Lang::CN;
    this->m_laneMode = LaneMode::DUAL_LANE;
    this->m_machineType = MachineType::AOI;
    this->m_companyName = "";
    this->m_jobFolderPath = "";
}

AppSetting::~AppSetting()
{

}

void AppSetting::writeAppSetting( const QString& path )
{
    // 创建默认配置文件，设置默认值
    QSettings configFile( path, QSettings::IniFormat );

    configFile.setValue( "Theme", "BLACK" );
    configFile.setValue( "Lang", "CN" );
    configFile.setValue( "LaneMode", "DUALLANE" );
    configFile.setValue( "MachineType", "AOI" );
    configFile.setValue( "CompanyName", "SciJet" );
    configFile.setValue( "JobFolderPath", "../data" );

    cout << "加载AppSetting.ini成功" << endl;
}

void AppSetting::readAppSetting( const QString& path )
{
    QSettings configFile( path, QSettings::IniFormat );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 读取配置文件中主题配置，若数据不正常，则写入默认值
    QString theme = configFile.value( "Theme" ).toString();
    if( theme != "BLACK" && theme != "WHITE" )
    {
        configFile.setValue( "Theme", "BLACK" );
    }
    else if( theme == "BLACK" )
    {
        this->m_theme = Theme::BLACK;
    }
    else
    {
        this->m_theme = Theme::WHITE;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2 读取配置文件中语言配置，若数据不正常，则写入默认值
    QString lang = configFile.value( "Lang" ).toString();
    if( lang != "CN" && lang != "EN" )
    {
        configFile.setValue( "Lang", "CN" );
    }
    else if( lang == "CN" )
    {
        this->m_lang = Lang::CN;
    }
    else
    {
        this->m_lang = Lang::EN;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3 读取配置文件中轨道模式配置，若数据不正常，则写入默认值
    QString laneMode = configFile.value( "LaneMode" ).toString();
    if( laneMode != "DUALLANE" &&
        laneMode != "SIMULATOR" &&
        laneMode != "SINGLELANE" )
    {
        configFile.setValue( "LaneMode", "DUALLANE" );
    }
    else if( laneMode == "DUALLANE" )
    {
        this->m_laneMode = LaneMode::DUAL_LANE;
    }
    else if( laneMode == "SIMULATOR" )
    {
        this->m_laneMode = LaneMode::SIMULATOR;
    }
    else
    {
        this->m_laneMode = LaneMode::SINGLE_LANE;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //4 读取配置文件中机器类型配置，若数据不正常，则写入默认值
    QString machineType = configFile.value( "MachineType" ).toString();
    if( machineType != "AOI" && machineType != "SPI" )
    {
        configFile.setValue( "MachineType", "AOI" );
    }
    else if( machineType == "AOI" )
    {
        this->m_machineType = MachineType::AOI;
    }
    else
    {
        this->m_machineType = MachineType::SPI;
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //5 读取配置文件中公司名称配置，若数据不正常，则写入默认值
    QString companyName = configFile.value( "CompanyName" ).toString();
    if( companyName != "SciJet" && companyName != "Sung" )
    {
        configFile.setValue( "CompanyName", "SciJet" );
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

    cout << "加载AppSetting.ini成功" << endl;
}

void AppSetting::load( const QString& path )
{
    //1 如果文件不存在，创建默认配置文件，写入默认配置
    //2 如果文件存在，则读取配置文件
    if( !QFile::exists( path ) )
    {
        writeAppSetting( path );
    }    
    else
    {        
        readAppSetting( path );
    }
}
