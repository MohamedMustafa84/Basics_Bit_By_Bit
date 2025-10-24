#include <iostream>
using namespace std; 



class clsAddress{
    private:
    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

    public:


// Constructor 
// is a method without any type and take the class name 
// the constructor call whenever you create new Object from the class and every  class has default  constructor

// for instance

        clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode){
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _POBox = POBox;
            _ZipCode = ZipCode;
        }

            void SetAddressLine1(string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }

    string AddressLine1()
    {
        return _AddressLine1;
    }

    void SetAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }

    string AddressLine2()
    {
        return _AddressLine2;
    }


    void setPOBox(string POBox){
        _POBox = POBox;
    }

    string  POBox()
    {
        return _POBox;
    }

    void setZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }

    string ZipCode()
    {
        return _ZipCode;
    }

    void printAddressDetails (){
        cout <<"\nAddress Details :\n";
        cout << "---------------------------------------\n";
        cout <<"\nAddress Line 1 : "<<_AddressLine1<<endl;
        cout <<"\nAddress Line 2 : "<<_AddressLine2<<endl;
        cout <<"\nPOBox          : "<<_POBox<<endl;
        cout <<"\nZipCode        : "<<_ZipCode<<endl;
    }
};

int main(){

    clsAddress Person1("Queen Alia Street","B204","11148","6544");
    Person1.printAddressDetails();
    return  0;
}
