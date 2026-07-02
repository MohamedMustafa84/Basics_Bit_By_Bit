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




    public static void Main()
    {
        //PrintAllContact();

        //FindContactWithFirstName("jane");
        //PrintAllContactsWithFirstNameAndCountryID("jane",2);

        //GetContactsStartWith("j");

        //GetContactsEndWith("e");
        GetContactsFirstNameContain("l");

        Console.ReadKey();
    }











}

