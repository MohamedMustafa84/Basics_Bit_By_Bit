#include <iostream>
#include <cmath>
#include <string>
using namespace std;



int   readValidatedNumberInRange(int  from, int  to, int   number)
{
    while (number < from || number > to)
    {
        cout << " the number most be between [" << from << " - " << to << "] please retry -->";
        cin >> number;
        cout << endl;
    }
    return number;
}



// ------------------------------------------------------------------
enum enCalculationType
{
    decimal = 1,
    Binary = 2,
    hexadecimal = 3,
    octal = 4
};
struct stCalculation{
    string Number;
    enCalculationType NumberType;
    enCalculationType ReadTargetType;
};



enCalculationType readNumberType(){
    
    int  NumberType = 0;
    cout << " please enter the [Digit] of  your number type form this list : \n";
    cout << "1 - decimal \n";
    cout << "2 - Binary \n";
    cout << "3 - hexadecimal \n";
    cout << "4 - Octal \n";
    cin >> NumberType;
    NumberType =readValidatedNumberInRange(1,4,NumberType);
    return (enCalculationType)NumberType;
}

string readNumber(){

    string Number = "";
    cout <<"Enter Your Number : ";
    cin >> Number;
    return Number;
}

enCalculationType ReadTargetType(){
    int  calcType = 0;
    cout << "############# Enter Calculation type ##############\n";
    cout << "conversion to  dictmal Enter 1 \n";
    cout << "conversion to  Binary Enter 2 \n";
    cout << "conversion to  hexadecimal Enter 3 \n";
    cout << "conversion to  octal Enter 4 \n";
    cin >> calcType;
    calcType = readValidatedNumberInRange(1,4,calcType);
    return (enCalculationType)calcType;
}

stCalculation ReadCalculationItems(){
    stCalculation calculation;
    calculation.Number = readNumber();
    calculation.NumberType = readNumberType();
    calculation.ReadTargetType = ReadTargetType();
    return calculation;
}


// ------------------------ to decimal---------------

string BinaryTodecimal(string BinaryNum)
{
    int BinaryNumber = stoi(BinaryNum);
    int  Remainder = 0, power = 0 ;
    int decimalNumber = 0;
    while (BinaryNumber > 0)
    {
        Remainder = BinaryNumber % 10;
        BinaryNumber = BinaryNumber / 10;
        decimalNumber += (Remainder * pow(2, power));
        power++;
    }
    
    return to_string(decimalNumber);
}
int octalTodecimal(string octalNum)
{
    int octalNumber =stoi(octalNum);

    int  Remainder = 0, power = 0, decimalNumber = 0;
    while (octalNumber > 0)
    {
        Remainder = octalNumber % 10;
        octalNumber = octalNumber / 10;
        decimalNumber += (Remainder * pow(8, power));
        power++;
    }
    return decimalNumber;
}
string hexaTodecimal(string hexaNumber)
{
    int decimalNumber = 0;
        for (int i = 0; i < hexaNumber.length(); i++)
        {
            if (hexaNumber[i] == 'A')
            {
                decimalNumber = decimalNumber + 10 * pow(16, i);
            }
            else if (hexaNumber[i] == 'B')
            {
                decimalNumber = decimalNumber + 11 * pow(16, i);
            }
            else if (hexaNumber[i] == 'C')
            {
                decimalNumber = decimalNumber + 12 * pow(16, i);
            }
            else if (hexaNumber[i] == 'D')
            {
                decimalNumber = decimalNumber + 13 * pow(16, i);
            }
            else if (hexaNumber[i] == 'E')
            {
                decimalNumber = decimalNumber + 14 * pow(16, i);
            }
            else if (hexaNumber[i] == 'F')
            {
                decimalNumber += 15 * pow(16, i);
            }
            else
            {
                decimalNumber = decimalNumber + hexaNumber[i] * pow(16, i);
            }
        }
    return to_string(decimalNumber);
}




// ------------ to binary-----------
string decimalToBinary(string decimalNum)
{
    int decimalNumber = stoi(decimalNum);

    string BinaryNumber = "";
    int  Remainder = 0;

    while (decimalNumber > 0)
    {
        Remainder = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        BinaryNumber = to_string(Remainder) + BinaryNumber;
    }

    return BinaryNumber;
}

string octalToBinary(string octalNumber)
{
    return decimalToBinary(to_string(octalTodecimal(octalNumber)));
}
string hexaToBinary(string hexaNumber){
    return  decimalToBinary(hexaTodecimal(hexaNumber));
     
 }



