using System;


public  abstract class clsPerson
{
    public string FirstName { get; set; }
    public string LastName { get; set; }

    public abstract void Introduce();

    public void SayGoodBye()
    {
        Console.WriteLine("Good Bye!");
    }

}



public  class clsEmployee : clsPerson {

    public int ID{ get; set; }

    public override  void Introduce()
    {
        Console.WriteLine($"My Name is {FirstName} {LastName} And My Employee ID is {ID}");        

    }


}



internal class Program { 
    static void Main(string[] args)
    {
        // You cannot create An Object of an abstract Class , you can only inherit it 
        //clsPerson Person1 = new clsPerson;

        clsEmployee Employee1 = new clsEmployee();

        Employee1.FirstName = "Mohamed";
        Employee1.LastName = "Mustafa";
        Employee1.ID = 1;
        Employee1.Introduce();
        Employee1.SayGoodBye();


        Console.ReadKey();


    }

}



