using System;


 public class clsPerson
{
    public int Id { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }


     public clsPerson (int ID , string FirstName, string LastName)
    {
        Id = ID ;
        this.FirstName = FirstName;
        this.LastName = LastName;
    }

    
    public string FullName()
    {
        return FirstName + " "+LastName;
    }
}


// Employee inherit person 


  class clsEmployee : clsPerson {



    public clsEmployee (int ID ,string FirstName, string LastName , float Salary, string JobTitle) : base(ID, FirstName, LastName)
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

        clsEmployee Employee2 = new clsEmployee(1,"Mohamed","Mustafa",10000,"Backend Developer");


        Console.WriteLine("Employee ID  :{0}", Employee2.Id);
        Console.WriteLine("Employee Full Name  :{0}", Employee2.FullName());
        Console.WriteLine("Employee Job Title  :{0}", Employee2.jobTitle);
        Console.WriteLine("Employee Salary     :{0}", Employee2.Salary);

        Employee2.IncreaseSalaryBy(100);

        Console.WriteLine("Salary After increased By 100 Usd : {0} Usd", Employee2.Salary);



    }
}