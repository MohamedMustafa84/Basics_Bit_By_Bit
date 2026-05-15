using System;
using System.Security.Principal;
class clsPerson {

    public int ID { get; set; }
    public string Name { get; set; }
    public short Age { get; set; }

    // Constructor is a method that take the same name of the class and its call when   we create an object fro the class




    // Default Constructor 
    // public clsPerson()
    //{

    //}

    //prameter less constructor
    public clsPerson() { 

        ID = -1;
        Name = "Empty";
        Age = 0;
    }


    // Prameterized Constructor 

    public clsPerson ( string Name, short Age)
    {
        
         ID += 1;
        this.Name = Name;
        this.Age = Age;
    }


     public static clsPerson Find(int ID)
    {
        // we simulate the result for now , later on we will connect to database 
        
        if(ID == 10)
        {
            return new clsPerson("mohamed", 23);
        }
        else
        {
            return null;
        }
    }

    public static clsPerson Find ( int ID ,string Name)
    {

        if(ID == 10)
        {
            return new clsPerson(Name, 23);
        }else
        {
            return null;
        }
    }






    // Destructor :
    // is a method call when  at the end of Object Life
    //  destructor did not take any prameters

    ~clsPerson()
    {
        Console.WriteLine("the Destructor is Called");
    }


}

// Note :
// they are two ways to pervent the programer from creating Object from the class 
// 1- by creating A static Class 
// 2- By Creating A private constructor

static class clsSetting
{
    public static  int  DayNumber
    {
        get
        {
            return DateTime.Today.Day;
        }
    
    
    
    
    }
    public  static string DayName { 
    
        get
        {
              return DateTime.Today.DayOfWeek.ToString();
        }

    }

    public static string  projectPath { get;}


    // private clsSetting()
    //{

    //}


    //static  Constructor is a Constructor  Call Only Once In the Program Life 
    // Static Constructor dose  not take Any Prameters
    static clsSetting()
    {
        projectPath = @"C:MyProjects\";
    }
}

internal class Program { 

      static void Main(string[] args)
    {

        clsPerson Person1 = new clsPerson();


        Console.WriteLine("ID : {0}", Person1.ID);
        Console.WriteLine("Name : {0}",Person1.Name);
        Console.WriteLine("Age : {0}",Person1.Age);


        // Prameterized Constructor

        clsPerson Person2 = new  clsPerson("Mohamed", 23);

        Console.WriteLine("ID : {0}",Person2.ID);
        Console.WriteLine("Name : {0} ", Person2.Name);
        Console.WriteLine("Age :{0}", Person2.Age);




        // Private Constructor vs Static Class

        // You cannot  creating an object here becouse class has  Private Constructor And Coz the class is static 
        //clsSetting Obj1 = new clsSetting();


        Console.WriteLine("Setting Day Number :{0}", clsSetting.DayNumber);
        Console.WriteLine("Setting Day Name :{0}", clsSetting.DayName);

        Console.WriteLine("Project Path :{0}", clsSetting.projectPath);






        Console.WriteLine("Find Person3 By ID ");

        clsPerson Person3 = clsPerson.Find(50);

        if(Person3 != null)
        {
            Console.WriteLine("ID  : {0}",Person3.ID);
            Console.WriteLine("Name: {0}", Person3.Name);
            Console.WriteLine("Age : {0}", Person3.Age);
        }
        else
        {
            Console.WriteLine("Could not find the person by the givin ID ");
        }










    }

}

