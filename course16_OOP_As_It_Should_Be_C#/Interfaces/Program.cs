using System;

//  in C# an interface is similar to abstract class however
//  unlike abstract classes All method of An interface are fully abstract ( methods without body )
public interface IPerson {
    public string FirstName { get; set; }
    public string LastName { get; set; }

    public void Interduce();
    public void Print();

}


public class clsEmployee : IPerson
{
    public string FirstName { get; set; }
    public string LastName { get; set; }

    public int Id { get; set; }

    public void Interduce()
    {
        Console.WriteLine($"Iam {FirstName} {LastName} From Sudan ");
    }

    public void Print()
    {
        Console.WriteLine($"Hi {FirstName} {LastName} my ID is {Id}");
    }
}



internal class Program { 
     static void Main(string[] args) 
    {
        // you cannot create Object from the Interface 
        //IPerson Person = new IPerson();


        clsEmployee Employee1 =new clsEmployee();

        Employee1.Id = 1;
        Employee1.FirstName = "Mohamed";
        Employee1.LastName = "mustafa";

        Employee1.Interduce();
        Employee1.Print();


        
    }

}
