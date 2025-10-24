#include  <iostream>
using namespace std ;


class clsCalculator{
    private:
        float _Result = 0;
        float _LastNumber = 0;
        string _LastOperation = "clear";
        float _PreviousResult = 0;

    public:

    bool IsZero(float number){
        return number == 0;
    }

    void Add(float number){
        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += number;
    }

    void Substract(float number)
    {

        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Substracting";
        _Result -= number;
    }

    void Multiply(float number)
    {
        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Multiplying";
        _Result *= number;
    }

    void Divide(float number)
    {
        if (0==number){
            number = 1;
        }
        _LastNumber = number;
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= number;
    }

    void clear()
    {
        _LastOperation = "Clear";
        _Result = 0;
    }

    void printResult (){
        if(_LastOperation=="Clear"){
            cout << "Calculator is Clear Now " << endl;
            return;
        }
        cout << "The Result After "<<_LastOperation<<" "<<_LastNumber<< " Is "<< _Result << endl;
    }

    
};

int main(){

    clsCalculator Calculator1;

    Calculator1.Add(100);
    Calculator1.printResult();

    Calculator1.Substract(20);
    Calculator1.printResult();

    Calculator1.clear();
    Calculator1.printResult();

    Calculator1.Add(10);
    Calculator1.printResult();

    Calculator1.Multiply(100);
    Calculator1.printResult();

    Calculator1.Divide(0);
    Calculator1.printResult();

    Calculator1.Divide(2);
    Calculator1.printResult();


    return 0;




}