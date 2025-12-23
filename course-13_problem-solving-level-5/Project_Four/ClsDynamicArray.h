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

        T GetItem(int Index){
             if(Index >= _Size){
                throw std::out_of_range("Index is out of range");
             }

            return OriginalArray[Index];
        }

        void Reverse(){
            if(_Size <0){
                return;
            }

            _TempArray = new T[_Size];

            int Counter= 0;
            for ( int i = _Size - 1; i >= 0;  i--){
                _TempArray[Counter] = OriginalArray[i];
                Counter++;
            }

            delete []OriginalArray;

            OriginalArray = _TempArray;
        }

        bool Clear(){

            _Size = 0;
            _TempArray = new T[0];
            delete[] OriginalArray;

            OriginalArray = _TempArray;
            return true;
        }

        bool DeleteItemAt(int Index){
            if(Index >=_Size ||_Size<0){
                return false;
            }

            _Size--;

            _TempArray = new T[_Size];

            // copy all items before the index to be deleted 
            for (int i = 0; i < Index; i++){

                _TempArray[i] = OriginalArray[i];  
            }
            
            for (int i = Index + 1; i < _Size +1; i++){
                _TempArray[i-1] = OriginalArray[i];  

            }

                delete[] OriginalArray;
                 OriginalArray = _TempArray;
                 return true;
        }

        bool DeleteFirstItem(){
            return DeleteItemAt(0);
        }

        bool DeleteLastItem()
        {
            return DeleteItemAt(_Size-1);
        }

        int Find(T Item){

            for (int i = 0; i < _Size; i++){
                if(OriginalArray[i]== Item){
                    return i;
                }
            }
            return -1;
        }

        bool Deleteitem(T Item){
            int ItemIndex = Find(Item);
            if(ItemIndex == -1){
                return false;
            }

            DeleteItemAt(ItemIndex);
            return true;

        }

        bool InsertAt(int Index ,T Item){
                if(Index <0 ||Index >_Size){
                    return false;
                }


             _Size++;
             _TempArray = new T[_Size];

             for (int i = 0; i <Index; i++)
             {
                 _TempArray[i] = OriginalArray[i];
                 
             }

             _TempArray[Index] = Item;

             for (int i = Index ; i < _Size-1; i++){
                 _TempArray[i+1] = OriginalArray[i];
             }

             delete [] OriginalArray;
             OriginalArray = _TempArray;

             return true;
        }

        bool InsertAtBeginning(T Item){
            return InsertAt(0, Item);
        }

        bool InsertAtEnd(T Item){
            return InsertAt (_Size,Item);
        }

            bool InsertBefore(T ItemToInsertBefore, T NewItem){
                int IndexToInsertBefore = Find(ItemToInsertBefore);

        if (IndexToInsertBefore == -1)
        {
            return false;
        }

            if (IndexToInsertBefore == 0)
            {
                return InsertAtBeginning(NewItem);
            }

            return InsertAt(IndexToInsertBefore - 1, NewItem);
        }
};
    