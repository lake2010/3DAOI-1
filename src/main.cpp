#include <iostream>

#include "SDK/customexception.hpp"
#include "App/datagenerator.hpp"
#include "App/appsetting.hpp"
#include "App/capturesetting.hpp"

using namespace std;
using namespace App;
using namespace Job;
using namespace SDK;

//void func()
//{
//    THROW_EXCEPTION("Argument invaild!");
//}

int main()
{
//    try
//    {
//        func();
//    }

//    catch(SDK::CustomException& ex)
//    {
//        cout << ex.what() << endl;
//    }



    AppSetting app;
    app.load( "../src/AppSetting.ini" );

    CaptureSetting capture;
    capture.load( "../src/CaptureSetting.ini" );

    DataGenerator data;
    data.generateData();



    return 0;
}


