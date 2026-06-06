using System;
using System.Security.Cryptography;

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







// Implementing Multiple  Interfaces 
 
// In  C# we dont have Multiple Inhertance some People say we can do that using Multiple Interface but than not really Inhertance coz we  rewrite the funtion insted of just using it 

 public interface ICoummunicate {
    
    void CallPhone( string Phone);

    void SendEmail(string Title, string Body);

    void SendSMS(string Title, string Body);
    void SendFax(string Title, string Body);

} 





// Multiple inhertance syntax 

 public  class clsPerson : IPerson, ICoummunicate{
     // From IPerson Interfce
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

    // From Icoummunicate Interface

     public void CallPhone(string Phone)
    {
        Console.WriteLine("Calling  {0}", Phone);
    }

     public void SendEmail(string Title, string Body)
    {
        Console.WriteLine(Title);
        Console.WriteLine(Body);
    }

    public void SendSMS(string Title, string Body)
    {
        Console.WriteLine(Title);
        Console.WriteLine(Body);
    }
    public void SendFax(string Title, string Body)
    {
        Console.WriteLine(Title);
        Console.WriteLine(Body);
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



        // Muliple intefaces


        clsPerson person1 = new clsPerson();

        // from IPerson Interface
        person1.Id = 2;
        person1.FirstName = "Ahmed";
        person1.LastName = "mustafa";
        person1.Interduce();
        person1.Print();


        //From  ICommunicate Interface

        person1.CallPhone("24985775334");
        person1.SendEmail("Hello", "this is the body of the message from send Email Method");
        person1.SendSMS("Hello", "this is message from send SMS method");
        person1.SendFax("Hello", "this is from send fax Methods");





    }

}
