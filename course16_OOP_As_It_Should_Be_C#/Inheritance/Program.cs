using System;
using System.Data;


public class clsPerson
{
    public int Id { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public short  Age { get; set; }


    public clsPerson (int ID , string FirstName, string LastName,short Age)
    {
        Id = ID ;
        this.FirstName = FirstName;
        this.LastName = LastName;
        this.Age = Age;
    }

    
    public string FullName()
    {
        return FirstName + " "+LastName;
    }

    public void Great()
    {
        Console.WriteLine("Hi MY Name Is {0} Iam {1} Years Old", FullName(), Age);
    }
}


// Employee inherit person 


  class clsEmployee : clsPerson {



    public clsEmployee (int ID ,string FirstName, string LastName ,short Age, float Salary, string JobTitle) : base(ID, FirstName, LastName,Age)
    {
        jobTitle = JobTitle;
        this.Salary = Salary;

    }

// here you can access the Public and Protected Members only  from the class clsPerson
    public float  Salary { get; set; }
    public string  jobTitle { get; set; }


    public void IncreaseSalaryBy(float amount)
    {
        Salary += amount;
    }

    public void Work()
    {
        Console.WriteLine("I Work At XYZ Crop And Earn {0} per Year",Salary);
    }

}




// Methods Override And Methods Shadowing

class clsMyBaseClass {
    // To Override Method  you have to  make it  A virtual 

    public  virtual void Print()
    {
        Console.WriteLine("Hi , iam the  print method from the base class (BaseClass) ");
    }

    public virtual void MyOtherMethod()
    {
        Console.WriteLine("Base class Implementaion of MyOtherMethod");
    }
}


class clsMYDerivedClass : clsMyBaseClass
{
    // we use the override key word to override  the methods
    public override  void Print()
    {
        Console.WriteLine("Hi , iam the  print method from the derived class  ");

        //we use base keyword  to Access the Base class Method  from the Derived class
        base.Print();


      
    }
    
    
    // We use new keyword to Shadow the Methods
    public new void MyOtherMethod()
    {
        Console.WriteLine("Derive Class implementation of the Shadwing Method (MyOtherMethod ");
    }


}





internal class Program
{
    static void Main(string[] args)
    {

        //clsEmployee Employee1 = new clsEmployee();


        //Employee1.Id = 1;
        //Employee1.FirstName = "Mohamed";
        //Employee1.LastName = "Mustafa";
        //Employee1.Title = "Backend developer";
        //Employee1.Salary = 10000;

        //// here you can acces clsperson public members  Only

        //Console.WriteLine("Employee ID  :{0}",Employee1.Id);
        //Console.WriteLine("Employee Full Name  :{0}",Employee1.FullName());
        //Console.WriteLine("Employee Job Title  :{0}",Employee1.jobTitle);
        //Console.WriteLine("Employee Salary     :{0}", Employee1.Salary);

        //Employee1.IncreaseSalaryBy(100);

        //Console.WriteLine("Salary After increased By 100 Usd : {0} Usd",Employee1.Salary);




        //----------------

        // inhertiance with the constructors 

        //clsEmployee Employee2 = new clsEmployee(1,"Mohamed","Mustafa",23,10000, "Backend Developer");


        //Console.WriteLine("Employee ID  :{0}", Employee2.Id);
        //Console.WriteLine("Employee Full Name  :{0}", Employee2.FullName());
        //Console.WriteLine("Employee Job Title  :{0}", Employee2.jobTitle);
        //Console.WriteLine("Employee Salary     :{0}", Employee2.Salary);
        //Console.WriteLine("Employee Age     :{0}", Employee2.Age);

        //Employee2.IncreaseSalaryBy(100);

        //Console.WriteLine("Salary After increased By 100 Usd : {0} Usd", Employee2.Salary);




        //---------------------------------------------------

        // Upcasting And DownCasting 

        clsEmployee Employee1 = new clsEmployee(3, "Mohamed", "Mustafa", 23, 20000, "Backend");

        clsPerson Person1 = Employee1;

        Person1.Great();


        //Downcasting

        clsPerson Person2 = new clsEmployee(4, "Ali", "Mustafa", 23, 20000, "Backend");
        clsEmployee Employee3 = (clsEmployee)Person2; // this is save downcasting coz Person2 come from Employee class 

        Employee3.Work();



        // invalid  casting throw InvalidCastingExeption at runtime 

        //clsPerson person3 = new clsPerson(1, "mohamed", "mustafa", 23);
        //clsEmployee Employee4 =(clsEmployee) person3; //this is unsave downcasting coz the person3 did not have Salary And JobTitle






        //  Method Method override 

        clsMyBaseClass BaseOpj = new clsMyBaseClass();

        Console.WriteLine("Base Object :");

        BaseOpj.Print();
        BaseOpj.MyOtherMethod();


        Console.WriteLine("Derived Object :");

        clsMYDerivedClass DerivedObj = new clsMYDerivedClass();

        DerivedObj.Print();
        DerivedObj.MyOtherMethod();




        // Methods Override vs Methods Shadowing 
        // the main deferent is when We Upcast the class  override will override the base class method but the shadwing Method will not 

        // Casting :
        clsMyBaseClass MyDerivedObjectAsBase = DerivedObj;

        Console.WriteLine("After Casting :");
        MyDerivedObjectAsBase.Print(); // Output : Hi , iam the  print method from the derived class 
        MyDerivedObjectAsBase.MyOtherMethod(); // Output : Base class Implementaion of MyOtherMethod








    }
}