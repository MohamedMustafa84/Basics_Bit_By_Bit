#pragma once
#include "../Project_Two/ClsMyQueue.h"
#include <iostream>
using namespace std; 

template <class T>


class clsMyStack :public clsMyQueue <T>{
    

    public:
        void Push(T Item ){
            clsMyQueue<T>::_MyList.InsertAtBeginning(Item);
        }

        


        T Top(){
          return  clsMyQueue <T>::front();
        }

        T Bottom()
        {
          return   clsMyQueue<T>::back();
        }
    void InsertAtTop(T Item){
        clsMyQueue<T>::InsertAtFront(Item);
    }

    void InsertAtBottom(T Item)
    {
        clsMyQueue<T>::InsertAtBack(Item);
    }
};
