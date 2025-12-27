#pragma once
#include "../Project_Five/ClsMyQueueArr.h"
#include <iostream>
using namespace std; 

template <class T>


class clsMyStackArr : public clsMyQueueArr <T>{

  

    public:
        void Push(T Item)
        {
            clsMyQueueArr<T>::_MyArray.InsertAtBeginning(Item);
        }

        T Top(){
            return clsMyQueueArr<T>::front();
        }

        T Bottom()
        {
            return clsMyQueueArr<T>::back();
        }
        void InsertAtTop(T Item){
            clsMyQueueArr<T>::InsertAtFront(Item);
        }

        void InsertAtBottom(T Item)
        {
            clsMyQueueArr<T>::InsertAtBack(Item);
        }
};