// ------------ to hexa -------------
string decimalToHexa(string decimalNum){
    int decimalNumber =stoi(decimalNum);
    int Remainder = 0;
    string hexaNumber = "";
    while(decimalNumber>0){
        
        Remainder =  decimalNumber % 16;
        
        switch (Remainder)
        {
        case 10:
            hexaNumber = "A"+hexaNumber;
            break;
        case 11:
            hexaNumber = "B"+hexaNumber;
            break;
        case 12:
            hexaNumber = "C"+hexaNumber;
            break;
            case 13:
            hexaNumber = "D"+hexaNumber;
            break;
        case 14:
            hexaNumber = "E"+hexaNumber;
            break;
        case 15:
            hexaNumber = "F" + hexaNumber;
            break;
            
            default:
                hexaNumber = to_string(Remainder) + hexaNumber;

                break;
        }
        decimalNumber = decimalNumber / 16;

    }
    return hexaNumber;
}


string octalToHexa(string octalNumber){
    return decimalToHexa(to_string(octalTodecimal(octalNumber)));
}

string BinaryToHexa(string BinaryNumber)
{
    return decimalToHexa(BinaryTodecimal(BinaryNumber));
}




// -------------- to Octal ------------
string decimalToOctal(string decimalNum){
    int decimalNumber = stoi(decimalNum);
    int Remainder = 0;
    string OctalNumber = "";

    while(decimalNumber >0){
        Remainder = decimalNumber % 8;
        decimalNumber = decimalNumber / 8;
        OctalNumber = to_string(Remainder) + OctalNumber ;
    }
    return OctalNumber;
}

string BinaryToOctal(string BinaryNum)
{
    return decimalToOctal(BinaryTodecimal(BinaryNum));
}

string hexaToOctal(string hexaNumber){

    return decimalToOctal(hexaTodecimal(hexaNumber));
}


int StartCalculation()
{
    stCalculation calculation = ReadCalculationItems();
    string Number = calculation.Number;
    enCalculationType NumberType = calculation.NumberType;
    enCalculationType OperationType = calculation.ReadTargetType;


    if(NumberType == OperationType){
        cout << "Error:You Enter Invalid Operation Type ,Your Number Already in This Type \n";
        cout << "Please Retry Again ";
        StartCalculation();
        return 0;
    }

    cout << "################ THE RESULT ####################\n";
    if(NumberType ==enCalculationType::decimal &&  OperationType==enCalculationType::Binary){
        cout << "Your Number in Binary is : ";
        cout << decimalToBinary(Number) << endl;
    }
     else if(NumberType ==enCalculationType::decimal && OperationType==enCalculationType::octal){
        cout << "Your Number in Octal is : ";
        cout << decimalToOctal(Number) << endl;
    }
    else if (NumberType == enCalculationType::decimal && OperationType == enCalculationType::hexadecimal)
    {
        cout << "Your Number in hexadecimal is : ";
        cout << decimalToHexa(Number) << endl;
    }
    else if (NumberType == enCalculationType::Binary && OperationType == enCalculationType::decimal)
    {
        cout << "Your Number in decimal is : ";
        cout << BinaryTodecimal(Number) << endl;
    }
    else if (NumberType == enCalculationType::Binary && OperationType == enCalculationType::octal)
    {
        cout << "Your Number in Octal is : ";
        cout << BinaryToOctal(Number) << endl;
    }
    else if (NumberType == enCalculationType::Binary && OperationType == enCalculationType::hexadecimal)
    {
        cout << "Your Number in hexadecimal is : ";
        cout << BinaryToHexa(Number) << endl;
    }
    else if (NumberType == enCalculationType::octal && OperationType == enCalculationType::decimal)
    {
        cout << "Your Number in decimal is : ";
        cout << octalTodecimal(Number) << endl;
    }
    else if (NumberType == enCalculationType::octal && OperationType == enCalculationType::Binary)
    {
        cout << "Your Number in Binary is : ";
        cout << octalToBinary(Number) << endl;
    }
    else if (NumberType == enCalculationType::octal && OperationType == enCalculationType::hexadecimal)
    {
        cout << "Your Number in hexadecimal is : ";
        cout << octalToHexa(Number) << endl;
    }
    else if (NumberType == enCalculationType::hexadecimal && OperationType == enCalculationType::decimal)
    {
        cout << "Your Number in decimal is : ";
        cout << hexaTodecimal(Number) << endl;
    }
    else if (NumberType == enCalculationType::hexadecimal && OperationType == enCalculationType::Binary)
    {
         cout << "Your Number in Binary is : ";
         cout << hexaToBinary(Number) << endl;
     }
     else if (NumberType == enCalculationType::hexadecimal && OperationType == enCalculationType::octal)
     {
         cout << "Your Number in Octal is : ";
         cout << hexaToOctal(Number) << endl;
     }
    else{
        cout << "Error While Calculate conversion " << endl;
    }
    return 0;
}

void ProgramerCalculator()
{
    char Retry = 'Y';
    do
    {
        StartCalculation();
        cout << "Do You Want To Retry ?[Y/N] ";
        cin >> Retry;
    } while (Retry == 'Y' || Retry == 'y');
}

int main()
{

    ProgramerCalculator();

    return 0;
    }