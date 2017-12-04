#include <iostream>

#include "SDK/customexception.hpp"
#include "App/datagenerator.hpp"
#include "App/appsetting.hpp"

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

    DataGenerator data;
    data.generateData();

    AppSetting app;
    app.load("AppSetting.ini");



    return 0;
}


