using System;


class clsPerson
{
    public int Id { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Title{ get; set; }

    
    public string FullName()
    {
        return FirstName + " "+LastName;
    }
}


// Employee inherit person 


class clsEmployee : clsPerson {

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

        clsEmployee Employee1 = new clsEmployee();

        Employee1.Id = 1;
        Employee1.FirstName = "Mohamed";
        Employee1.LastName = "Mustafa";
        Employee1.Title = "Backend developer";
        Employee1.Salary = 10000;

        // here you can acces clsperson public members  Only

        Console.WriteLine("Employee ID  :{0}",Employee1.Id);
        Console.WriteLine("Employee Full Name  :{0}",Employee1.FullName());
        Console.WriteLine("Employee Job Title  :{0}",Employee1.jobTitle);
        Console.WriteLine("Employee Salary     :{0}", Employee1.Salary);

        Employee1.IncreaseSalaryBy(100);

        Console.WriteLine("Salary After increased By 100 Usd : {0} Usd",Employee1.Salary);



    }
}