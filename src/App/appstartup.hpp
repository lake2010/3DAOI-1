#ifndef APPSTARTUP_HPP
#define APPSTARTUP_HPP

#include "Job/inspectiondata.hpp"
#include "appsetting.hpp"
#include "capturesetting.hpp"
#include "datagenerator.hpp"

namespace App
{
    /**
     *  @brief    AppStartup
     *                  软件启动：
     *                  1.加载非重要配置文件AppSetting.ini
     *                  2.加载重要配置文件CaptureSetting.ini
     *                  3.扫描程式文件夹
     *                  4.若程式文件夹无文件，则自动生成程式
     *                  5.若程式文件夹有文件，则选择程式并加载
     *                  6.加载成功后打印程式的检测信息到屏幕，并写入xml文件
     *  @author   plato
     *  @version  1.00 2017-12-05 plato
     *                 note:create it
     */
    class AppStartup
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   AppStartup: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        AppStartup();

        /*
        *  @brief   ~AppStartup: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~AppStartup();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //member functions

        /*
        *  @brief   loadAppSetting: 加载软件配置
        *  @param   path: 待加载的文件路径
        *  @return  N/A
        */
        void loadAppSetting( const QString& path );

        /*
        *  @brief   loadCaptureSetting: 加载图像配置
        *  @param   path: 待加载的文件路径
        *  @return  N/A
        */
        void loadCaptureSetting( const QString& path );

        /*
        *  @brief   readJobFolder: 读取程式文件夹
        *  @param   N/A
        *  @return  N/A
        */
        void readJobFolder();

        /*
        *  @brief   generateJob: 生成程式
        *  @param   path:   生成的程式路径
        *  @return  N/A
        */
        void generateJob( QString path,
                          Job::InspectionData& inspectionData );

//        /*
//        *  @brief   loadInspectionData: 加载检测数据
//        *  @param   path: 待加载的文件路径
//        *  @return  N/A
//        */
//        void loadInspectionData( const QString& path );

        /*
        *  @brief   writeToXml: 检测数据写入xml文件
        *  @param   fileName: 待写入的文件路径
        *           inspectionData: 传入的检测数据对象
        *  @return  N/A
        */
        void writeToXml( QString fileName,
                         Job::InspectionData& inspectionData );

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        /*
        *  @brief   appSettingPath: 软件配置文件路径
        *  @param   N/A
        *  @return  传入的软件配置文件路径
        */
        QString appSettingPath()
        {
            return this->m_appSettingPath;
        }

        /*
        *  @brief   setAppSettingPath: 设置软件配置文件路径
        *  @param   appSettingPath: 传入的软件配置文件路径
        *  @return  N/A
        */
        void setAppSettingPath( QString appSettingPath )
        {
            this->m_appSettingPath = appSettingPath;
        }

        /*
        *  @brief   captureSettingPath: 图像配置文件路径
        *  @param   N/A
        *  @return  传入的图像配置文件路径
        */
        QString captureSettingPath()
        {
            return this->m_captureSettingPath;
        }

        /*
        *  @brief   setCaptureSettingPath: 设置图像配置文件路径
        *  @param   captureSettingPath: 传入的图像配置文件路径
        *  @return  N/A
        */
        void setCaptureSettingPath( QString captureSettingPath )
        {
            this->m_captureSettingPath = captureSettingPath;
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        AppSetting m_appSetting;          // 软件配置
        CaptureSetting m_captureSetting;  // 图像配置
        QString m_appSettingPath;         // 软件配置文件路径
        QString m_captureSettingPath;     // 图像配置文件路径
    };

}//End of namespace App

#endif // APPSTARTUP_HPP
