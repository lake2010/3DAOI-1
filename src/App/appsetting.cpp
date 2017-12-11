#include "appsetting.hpp"

using namespace std;
using namespace App;

AppSetting::AppSetting()
{
    // 成员变量初始化
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
    configFile.setValue( "LaneMode", "DUAL_LANE" );
    configFile.setValue( "MachineType", "AOI" );
    configFile.setValue( "CompanyName", "SciJet" );
    configFile.setValue( "JobFolderPath", "../data/" );   
}

void AppSetting::readAppSetting( const QString& path )
{
    QSettings configFile( path, QSettings::IniFormat );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 读取配置文件中主题配置，若数据不正常，则写入默认值
    QString theme = configFile.value( "Theme" ).toString();
    if( "BLACK" == theme  )
    {
        this->m_theme = Theme::BLACK;
    }
    else if( "WHITE" == theme )
    {
        this->m_theme = Theme::WHITE;
    }
    else
    {
        configFile.setValue( "Theme", "BLACK" );
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2 读取配置文件中语言配置，若数据不正常，则写入默认值
    QString lang = configFile.value( "Lang" ).toString();
    if( "CN" == lang )
    {
        this->m_lang = Lang::CN;
    }
    else if( "EN" == lang )
    {
        this->m_lang = Lang::EN;
    }
    else
    {
        configFile.setValue( "Lang", "CN" );
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3 读取配置文件中轨道模式配置，若数据不正常，则写入默认值
    QString laneMode = configFile.value( "LaneMode" ).toString();
    if( "DUAL_LANE" == laneMode )
    {
        this->m_laneMode = LaneMode::DUAL_LANE;
    }
    else if( "SIMULATOR" == laneMode )
    {
        this->m_laneMode = LaneMode::SIMULATOR;
    }
    else if( "SINGLE_LANE" == laneMode )
    {
        this->m_laneMode = LaneMode::SINGLE_LANE;
    }
    else
    {
        configFile.setValue( "LaneMode", "DUAL_LANE" );
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //4 读取配置文件中机器类型配置，若数据不正常，则写入默认值
    QString machineType = configFile.value( "MachineType" ).toString();
    if(  "AOI" == machineType )
    {
        this->m_machineType = MachineType::AOI;
    }
    else if( "SPI" == machineType )
    {
        this->m_machineType = MachineType::SPI;
    }
    else
    {
        configFile.setValue( "MachineType", "AOI" );
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //5 读取配置文件中公司名称配置，若数据不正常，则写入默认值
    QString companyName = configFile.value( "CompanyName" ).toString();
    if( "SciJet" == companyName || companyName == "Sung" )
    {
        this->m_companyName = companyName;
    }
    else
    {
        configFile.setValue( "CompanyName", "SciJet" );
    }

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //6 读取配置文件中程式目录配置，若数据不正常，则写入默认值
    QString jobFolderPath = configFile.value( "JobFolderPath" ).toString();
    if( "../data/" == jobFolderPath )
    {
        this->m_jobFolderPath = jobFolderPath;
    }
    else
    {
        configFile.setValue( "JobFolderPath", "../data/" );
    }

    cout << "加载AppSetting.ini成功" << endl;
}

void AppSetting::load( const QString& path )
{   
    // 判断要加载的文件是否存在
    if( !QFile::exists( path ) ) //1 如果不存在，写一个默认配置文件，然后读取
    {
        writeAppSetting( path );
        readAppSetting( path );
    }    
    else // 如果文件存在，则读取配置文件
    {        
        readAppSetting( path );
    }
}
