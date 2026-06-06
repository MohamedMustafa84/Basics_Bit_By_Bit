using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;




public class clsEmployee
{

    public string Name;
}

public struct stEmployee {
    public string Name;

}


internal class Program { 

    static void Main(string[] args)
    {
        // Class Vs Struct :


        //-----------------------------------------------------------------------------------------------------------------------------------
        // 1- class is reference type whereas a struct is a value type 
        // for Example:

            
           clsEmployee Emp1= new clsEmployee();
           Emp1.Name ="mohamed";

           clsEmployee Emp2 = new clsEmployee();

        // assign Emp1 to Emp2
            Emp2 = Emp1;
            Emp2.Name = "Ali";

            Console.WriteLine("Employee1 name : {0}",Emp1.Name); //Output : Employee1 name : Ali

        // the above Example we have assigned the value of Emp1 to Emp2  the Emp2 object refers to teh same Emp1 object  so an update in emp2
        // update Emp1 automatically 

        // this why classes is reference type 

        // contrary  to classes when we assigned one struct variable to another  the value of the struct  gets copied to assigned variable 
        // so  update one struct variable does not effect the other 

        // for Example :

        stEmployee Employee1 = new stEmployee();
        Employee1.Name = "Mohamed";

        stEmployee Employee2 = new stEmployee();

        // assign Employee1 to Employee2

        Employee1 = Employee2;

        Employee1.Name= "Ali";

        Console.WriteLine("Employee1 Name : {0}",Employee1); // output : Employee1 Name : Mohamed 

        // when we assigned the value of Employee1 to Employee2 a new value Employee2 is created  
        // here the value of Employee1 is copied  to Employee2  so change in Employee2 does not effect Employee1


        //-----------------------------------------------------------------------------------------------------------------------------------
        // 2- Inhertance is not passible in the struct whereas its is an important feature of the C# classes


        //-----------------------------------------------------------------------------------------------------------------------------------
        // 3- default Constructors :
        // classes have a default  constructor that aoutomaticlly provided by the compiler if a constructor is not explicitly defined 
        // structure on the other hand do not have a default constructor  and require all fields to  be initialized explicitly



        //-----------------------------------------------------------------------------------------------------------------------------------
        //4- Preformance : 
        // Structure are genarally faster than classes  for small simple type as they are stored on the stack  rather than the heap
        //  this means the access and manipulating structure fields can be faster than classes fields


        //-----------------------------------------------------------------------------------------------------------------------------------
            //5- Memory Manegment : 
                // since structure are value type they are allocated on teh stack  which is lemited resourses while classes are allocated on the heap
                //which is larger more flexible memory pool this means using too many  structure or larger structure  can quickly consume the available
                // stack cousing stack overflow error





    }




}



