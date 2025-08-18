#include <iostream>
using namespace std;

void printLetters(){
    for (int i = 65; i<=90; i++){

        for (int j=65; j<=90; j++){

            cout << char(i) << char(j) << endl;
        }
        
    }
}




void printTringleStars(){

    for (int i = 1; i <= 10;i++){
        
        for (int j = 10; j >= i; j--)
        {
            cout <<"*";
        }
        cout << endl;
    }
}

// void printTrainagleOfNumber(){


//         for (int i = 10; i >= 1; i--)
//         {

//             for (int j = 1; j <= i; j++)
//             {
//                 cout << j;
//             }
//             cout << endl;
//         }
//     }

    void printTrainagleOfNumber()
    {

        for (int i = 1; i <= 10; i++){

            for (int j = 1; j<= i; j++){
                cout << j <<" ";
            }
            cout << "\n";
        }
        cout << endl;

    }

    void printTrainagleOfLetters()
    {

        for (int i = 65; i <= 90; i++)
        {

            for (int j = 65; j <= i; j++)
            {
                cout << char(j)<<" ";
            }
            cout << "\n";
        }
        cout << endl;
    }


void printNumebers(){
    for (int i = 1; i <= 10; i++){

        for (int j =i; j <= 10; j++){

            cout << j << " ";
        }
        cout << "\n";
    }
    cout << endl;
}







int main (){

    // printLetters();
    // printTringleStars();

    // printTrainagleOfNumber();

    // printTrainagleOfLetters();

    // printNumebers();

    return 0;
}
