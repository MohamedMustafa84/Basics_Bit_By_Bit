#include <iostream>
using namespace std;


class clsPerson{

    int Age;
// this private and will not be accessed from outside the class

// for internal use only


    public:
        string firstName = "";
        string LastName = "";
        string fullName(){
            firstName + " " + LastName;
        }
};

int main(){

    clsPerson person1;

    person1.firstName = "Mohamed";
    person1.LastName = "Mustafa";



    return 0;
}