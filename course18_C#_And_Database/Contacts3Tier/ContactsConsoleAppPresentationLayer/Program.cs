using System;
using ContactsBusinessLayer;



internal class Program
{




    public static void PrintContactInfo(ContactsBusinessLayer.ClsContact Contact)
    {

        Console.WriteLine("---------------------------------------------------");
        Console.WriteLine("\t\t Contact Info");
        Console.WriteLine("---------------------------------------------------");

        Console.WriteLine($"Contact ID: {Contact.ID}");
        Console.WriteLine($"First Name : {Contact.FirstName}");
        Console.WriteLine($"Last Name : {Contact.LastName}");
        Console.WriteLine($"Email : {Contact.Email}");
        Console.WriteLine($"Phone : {Contact.Phone}");
        Console.WriteLine($"Address: {Contact.Address}");
        Console.WriteLine($"Country ID : {Contact.CountryID}");
        Console.WriteLine($"Date Of Birth : {Contact.DateOfBirth}");
        Console.WriteLine($"Image Path : {Contact.ImagePath}");

    }

    public static void testFindContact(int id)
    {
        ContactsBusinessLayer.ClsContact Contact = ContactsBusinessLayer.ClsContact.Find(id);
        if (Contact != null)
        {
            PrintContactInfo(Contact);
            return;
        }

        Console.WriteLine("Contact Not Found :(");
    }

    public static void TestAddNewContact()
    {
        ContactsBusinessLayer.ClsContact NewContact =  new ContactsBusinessLayer.ClsContact();

        NewContact.FirstName = "Mohamed";
        NewContact.LastName = "Mustafa";
        NewContact.Email = "mohamedexamplde@gmail.com";
        NewContact.Phone= "0909092425";
        NewContact.Address = "12-khortoum -rmf";
        NewContact.CountryID = 1;
        NewContact.DateOfBirth = new DateTime(2002, 5, 3, 12, 3, 3);
        NewContact.ImagePath= "f:/Images/myPhoto.jpg";
        NewContact.Mode = ClsContact.enMode.AddNew;
        


        if (NewContact.Save())
        {
            Console.WriteLine("Contact Added Successfullly :)");


        }
        else
        {

            Console.WriteLine("Contact not save :(");
        }



    }


    static void Main(string[] args)
    {
        //testFindContact(1);

        TestAddNewContact();

    }

}
