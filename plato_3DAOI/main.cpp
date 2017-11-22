#include <iostream>

#include "SDK/customexception.hpp"

using namespace std;

void func()
{
    THROW_EXCEPTION("Argument invaild!");
}

int main()
{
    try
    {
        func();
    }

    catch(SDK::CustomException& ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
