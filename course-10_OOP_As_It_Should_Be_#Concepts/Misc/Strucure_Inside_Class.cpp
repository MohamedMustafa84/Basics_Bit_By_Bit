#include <iostream>
using namespace std ;


class clsPerson {
    struct stAddress{
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };
    public :
    string FullName;
    stAddress Address;
    clsPerson(){
        FullName = "Mohamed Mustafa";
        Address.AddressLine1 = "UmKaty";
        Address.AddressLine2 = "Karary";
        Address.City = "Khartoum";
        Address.Country = "Sudan";
    }
    void Print(){
        cout << "================= Person Information ==================" << endl;
        cout << "Full Name     : " << FullName << endl;
        cout << "Address Line1 : " << Address.AddressLine1 << endl;
        cout << "Address Line2 : " << Address.AddressLine2 << endl;
        cout << "City          : " << Address.City << endl;
        cout << "Country       : " << Address.Country << endl;
        cout << "========================================================" << endl;
    }
};

int main(){

    clsPerson Person1;
    Person1.Print();

    return 0;
}