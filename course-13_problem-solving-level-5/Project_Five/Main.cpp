#include <iostream>
#include "ClsMyQueueArr.h"
using namespace std;

int main()
{

    clsMyQueueArr<int> MyQueue;

    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);
    MyQueue.push(60);
    MyQueue.push(1880);

    cout << "My Queue Content : \n ";
    MyQueue.print();

    cout << "\nQueue Size = " << MyQueue.size();
    cout << "\nQueue Front = " << MyQueue.front();
    cout << "\n Queue Back = " << MyQueue.back();

    MyQueue.pop();

    cout << "\nMy Queue After pop() :\n";
    MyQueue.print();

    // Extention #1

    cout << "\n\n Item(2)" << MyQueue.GetItem(2);

    // Extention #2
    MyQueue.Reverse();

    cout << "\n Queue After the reverse : \n";
    MyQueue.print();

    // Extention #3
    MyQueue.UpdateItem(2, 500);

    cout << "\nQueue After Updating the Item of Index 2 To 500 :\n";
    MyQueue.print();

    // Extention #4

    MyQueue.InsertAfter(3, 400);

    cout << "Queue after inserting 400 after the item of index 3 : \n";
    MyQueue.print();

    // Extention #5
    MyQueue.InsertAtFront(100);

    cout << "Queue After Inserting 100 at the front :\n";
    MyQueue.print();

    // Extention #6
    MyQueue.InsertAtBack(200);

    cout << "Queue After Inserting 200 at the back :\n";
    MyQueue.print();

    // Extention #7
    MyQueue.Clear();

    cout << "Queue After Clear() : \n";
    MyQueue.print();

    return 0;
}