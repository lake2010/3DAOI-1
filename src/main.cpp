#include <iostream>

#include "App/appstartup.hpp"
#include "SDK/customexception.hpp"

using namespace std;
using namespace App;
using namespace Job;
using namespace SDK;

int main()
{
    try
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 启动软件，设置配置文件的路径和程式文件夹路径
        AppStartup start;
        start.setAppSettingPath( "../src/Setting/AppSetting.ini" );
        start.setCaptureSettingPath( "../src/Setting/CaptureSetting.ini" );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 加载AppSetting.ini和CaptureSetting.ini
        start.loadAppSetting( start.appSettingPath() );
        start.loadCaptureSetting( start.captureSettingPath() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 读取程式文件夹目录下的程式
        start.readJobFolder();
    }
    catch( const CustomException& ex )
    {
        cout << ex.what() << endl;
    }

    return 0;
}


