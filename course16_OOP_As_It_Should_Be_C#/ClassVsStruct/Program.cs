using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;




public class clsEmployee
{

    public string Name;
}


internal class Program { 

    static void Main(string[] args)
    {
        // Class Vs Struct :

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
        // 








    }




}



