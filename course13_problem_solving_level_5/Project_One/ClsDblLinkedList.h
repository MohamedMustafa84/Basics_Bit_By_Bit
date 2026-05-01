#pragma once

#include <iostream>
using namespace std;


template <class T>

class clsDblLinkedList{
    protected:
        int _Size = 0;

    public :
    class node{
        public:
        T value;
        node *prev;
        node *next;
    };

        node *head = NULL;
        void InsertAtBeginning(T value)
        {
            node *newNode = new node();

            newNode->value = value;
            newNode->next = head;
            newNode->prev = NULL;

            head = newNode;
            _Size++;
        }

        void printList()
        {
            node *Current =head;

            while (Current != NULL)
            {
                cout << Current->value << " ";
                Current = Current->next;
            }
            cout << "\n";
        }

        node *Find(T Nodevalue)
        {

            node *Current = head;
            while (Current != NULL)
            {

                if (Current->value == Nodevalue)
                {
                    return Current;
                }

                Current = Current->next;
            }

            return NULL;
        }

        void InsertAfter(node *&NodeToInsertAfter, T value)
        {

            node *newNode = new node();

            newNode->prev = NodeToInsertAfter;
            newNode->value = value;
            newNode->next = NodeToInsertAfter->next;

            if (NodeToInsertAfter != NULL)
            {
                NodeToInsertAfter->next->prev = newNode;
            }

            NodeToInsertAfter->next = newNode;
            _Size++;
        }

        void InsertAtEnd(T value)
        {

            _Size++;
            node *newNode = new node();

            newNode->value = value;
            newNode->next = NULL;

            if (head == NULL)
            {
                head = newNode;
                return;
            }

            // search for the last node
            node *Current = head;

            while (Current->next != NULL)
            {
                Current= Current->next;
            }

            Current->next = newNode;
            

            return;
        }

        void DeleteNode(node*& NodeToBeDelete)
        {

            if (head == NULL)
            {
                return;
            }

            node *Current = head;
            node *Prev = head;

            if (Current->value == NodeToBeDelete->value)
            {
                head = Current->next;
                delete Current;
            }

            // Find the Key To Be Deleted
            while (Current != NULL && Current->value != NodeToBeDelete->value)
            {
                Prev = Current;
                Current = Current->next;
            }

            // if the value is not present
            if (Current == NULL)
                return;

            Prev->next = Current->next;
            delete Current; // free from memory
            _Size--;
        }

        void DeleteFirstNode()
        {
            node *Current = head;

            if (head == NULL)
            {
                return;
            }

            head = Current->next;
            delete Current;

            _Size--;

            return;
        }

    
        void DeleteLastNode()
        {
            node *Current = head;
            node *Prev = head;

            if (head == NULL)
            {
                return;
            }

            if(Current->next == NULL){
                head = NULL;
                delete Current;
                _Size--;

                return;
            }

            while(Current !=NULL && Current->next !=NULL){
                Prev = Current;
                Current= Current->next;
            }

            Prev->next = NULL;


            delete Current;
            _Size--;

            return;
        }

         int Size(){
            return _Size;
        }


        bool IsEmpty(){
            return (_Size == 0);
        }

        void Clear()
        {
            node *cur = head;
            while (cur != nullptr)
            {
                node *next = cur->next;
                delete cur;
                cur = next;
            }
            head = nullptr;
            _Size = 0;
        }

        void Reverse(){
             node *Current=head;
             node *temp = nullptr;

             while(Current !=nullptr){
                temp=Current->prev;
                Current->prev = Current->next;
                Current->next = temp;

                Current = Current->prev;
             }

             if(temp !=nullptr){
                 head = temp->prev;
             }
        }

        node *GetNode(int Index){
            int Counter = 0;

            if (Index > _Size-1 || Index < 0)
            {
                return NULL;
            }

            node *Current = head;

            while(Current !=NULL && Current->next !=NULL){
                
                if(Counter == Index ){
                    break;
                }
                Current = Current->next;
                Counter++;
            }

            return Current;
        }



        T GetItem(int Index){

            node *ItemNode = GetNode(Index);

            if (ItemNode ==NULL){
                return 0;
            }else{
                return ItemNode->value;
            }
        }

        bool Update(int Index, T newValue){
            node *NodeToUpdate =GetNode(Index);
            if(NodeToUpdate != NULL){
                NodeToUpdate->value = newValue;
                return true;
            }
            return false;
        }

        bool InsertAfter(int Index , T Value ){

            node *ItemNode=GetNode(Index);

            if(ItemNode !=NULL){
                
                InsertAfter(ItemNode, Value);

                return true;
            }
            return false;
        }



};