using System;
using System;
using System.ComponentModel;
using System.Globalization;
using System.Net;
using Microsoft.Data.SqlClient;






internal class Program{

    static string ConnectionString = "Server=.;Database=ContactsDB;Integrated Security=True;TrustServerCertificate=True"; 

    static  void PrintAllContact()
    {
        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "Select * from Contacts";

        SqlCommand Command = new SqlCommand(query, Connection);

        try
        {
            Connection.Open();
            SqlDataReader reader =  Command.ExecuteReader();  

            while (reader.Read())
            {
                int ContactID = (int)reader["ContactID"];
                string FirstName = (string)reader["FirstName"];
                string LastName = (string)reader["LastName"];
                string Email = (string)reader["Email"];
                string Phone = (string)reader["Phone"];
                string Address = (string)reader["Address"];
                int CountryID = (int)reader["CountryID"];



                Console.WriteLine($"Contact ID :{ContactID}");
                Console.WriteLine($"Name :{FirstName}{LastName}");
                Console.WriteLine($"Email :{Email}");
                Console.WriteLine($"Phone :{Phone}");
                Console.WriteLine($"Address :{Address}");
                Console.WriteLine($"CountryID :{CountryID}");

                Console.WriteLine("--------------------------------------------------------------");




            }
            reader.Close();
            Connection.Close();


        }catch(Exception ex)
        {
            Console.WriteLine("Error : "+ ex.Message);
        }


        


    }



    //Parameterized Query :


    static void FindContactWithFirstName(string FirstName)
    {
        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "SELECT * FROM Contacts WHERE FirstName = @FirstName";

        SqlCommand Command = new SqlCommand(query,Connection);

        Command.Parameters.AddWithValue("@FirstName", FirstName);


        try
        {
            Connection.Open();
            SqlDataReader reader = Command.ExecuteReader();

            while(reader.Read())
            {

                int ContactID = (int)reader["ContactID"];
                string firstName = (string)reader["FirstName"];
                string LastName = (string)reader["LastName"];
                string Email = (string)reader["Email"];
                string Phone = (string)reader["Phone"];
                string Address = (string)reader["Address"];
                int CountryID = (int)reader["CountryID"];



                Console.WriteLine($"Contact ID :{ContactID}");
                Console.WriteLine($"Name :{FirstName}{LastName}");
                Console.WriteLine($"Email :{Email}");
                Console.WriteLine($"Phone :{Phone}");
                Console.WriteLine($"Address :{Address}");
                Console.WriteLine($"CountryID :{CountryID}");

                Console.WriteLine("--------------------------------------------------------------");

            }
            reader.Close();
            Connection.Close();
        }catch (Exception ex)
        {
            Console.WriteLine("Error : "+ ex.Message);
        }

    }

    public  static void PrintAllContactsWithFirstNameAndCountryID (string firstName,int countryID)
    {
        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "select * from Contacts where @FirstName=firstName and @CountryID = countryID";

        SqlCommand Command = new SqlCommand(query,Connection);
        Command.Parameters.AddWithValue("@firstName", firstName);
        Command.Parameters.AddWithValue("@CountryID", countryID);
        
        try
        {
            Connection.Open();
            SqlDataReader reader = Command.ExecuteReader();

            while (reader.Read())
            {

                int ContactID = (int)reader["ContactID"];
                string FirstName = (string)reader["FirstName"];
                string LastName = (string)reader["LastName"];
                string Email = (string)reader["Email"];
                string Phone = (string)reader["Phone"];
                string Address = (string)reader["Address"];
                int CountryID = (int)reader["CountryID"];



                Console.WriteLine($"Contact ID :{ContactID}");
                Console.WriteLine($"Name :{FirstName}{LastName}");
                Console.WriteLine($"Email :{Email}");
                Console.WriteLine($"Phone :{Phone}");
                Console.WriteLine($"Address :{Address}");
                Console.WriteLine($"CountryID :{CountryID}");

                Console.WriteLine("--------------------------------------------------------------");

            }


            reader.Close();
            Connection.Close();

        }catch (Exception ex)
        {
            Console.WriteLine("Error : ",ex.Message);
            
        }
    }



