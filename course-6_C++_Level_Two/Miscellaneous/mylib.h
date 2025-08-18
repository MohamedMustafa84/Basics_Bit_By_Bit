#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

namespace UserInputs
{
    int ReadNumber(string Message)
    {
        int Number;
        cout << Message << " ";
        cin >> Number;
        while (cin.fail())
        {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid Number , Enter A Valid One:" << endl;
            cin >> Number;
        }



        return Number;
    }
}

namespace Checker
{
    bool isPositiveNumber(int Number)
    {
        return (Number >= 0) ? true : false;
    }
}

namespace Random{
    int RandomNumberInRange(int from ,int to){
        return rand() % (to - from + 1) + from;
    }

}



