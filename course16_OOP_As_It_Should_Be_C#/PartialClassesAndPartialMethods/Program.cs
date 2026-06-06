using System;

internal class Program { 

    static void Main()
    {

        ClsMyClass Object1 = new ClsMyClass();

        Object1.Method1();
        Object1.Method2();


        Console.WriteLine("Partial Method :");

        ClsPerson Person1 = new ClsPerson();

        Person1.Age = 23;

        Person1.BirthDay();

    }


}
