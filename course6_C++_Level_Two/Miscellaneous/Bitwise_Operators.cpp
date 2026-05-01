#include <iostream>
using namespace std;


//----- Bitwise AND Operator -----

// Bitwise (12 & 25) = 8

// 12= 00001100 (in Binary)
// 25= 00011001 (in Binary)

// Bit Operator of 12 and 25
//     00001100
//   & 00011001
//    ___________
//     00001000 = 8(in decimal)
 



//----- Bitwise OR  Operator -----

// Bitwise(12 | 25) = 29

// Bit Operator of 12 and 25
//     00001100
//   | 00011001
//    ___________
//     00011101 = 29(in decimal)

int main()
{
    cout << "Bitwise And Operator for (12 & 25) is " << (12 & 25) << endl;
    cout << "Bitwise OR Operator for (12 | 25) is " << (12 | 25) << endl;
    return 0;
}
