# include <iostream>
#include "ClsDynamicArray.h"
using namespace std;


int main(){

    clsDynamicArray<int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty ? " <<( MyDynamicArray.IsEmpty()? "YES" :"No");
    cout << "\nArray Size : " << MyDynamicArray.Size();

    cout << "\n Array Items : \n";
    MyDynamicArray.printList();

    // Extention 1 Resize Array
    MyDynamicArray.Resize(2);
    cout << "\n\nArray Size : " << MyDynamicArray.Size();
    cout << "\nArray Items After Resize To 2 : \n";
    MyDynamicArray.printList();

    MyDynamicArray.Resize(10);
    cout << "\n\nArray Size : " << MyDynamicArray.Size();
    cout << "\nArray Items After Resize To 10 : \n";
    MyDynamicArray.printList();

    return 0;
}