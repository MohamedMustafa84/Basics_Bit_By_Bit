#include <iostream>
using namespace std;

class clsPerson{
    public :
        // virtual function
        // we use it when we need to work with pointer and   the compiler create a table in memory to handel the address right
        // it like hint to compiler tell it we want to override this function

        // Note : Virtual Function Make the Program abit slow because it  create a table in the Memory , put it make the code more secure

        virtual void print()
        {
            cout << "Hi Iam A Person " << endl;
        }
};

class clsEmployee : public clsPerson
{

public:
 void print()
    {
        cout << "Hi Iam An Employee " << endl;
    }
};

class clsStudent:public clsPerson
{

public:
    void print()
    {
        cout << "Hi Iam A Student  " << endl;
    }
};

int main (){

    clsEmployee Employee1;
    clsStudent Student1;

    clsPerson *Person1 = &Employee1;
    clsPerson *Person2 = &Student1;

    Person1->print();
    Person2->print();

    return 0; 

}