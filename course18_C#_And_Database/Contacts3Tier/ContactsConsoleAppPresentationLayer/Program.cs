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


    static void Main(string[] args)
    {
        testFindContact(1);

    }

}
