#include <iostream>
using namespace std;

class clsPerson
{

    private:
    string _firstName;
    string _lastName ;


public:

    // property set     
    void SetFirstName(string firstName){
        _firstName = firstName;
    }

    void SetLastName(string lastName)
    {
        _lastName = lastName;
    }

    // property get

    string GetfirstName(){
        return _firstName;
    }
    string GetLastName()
    {
        return _lastName;
    }

   
};

int main()
{

    clsPerson person1;

    person1.SetFirstName("Mohamed");
    person1.SetLastName("Mustafa");

    cout << "My Name IS" << person1.GetfirstName() + " " + person1.GetLastName() << endl;

    return 0;
}