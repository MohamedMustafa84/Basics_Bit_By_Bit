using System;
using System.Collections.Specialized;
using System.Data;
using System.Reflection.Metadata.Ecma335;
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
        Console.WriteLine("---------------------------------------------------");

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


    public static void TestUpdateContact(int ContactID)
    {


        ClsContact Contact = ClsContact.Find(ContactID);

        if(Contact != null)
        {
            Contact.FirstName = "Mohamed";
            Contact.LastName = "Mustafa";
            Contact.Email = "mohamedexamplde@gmail.com";
            Contact.Phone = "0909092425";
            Contact.Address = "12-khortoum -rmf";
            Contact.CountryID = 1;
            Contact.DateOfBirth = new DateTime(2002, 5, 3, 12, 3, 3);
            Contact.ImagePath = "f:/Images/myPhoto.jpg";
            Contact.Mode = ClsContact.enMode.Update;



            if (Contact.Save())
            {
                Console.WriteLine("Contact Updated Successfullly :)");


            }
            else
            {

                Console.WriteLine($"Erorr while Updating Contact with ID {ContactID}");
            }
            return;

        }
        else
        {
            Console.WriteLine($"Contact With ID {ContactID} Not Found :(");
        }

        



    }


     public static void TestDeleteContact(int ID)
    {

        if (ClsContact.ISContactExist(ID))
        {
            if (ClsContact.DeleteContact(ID))
            {
                Console.WriteLine("Contact Deleted Succssfully :)");
            }
            else
            {
                Console.WriteLine("the Deletion Operation Faild :(");
            }
        }
        else
        {
            Console.WriteLine($"Contact With ID {ID} Not Found ");
        }


        

    }


     public static void TestGetAllContacts()
    {
        DataTable ContactsTable = ClsContact.GetContactsList();

        if(ContactsTable != null)
        {
            Console.WriteLine("ContactID \t| FirstName\t | LastName\t| Email\t\t | Phone\t\t| DateOFBirth \t\t |CountryID ");



            foreach(DataRow Row in ContactsTable.Rows)
            {
                Console.WriteLine($"{Row["ContactID"]} \t \t| {Row["FirstName"]}\t |{Row["LastName"]}\t | {Row["Email"]}\t\t | {Row["Phone"]}\t\t | {Row["DateOFBirth"]}\t\t | {Row["CountryID"]}");
            }
        }
        else
        {
            Console.WriteLine("Erorr while Getting the Data ");
        }

    }



     public static void TestContactExistance(int ID)
    {
        if (ClsContact.ISContactExist(ID))
        {
            Console.WriteLine($"Contact with ID {ID} Is Exist ");
        }
        else
        {
            Console.WriteLine($"Contact With ID {ID} Not Found ");
        }
    }


    public static void TestFindCountryByID(int ID)
    {
        ClsContact.clsCountries Country = ClsContact.clsCountries.FindCountryByID(ID);

        if (Country != null)
        {
            Console.WriteLine($"the Country with ID {ID} Is {Country.CountryName}");
        }
        else
        {
            Console.WriteLine($"Counttry With ID {ID} Not Found ");
        }
    }

    public static void TestFindCountryByName(string CountryName)
    {
        int CountryID = ClsContact.clsCountries.FindCountryByName(CountryName);

        if (CountryID>0)
        {
            Console.WriteLine($"the  ID for {CountryName} is {CountryID}" );
        }
        else
        {
            Console.WriteLine($"they is no country with the Name {CountryName} is the Database");
        }

    }

    public static void TestAddNewCountry(string CountryName)
    {

        if (ClsContact.clsCountries.FindCountryByName(CountryName) <1)
        {

            ClsContact.clsCountries Country = new ClsContact.clsCountries();

            Country.CountryName = "Sudan";
            Country.eMode = ClsContact.clsCountries.enMode.AddNew;

            if (Country.Save())
            {
                Console.WriteLine($"Country {Country.CountryName} Added Successfully :) ");

            }
            else
            {
                Console.WriteLine($"unable to add Country {Country.CountryName} :(");
            }
        }
        else
        {
            Console.WriteLine("this Country is Already Exist :) ");
        }

    }

    public static void TestUpdateCountry(int CountryID ,string CountryName)
    {



        ClsContact.clsCountries Country = ClsContact.clsCountries.FindCountryByID(CountryID);


        if(Country != null)
        {
            Country.CountryName = CountryName;

            if (Country.Save())
            {
                Console.WriteLine("Country Updated Successfully :)");
            }
            else
            {
                Console.WriteLine("Unable To Save the Update :(");
            }
        }
        else
        {
            Console.WriteLine($"Coutry with ID {CountryID} is not Found :(");
        }
    }



    public static void TestDeleteCountry(int ID)
    {
        if (ClsContact.clsCountries.DeleteCountry(ID))
        {
            Console.WriteLine("Country Deleted Succssfully :)");
        }
        else
        {
            Console.WriteLine($"Unable To Delete Country With ID {ID} :(");
        }
    }



    public static void TestGetAllCountries()
    {
        DataTable CountriesTable = ClsContact.clsCountries.GetAllCountries();

        if(CountriesTable != null)
        {
            Console.WriteLine("CountryID        countryName");

            foreach (DataRow Row in CountriesTable.Rows)
            {
                Console.WriteLine("   " + Row[0].ToString() +"               " + Row[1]  );
            }
        }
    }
    static void Main(string[] args)
    {
        //testFindContact(2);

        //TestAddNewContact();

        //TestUpdateContact(2);

        //TestDeleteContact(16);

        //TestGetAllContacts();

        //TestContactExistance(1);




        //TestFindCountryByID(6);
        //TestFindCountryByName("Sudan");

        //TestAddNewCountry("Sudan");

        //TestUpdateCountry(6,"Sudan");


        TestDeleteCountry(8);

        TestGetAllCountries();

    }

}
