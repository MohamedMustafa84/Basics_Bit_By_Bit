#include <iostream>
using namespace std ;




// Abstract Class or interface :
//  is A class include Pure Virtual Functions
// And Any Class inherit this Class need to Override all  the  pure Virtual Functions

// We are not able to make Object from the Abstract class Only we can Inherit it  


class clsMobile{
    // this is the pure Virtual functions 
        virtual void Deil(string phoneNumber) = 0;
        virtual void SendSMS(string Text) = 0;
        virtual void TakePhoto() = 0;
};


class clsIphone:public clsMobile{
    public:
    void Deil(string phoneNumber){

    }

    void SendSMS(string Text) {

    }

    void TakePhoto(){
        
    }
};

class clsSamsung :public clsMobile{
public:
    void Deil(string phoneNumber)
    {
    }

    void SendSMS(string Text)
    {
    }

    void TakePhoto()
    {
    }
};

int main (){

    clsIphone Iphone17;
    Iphone17.SendSMS("Hi");
    Iphone17.TakePhoto();

    clsSamsung S24;

    S24.Deil("2499243150605");
    S24.SendSMS("Hello");
    S24.TakePhoto();

    return 0; 

}