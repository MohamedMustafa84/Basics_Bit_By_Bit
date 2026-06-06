using System;
using System.Runtime.InteropServices;

public class clsOuterClass {
    public int outerVariale;

    public clsOuterClass(int OuterVariable)
    {
        this.outerVariale = OuterVariable;
    }

    public  void OuterMethod()
    {
        Console.WriteLine( "outer Methos is Called");
    }


    public class clsInnerClass
    {
        public int InnerVariable;

        public clsInnerClass (int InnerVariable)
        {
            this.InnerVariable = InnerVariable;
        }



        public void innerMethod()
        {
            Console.WriteLine("Inner Method is Called");
        }

        public void AcssessOuterVariable(clsOuterClass outer)
        {
            Console.WriteLine(" Access Outer Vartable ({0}) from the Inner Class By Creating Object From the outerClass",outer.outerVariale);
        }
    }


}




// Compostion
// is Design Pattern In OOP  Where a class is composed of Other Objects  and the Object Is Usually Created And Managed By The Class itself 
// in simple word you can create Object of another class from inside your calss


class clsA {

    int x;
    int y; 

    public void Method1()
    {
        Console.WriteLine("Method1 Of class clsA is Called");
    }

        public void Method2()
    {
        Console.WriteLine("Method2 of class CLsA is Called");
        
        Console.WriteLine("Now I will call method1 of class ClSB ...");
        // Compostion
        clsB clsB = new clsB();
        clsB.Method1();




    }

}

class clsB
{

    int x, y;

    public void Method1()
    {
        Console.WriteLine("Hi , Iam the Method1 from Class ClsB :-) ");
    }
}



internal class Program { 

    static  void Main(string[] args)
    {
        Console.WriteLine("Nested Classes : ");

        Console.WriteLine("Outer Calss:");

        clsOuterClass Outer1 = new clsOuterClass(100);
        Console.WriteLine("Outer Variable = {0}",Outer1.outerVariale);
        Outer1.OuterMethod();



        // create an object from InnerClass 

        clsOuterClass.clsInnerClass Inner = new clsOuterClass.clsInnerClass(200);
        
        Console.WriteLine("Inner class :");

        Console.WriteLine("InnerClass Variable = {0}",Inner.InnerVariable);
        Inner.innerMethod();

        Inner.AcssessOuterVariable(Outer1);




        // Composition

        clsA ObjectA1 = new clsA();

        ObjectA1.Method1();

        ObjectA1.Method2();


    }

}
