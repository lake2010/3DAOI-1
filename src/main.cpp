#include <iostream>

#include "App/appstartup.hpp"
#include "SDK/customexception.hpp"

using namespace std;
using namespace App;
using namespace SDK;

int main()
{
    try
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 启动软件，设置配置文件的路径
        AppStartup app;
        app.setAppSettingPath( "../src/Setting/AppSetting.ini" );
        app.setCaptureSettingPath( "../src/Setting/CaptureSetting.ini" );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 加载两个配置文件
        app.loadAppSetting( app.appSettingPath() );
        app.loadCaptureSetting( app.captureSettingPath() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 读取程式文件夹目录下的程式
        app.readJobPath();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4 如果目录下无程式，则生成默认程式；如果有程式，加载用户选择的程式
        if ( app.jobPath() == "" )
        {
            // 生成随机数据
            app.dataGenerator().generateData( app.inspectionData(),
                                              app.pMeasuredObj() );
            // 设置程式路径
            app.setJobPath( app.appSetting().jobFolderPath() + "V2" );
            // 生成默认程式
            app.generateJob( app.jobPath(), app.inspectionData() );
            cout << "文件夹中无程式，已生成默认程式！" << endl;
        }
        else
        {
            // 加载检测数据
            app.loadInspectionData( app.jobPath() );
            cout << "程式加载成功！" << endl;
        }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //5 打印检测数据到屏幕
        cout << endl << "检测信息如下：" << endl;
        app.inspectionData().print();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //6 将检测数据以xml格式输出
        app.writeToXml( app.jobPath() + ".xml", app.inspectionData() );
        cout << endl << "XML写入成功！" << endl;
    }
    catch( const CustomException& ex )
    {
        cout << ex.what() << endl;
    }
    return 0;
}


