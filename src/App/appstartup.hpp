#ifndef APPSTARTUP_HPP
#define APPSTARTUP_HPP

#include <QDir>
#include <QFile>
#include <QTextStream>

#include "DB/sqlitedb.hpp"

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
     *  @version  2.00 2017-12-05 plato
     *                 note:done it
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
        *  @brief   readJobPath: 读取程式路径
        *  @param   N/A
        *  @return  N/A
        */
        void readJobPath();

        /*
        *  @brief   generateJob: 生成程式
        *  @param   path:   生成的程式路径
        *           inspectionData: 程式所需的检测数据对象
        *  @return  N/A
        */
        void generateJob( QString path,
                          Job::InspectionData& inspectionData );

        /*
        *  @brief   loadInspectionData: 加载检测数据
        *  @param   path: 待加载的检测数据的路径
        *  @return  N/A
        */
        void loadInspectionData( QString path );

        /*
        *  @brief   writeToXml: 检测数据写入xml文件
        *  @param   path: 待写入的文件路径
        *           inspectionData: 程式所需的检测数据对象
        *  @return  N/A
        */
        void writeToXml( QString path,
                         Job::InspectionData& inspectionData );

        /*
        *  @brief   convertFromV1: 版本转换
        *  @param   sqlite: 需更新修改的数据库对象
        *  @return  N/A
        */
        void convertFromV1( SSDK::DB::SqliteDB& sqlite );

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        // 以下为配置文件相关函数
        AppSetting& appSetting() { return this->m_appSetting; }

        QString appSettingPath() { return this->m_appSettingPath; }
        void setAppSettingPath( QString appSettingPath ) { this->m_appSettingPath = appSettingPath; }

        QString captureSettingPath() { return this->m_captureSettingPath; }
        void setCaptureSettingPath( QString captureSettingPath ) { this->m_captureSettingPath = captureSettingPath; }

        // 以下为读写程式相关函数
        Job::InspectionData& inspectionData() { return this->m_inspectionData; }

        Job::MeasuredObj *pMeasuredObj() { return this->m_pHeadMeasuredObj; }

        QString& jobPath() { return this->m_jobPath; }
        void setJobPath( QString jobPath ) { this->m_jobPath = jobPath; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        AppSetting m_appSetting;                // 软件配置
        CaptureSetting m_captureSetting;        // 图像配置
        QString m_appSettingPath;               // 软件配置文件路径
        QString m_captureSettingPath;           // 图像配置文件路径

        Job::InspectionData m_inspectionData;   // 检测数据
        Job::MeasuredObj *m_pHeadMeasuredObj;   // 被测对象头指针
        QString m_jobPath;                      // 记录扫描的程式路径
    };

}//End of namespace App

#endif // APPSTARTUP_HPP
