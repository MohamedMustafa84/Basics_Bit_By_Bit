#pragma once 
#include <iostream>
#include "../../Libs/ClsDate.h"
#include <stack>
#include <queue>
using namespace std;


class clsQueueLine{
    short _AverageServeTime = 0;
    short _TotalTickets = 0;
    string _Prefix = "";
    
    
    class clsTicket
    {
        short _Number=0;
        string _Prefix = "";
        short _WaitingClients = 0;
        short _AverageServeTime = 0;

        public :
            clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime){
                _Prefix = Prefix;
                _Number = Number;
                _WaitingClients = WaitingClients;
                _AverageServeTime = AverageServeTime;
            }

            string Prefix(){
                return _Prefix;
            }

            short Number(){
                return _Number;
            }

            string FullName(){
                return _Prefix + to_string(_Number);
            }

            short WaitingClients(){
                return _WaitingClients;
            }

            short ExpectedServeTime(){
                return _AverageServeTime * (_WaitingClients+1);
            }


            void print(){
                cout << "\n\t\t\t-------------------------------------------------\n";
                cout << "\n\t\t\t\t    " << FullName();
                cout << "\n\t\t\t\t    Waiting Clients : " << _WaitingClients;
                cout << "\n\t\t\t\t    Serve Time In";
                cout << "\n\t\t\t\t    "<<ExpectedServeTime()<<" Minutes";
            }


    };


public:
    queue<clsTicket> QueueLine;

    clsQueueLine(string Prefix, short AverageServeTime)
    {
        _Prefix = Prefix;
        _TotalTickets = 0;
        _AverageServeTime = AverageServeTime;
    }

    void IssueTicket(){

        _TotalTickets++;
        clsTicket NewTicket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime);
        QueueLine.push(NewTicket);
    }

    int WaitingClients(){
        return QueueLine.size();
    }

    string WhoIsNext(){
        if(QueueLine.empty()){
            return "No Clients Left";
        }
        return QueueLine.front().FullName();
    }

    bool ServeNextClient(){
        if(QueueLine.empty()){
            return false;
        }
        QueueLine.pop();

        return true;
    }

    short ServedClients(){
        return _TotalTickets - WaitingClients();
    }


    void PrintInfo(){
        cout << "\n\t\t\t-------------------------------------------\n";
        cout << "\n\t\t\t\tQueue Info \n";
        cout << "\n\t\t\t-------------------------------------------\n";
        cout << "\n\t\t\t   Prefix  = "<<_Prefix;
        cout << "\n\t\t\t   Total Tickets = "<<_TotalTickets;
        cout << "\n\t\t\t   Served Clients = "<<ServedClients();
        cout << "\n\t\t\t   Waiting Clients = "<<WaitingClients();
        cout << "\n\t\t\t-------------------------------------------\n";
    }

    void PrintTicketsLineRTL(){
        if(QueueLine.empty()){
            cout << "\n\t\t Tickets : No Ticket" << endl;
        }else{
            cout <<"\n\t\t Tickets :\n";
            // we copy  the Queue in order not to lose the original
            queue<clsTicket> TempQueue = QueueLine; 
            
            while(!TempQueue.empty()){
                cout << " ";

                TempQueue.front().print();
                cout<<" <-- ";
               
                TempQueue.pop();
            }

            cout << endl;
        }
    }

    void PrintTicketsLineLTR(){
        if(QueueLine.empty()){
            cout << "\n\t\t Tickets : No Ticket" << endl;
        }else{
            stack<clsTicket> TempStack;
            queue<clsTicket> TempQueue = QueueLine ;
        //  copy Queue content in to a stack to reverse the output
            while(!TempQueue.empty()){
                TempStack.push(TempQueue.front());
                TempQueue.pop();
            }

            cout << "\n\t\t Tickets :\n";

            while(!TempStack.empty()){
                cout << " ";
                TempStack.top().print();
                cout<< " --> ";
                TempStack.pop();
            }
        }
    }



    void PrintAllTickets(){
        cout << "\n\n\t\t\t --------- Tickets -------------\n";

        if(QueueLine.empty()){
            cout << " ---- No Tickets ----------\n";
        }else{
            queue<clsTicket> TempQueue = QueueLine;
            while(!TempQueue.empty()){
                cout << " ";
                TempQueue.front().print();
                TempQueue.pop();
            }
        }
    }


};
