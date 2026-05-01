#include <iostream>
using namespace std;

// ---------- My Solution -------------

void printTableHeader(){
    cout << "\t \t \t  Multplcation Table from 1 to 10  \n\n";

    for (int i = 1; i <= 10; i++){
        cout << "\t" << i;
    }
    cout << endl;
    cout << "___________________________________________________________________________________\n";

}

void printTableBody()
{
    
    for (int i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            cout << i << " |";
        }
        else
        {
            cout << i << "  |";
        }
        for (int j = 1; j <= 10; j++)
        {
            cout << "\t" << i * j;
        }
        cout << endl;
    }
}

 void printMultiplcationTable(){
    printTableHeader();
    printTableBody();
}

    // ---------- teacher solution -------

    void PrintTableHeader(){
        cout <<"\n\n\t\t\t multiplication from 1 to 10 \n";
        cout << "\t";
        for (int i = 1; i <= 10; i++){
            cout << i << "\t";
        }
        cout << "\n___________________________________________________________________________________" << endl;
    }
    string columnSeparator(int i){
        if (i ==10){
            return "  |";
        }
        else{
            return "   |";
        }
    }

    void  PrintMultiplicationTable(){
        PrintTableHeader();
        for (int i = 1; i <= 10; i++){
            cout << i << columnSeparator(i)<<"\t";
            for (int j = 1; j <= 10; j++)
            {
                cout << i * j << "\t";
            }
            cout << endl;
        }
    }

    int
    main()
{
    // printMultiplicationTable();
    // PrintMultiplicationTable();

    return 0;
}