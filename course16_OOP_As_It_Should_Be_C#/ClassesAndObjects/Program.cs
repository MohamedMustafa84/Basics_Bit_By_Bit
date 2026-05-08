using System;

namespace OOP_C_
{


    class clsPerson
    {

        //fileds
        public string FirstName;
        public string LastName;

        //Method 
        public string FullName()
        {
            return FirstName + " " + LastName;
        }
    }


    internal class program
    {
        static void Main(string[] args)
        {
            // Create Object From Class 
            clsPerson Person1 = new clsPerson();

            Console.WriteLine("Access Object One (Person1) :");
            Person1.FirstName = "Mohamed";
            Person1.LastName = "Mustafa";
            Console.WriteLine(Person1.FullName());

            //Create Another Object From Class 

            clsPerson Person2;
            Person2 = new clsPerson();

            Console.WriteLine("Access Object Two Person two (Person2) :");

            Person2.FirstName = "Ali";
            Person2.LastName = "Maher";

            Console.WriteLine(Person2.FullName());

            // Objects In Memory 

            // Eatch Instance Has its Own Space In Memory Only Member Functions Are Shared Among All Objects





        }
    }
}
