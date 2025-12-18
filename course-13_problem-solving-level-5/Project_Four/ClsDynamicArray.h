 #pragma once 
 #include <iostream>
using namespace std;

template <class T>

class clsDynamicArray {
    protected :
        int _Size;
        T *_TempArray;

    public :
        T *OriginalArray;

        clsDynamicArray(int size = 0){

            if(size <0){
                size = 0;
            }

            _Size = size;

            OriginalArray = new T[_Size];
        }

        ~clsDynamicArray(){
            delete[] OriginalArray;
            delete[] _TempArray;
        }



        bool SetItem(int Index ,T Value){
            if(Index <0 || Index >= _Size){
                return false;
            }

            OriginalArray[Index] = Value;
            return true;
        }

        int Size(){
            return _Size;
        }


        bool IsEmpty(){
            return _Size == 0;
        }

        void printList(){
            for (int i = 0; i < _Size; i++){
                cout << OriginalArray[i] << " ";
            }
            cout << "\n";
        }

        bool Resize(int NewSize){
            if(NewSize<0){
                NewSize = 0;
            }

            _TempArray = new T[NewSize];

            // Limit the Original Size To the size if it is less
            if(NewSize <_Size){
                _Size = NewSize;
            }

            // Copy All Date from the Original Array Until the size 
            for (int i = 0; i < _Size; i++){
                _TempArray[i] = OriginalArray[i];
            }

            _Size = NewSize;

            delete[] OriginalArray;
            OriginalArray = _TempArray;
            

            return true;
        }
};