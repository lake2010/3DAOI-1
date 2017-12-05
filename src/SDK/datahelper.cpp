#include <random>
#include <ctime>
#include <functional>

#include "datahelper.hpp"

using namespace std;
using namespace SDK;

DataHelper::DataHelper()
{

}

DataHelper::~DataHelper()
{

}

double DataHelper::generateRandomNum()
{
    // 调用随机数引擎类，用于生成随机数
    static default_random_engine random( time( NULL ) );
    // 调用浮点型分布类，用于设置随机数范围
    static uniform_real_distribution<double> range( 10, 100 );
    // 返回生成的随机数
    return range( random );
}

string DataHelper::generateTime()
{
    // 基于当前系统的当前日期/时间
    time_t now = time(0);
    tm *localTime = localtime(&now);
    // 将日期和时间格式化输出
    char currentTime[20];
    sprintf(currentTime,"%d/%02d/%02d %02d:%02d:%02d",
            1900 + localTime->tm_year,
            1+ localTime->tm_mon,
            localTime->tm_mday,
            localTime->tm_hour,
            localTime->tm_min,
            localTime->tm_sec);

    return currentTime;
}
