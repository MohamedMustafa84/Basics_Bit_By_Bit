using System;
using MyMath;



internal class Program { 
    static void Main(string[] args)
    {

        clsMath Math1 = new clsMath();

        int reuslt = Math1.Sum(10, 20);

        Console.WriteLine("10 + 20 = {0}",reuslt);

    }

}