#include <iostream>
#include "ClsMyStack.h"
using namespace std;

int main()
{

    clsMyStack<int> MyStack;

    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);
    MyStack.Push(40);
    MyStack.Push(50);
    MyStack.Push(60);
    MyStack.Push(1880);

    cout << "My Stack Content : \n ";
    MyStack.print();

    cout << "\nStack Size = " << MyStack.size();
    cout << "\nStack Top = " << MyStack.Top();
    cout << "\n Stack Bottom = " << MyStack.Bottom();

    MyStack.pop();

    cout << "\nMy Stack After pop() :\n";
    MyStack.print();

    // Extention #1

    cout << "\n\n Item(2)" << MyStack.GetItem(2);

    // Extention #2
    // MyStack.Reverse();

    // cout << "\n Stack After the reverse : \n";
    // MyStack.print();

    // Extention #3
    MyStack.UpdateItem(2, 500);

    cout << "\nStack After Updating the Item of Index 2 To 500 :\n";
    MyStack.print();

    // Extention #4

    MyStack.InsertAfter(3, 400);

    cout << "Stack after inserting 400 after the item of index 3 : \n";
    MyStack.print();

    // Extention #5
    MyStack.InsertAtTop(100);

    cout << "Stack After Inserting 100 at the Top :\n";
    MyStack.print();

    // Extention #6
    MyStack.InsertAtBottom(200);

    cout << "Stack After Inserting 200 at the Bottom :\n";
    MyStack.print();

    // Extention #7
    MyStack.Clear();

    cout << "Stack After Clear() : \n";
    MyStack.print();

    return 0;
}