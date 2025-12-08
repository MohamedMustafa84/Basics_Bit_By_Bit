#pragma once

#include <iostream>
using namespace std;


template <class T>

class clsDblLinkedList{
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
        }

        void InsertAtEnd(T value)
        {
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
                return;
            }

            while(Current !=NULL && Current->next !=NULL){
                Prev = Current;
                Current= Current->next;
            }

            Prev->next = NULL;


            delete Current;

            return;
        }


};