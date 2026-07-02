using System;
using System;
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



    public static void Main()
    {
        //PrintAllContact();

        //FindContactWithFirstName("jane");
        PrintAllContactsWithFirstNameAndCountryID("jane",2);

        Console.ReadKey();
    }











}