      //--- Parameterized query with " like "
    static void  GetContactsStartWith(string startWith)
    {
        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "select * from Contacts where FirstName like ''+@StartWith +'%'";

        SqlCommand Command = new SqlCommand(query, Connection);

        Command.Parameters.AddWithValue("@StartWith", startWith);

        try
        {
            Connection.Open();

            SqlDataReader reader = Command.ExecuteReader();


            while (reader.Read())
            {

                int ContactID = (int)reader["ContactID"];
                string FirstName = (string)reader["FirstName"];
                string LastName = (string)reader["LastName"];
                string Email = (string)reader["Email"];
                string Phone = (string)reader["Phone"];
                string Address = (string)reader["Address"];
                int CountryID = (int)reader["CountryID"];



                Console.WriteLine($"Contact ID :{ContactID}");
                Console.WriteLine($"Name :{FirstName}{LastName}");
                Console.WriteLine($"Email :{Email}");
                Console.WriteLine($"Phone :{Phone}");
                Console.WriteLine($"Address :{Address}");
                Console.WriteLine($"CountryID :{CountryID}");

            }
            reader.Close();
            Connection.Close();
        }catch(Exception ex)
        {
            Console.WriteLine("Error: "+ ex.Message);
        }


    }






    static void GetContactsEndWith(string endWith)
    {
        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "select * from Contacts where FirstName like '%' +@EndWith +''";

        SqlCommand Command = new SqlCommand(query, Connection);

        Command.Parameters.AddWithValue("@EndWith", endWith);

        try
        {
            Connection.Open();

            SqlDataReader reader = Command.ExecuteReader();


            while (reader.Read())
            {

                int ContactID = (int)reader["ContactID"];
                string FirstName = (string)reader["FirstName"];
                string LastName = (string)reader["LastName"];
                string Email = (string)reader["Email"];
                string Phone = (string)reader["Phone"];
                string Address = (string)reader["Address"];
                int CountryID = (int)reader["CountryID"];



                Console.WriteLine($"Contact ID :{ContactID}");
                Console.WriteLine($"Name :{FirstName}{LastName}");
                Console.WriteLine($"Email :{Email}");
                Console.WriteLine($"Phone :{Phone}");
                Console.WriteLine($"Address :{Address}");
                Console.WriteLine($"CountryID :{CountryID}");

            }
            reader.Close();
            Connection.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }


    }




    static void GetContactsFirstNameContain(string contain)
    {
        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "select * from Contacts where FirstName like '%' +@Contain +'%'";

        SqlCommand Command = new SqlCommand(query, Connection);

        Command.Parameters.AddWithValue("@Contain", contain);

        try
        {
            Connection.Open();

            SqlDataReader reader = Command.ExecuteReader();


            while (reader.Read())
            {

                int ContactID = (int)reader["ContactID"];
                string FirstName = (string)reader["FirstName"];
                string LastName = (string)reader["LastName"];
                string Email = (string)reader["Email"];
                string Phone = (string)reader["Phone"];
                string Address = (string)reader["Address"];
                int CountryID = (int)reader["CountryID"];



                Console.WriteLine($"Contact ID :{ContactID}");
                Console.WriteLine($"Name :{FirstName}{LastName}");
                Console.WriteLine($"Email :{Email}");
                Console.WriteLine($"Phone :{Phone}");
                Console.WriteLine($"Address :{Address}");
                Console.WriteLine($"CountryID :{CountryID}");
                Console.WriteLine();
                Console.WriteLine("----------------------------------------------------------------");

            }
            reader.Close();
            Connection.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }


    }


    // Retrieve Single Value Using ExecuteScalar


    static string  GetFirstName(int contactID)
    {

        string FirstName="";

        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "select  FirstName from Contacts where ContactID = @ContactID";

        SqlCommand Command = new SqlCommand(query, Connection);

        Command.Parameters.AddWithValue("@ContactID", contactID);

        try
        {
            Connection.Open();

            Object Result = Command.ExecuteScalar();



            if(Result != null)
            {
                FirstName = Result.ToString();
            }
            else
            {
                FirstName = " ";
            }

           
            Connection.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }

        return FirstName;


    }


