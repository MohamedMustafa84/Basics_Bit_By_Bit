#include <iostream>
#include "ClsMyQueue.h"
using namespace std ;


int main(){

    clsMyQueue <int> MyQueue;

    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);
    MyQueue.push(60);
    MyQueue.push(1880);

    cout <<"My Queue Content : \n ";
    MyQueue.print();

    cout << "\nQueue Size = " << MyQueue.size();
    cout << "\nQueue Front = " << MyQueue.front();
    cout << "\n Queue Back = " << MyQueue.back();
    

    MyQueue.pop();

    cout << "\nMy Queue After pop() :\n";
    MyQueue.print();

    return 0;
}