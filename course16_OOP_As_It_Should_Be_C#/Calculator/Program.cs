using System;
using System.Reflection.Metadata;



class clsCalculator
{
    private int _OperationValue = 0;
    private int _Result = 0;
    private string _Operation = "";

    public void Add(int NumToAdd)
    {
        _Result += NumToAdd;
        _Operation = "Adding";
        _OperationValue = NumToAdd;
    }

    public void Substract(int SubstractValue)
    {
        _Result -= SubstractValue;
        _Operation = "Substracting";
        _OperationValue = SubstractValue;
    }

    public void Divide(int DivideValue)
    {
        _Operation = "Dividing";
        _OperationValue = DivideValue;
        if (DivideValue == 0)
        {
            _Result /= 1;
            return;
        }

        _Result /= DivideValue;


    }


    public void Multiply(int MultiplyValue)
    {
        _OperationValue = MultiplyValue;
        _Operation = "Multiplying";
        _Result *= MultiplyValue;
    }


    public void Clear()
    {

        _OperationValue = 0;
        _Result = 0;
        _Operation = "Clear";
    }

    public void PrintResult()
    {
        Console.WriteLine("Result After {0} {1} is : {2}", _Operation, _OperationValue, _Result);
    }






}




internal class Program
{
    static void Main(string[] args)
    {
        clsCalculator Claculator1 = new clsCalculator();


        Claculator1.Add(10);
        Claculator1.PrintResult();

        Claculator1.Add(100);
        Claculator1.PrintResult();

        Claculator1.Substract(20);
        Claculator1.PrintResult();

        Claculator1.Divide(0);
        Claculator1.PrintResult();

        Claculator1.Divide(2);
        Claculator1.PrintResult();

        Claculator1.Multiply(3);
        Claculator1.PrintResult();

        Claculator1.Clear();
        Claculator1.PrintResult();
    }

}