    // Find Single Contact 

    public struct stContact {

         public int ContactID { get; set; }

        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Address { get; set; } 
        public string Email { get; set; }

        public string Phone { get; set; }
        public int CountryID{ get; set; }


    }



    static bool  FindContactByID(int contactID ,ref stContact Contactinfo)
    {
        bool isFound = false;

        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "select * from Contacts where ContactID = @ContactID";

        SqlCommand Command = new SqlCommand(query, Connection);

        Command.Parameters.AddWithValue("@ContactID", contactID);

        try
        {
            Connection.Open();

            SqlDataReader reader = Command.ExecuteReader();


            while (reader.Read())
            {
                isFound= true;

                Contactinfo.ContactID = (int)reader["ContactID"];
                Contactinfo.FirstName = (string)reader["FirstName"];
                Contactinfo.LastName = (string)reader["LastName"];
                Contactinfo.Email = (string)reader["Email"];
                Contactinfo.Phone = (string)reader["Phone"];
                Contactinfo.Address = (string)reader["Address"];
                Contactinfo.CountryID = (int)reader["CountryID"];



            }
            reader.Close();
            Connection.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }

        return isFound;

    }

    public static void PrintContactInfo(stContact ContactInfo)
    {
        Console.WriteLine("-------------------------- Contact Info-------------------------");
        Console.WriteLine($"Contact ID  : {ContactInfo.ContactID}");
        Console.WriteLine($"First Name  : {ContactInfo.FirstName}");
        Console.WriteLine($"Last Name  : {ContactInfo.LastName}");
        Console.WriteLine($"Email  : {ContactInfo.Email}");
        Console.WriteLine($"Phone  : {ContactInfo.Phone}");
        Console.WriteLine($"Address : {ContactInfo.Address}");
        Console.WriteLine($"County ID  : {ContactInfo.CountryID}");
    }





    // insert Add data to the database


    static void AddNewContactAndGetContactID (stContact newContactInfo)
    {
        SqlConnection Connection = new SqlConnection(ConnectionString);

        string query = "insert into Contacts (FirstName,LastName,Email,Phone,Address,CountryID)   values (@FirstName,@LastName,@Email,@Phone,@Address,@CountryID); select SCOPE_IDENTITY()";

        SqlCommand Command = new SqlCommand(query, Connection);

        Command.Parameters.AddWithValue("@FirstName", newContactInfo.FirstName);
        Command.Parameters.AddWithValue("@LastName", newContactInfo.LastName);
        Command.Parameters.AddWithValue("@Email", newContactInfo.Email);
        Command.Parameters.AddWithValue("@Phone", newContactInfo.Phone);
        Command.Parameters.AddWithValue("@Address", newContactInfo.Address);
        Command.Parameters.AddWithValue("@CountryID", newContactInfo.CountryID);

        try
        {
            Connection.Open();

            object result= Command.ExecuteScalar();


             if (result!=null && int.TryParse(result.ToString(),out int InsertedID) )
            {
                Console.WriteLine($"Newly Inserted ID : {InsertedID}");
            } else
            {
                Console.WriteLine("add new Contact is Faield :(");

            }

          
            Connection.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }


    }




    public static void Main()
    {
        //PrintAllContact();

        //FindContactWithFirstName("jane");
        //PrintAllContactsWithFirstNameAndCountryID("jane",2);

        //GetContactsStartWith("j");

        //GetContactsEndWith("e");


        //GetContactsFirstNameContain("l");


        //Console.WriteLine("the first Name is " + GetFirstName(4));


        // Get single Contact 

        //stContact ContactInfo = new stContact { };

        
        //if (FindContactByID(3,ref ContactInfo))
        //{
        //    PrintContactInfo(ContactInfo);
        //}
        //else
        //{
        //    Console.WriteLine("the contact is not found");
        //}




        //  Insert Add data to the database

        stContact NewContact = new stContact
        {
            FirstName = "Ali",
            LastName = "mustafa",
            Email = "example@gamil.com",
            Phone = "113322343",
            Address = "khrtoum 12 str",
            CountryID = 2

        };

        AddNewContactAndGetContactID(NewContact);








        Console.ReadKey();
    }











}

