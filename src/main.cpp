#include <iostream>

#include "App/appstartup.hpp"

using namespace std;
using namespace App;
using namespace Job;
using namespace SDK;

int main()
{
    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //1 启动软件，设置配置文件的路径
    AppStartup start;
    start.setAppSettingPath( "../src/Setting/AppSetting.ini" );
    start.setCaptureSettingPath( "../src/Setting/CaptureSetting.ini" );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //2 加载AppSetting.ini和CaptureSetting.ini
    start.loadAppSetting( start.appSettingPath() );
    start.loadCaptureSetting( start.captureSettingPath() );

    //>>>-------------------------------------------------------------------------------------------------------------------------------------
    //3 扫描程式文件夹目录下的程式



//    AppSetting appSetting;
//    appSetting.load( "../src/Setting/AppSetting.ini" );

//    CaptureSetting capture;
//    capture.load( "../src/Setting/CaptureSetting.ini" );

//    DataGenerator data;
//    data.generateData();

//    InspectionData ins;
//    MeasuredObj objs[OBJ_CNT];
//    DataGenerator data;
//    data.generateData(ins,objs);

//    AppStartup app;

//    app.writeToXml("../data/V1.xml",ins);

    return 0;
}


