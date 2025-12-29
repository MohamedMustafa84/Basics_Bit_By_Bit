#include <iostream>
#include "ClsQueueLine.h"

using namespace std; 

int main(){

    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("S0", 5);

    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    cout << "\n Pay Bill Queue Info :\n";
    PayBillsQueue.PrintInfo();

    cout << "\n--------------------------------------------\n";
    PayBillsQueue.PrintTicketsLineRTL();
    cout << "\n--------------------------------------------\n";
    PayBillsQueue.PrintTicketsLineLTR();


    PayBillsQueue.PrintAllTickets();

    PayBillsQueue.ServeNextClient();

    cout << "\nPay Bills Queue After Serving One Client : ";
    PayBillsQueue.PrintInfo();

    return 0;
}