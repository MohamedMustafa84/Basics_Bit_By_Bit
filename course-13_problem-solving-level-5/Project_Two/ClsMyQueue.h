#pragma once

#include <iostream>
#include "../Project_One/Project_One/ClsDblLinkedList.h"
template <class T>

class clsMyQueue{

    protected :
        clsDblLinkedList<T> _MyList;

    public:
        void push (T Item){
            _MyList.InsertAtEnd(Item);
        }

        void pop(){
            _MyList.DeleteLastNode();
        }

        void print (){
            _MyList.printList();
        }

        int size(){
             return _MyList.Size();
        }

        bool isEmpty(){
            return _MyList.IsEmpty();
        }

        T front(){
            return _MyList.GetItem(0);
        }

        T back()
        {
            return _MyList.GetItem(size()-1);
        }
};