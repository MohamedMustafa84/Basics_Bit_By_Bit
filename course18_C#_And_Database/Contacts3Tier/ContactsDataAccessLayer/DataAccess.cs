using System;
using System.Data;
using System.Net;
using Microsoft.Data.SqlClient;


namespace ContactsDataAccessLayer
{
    static public class ContactsDataAccess
    {
        static public bool FindContact(int ID, ref string FirstName, ref string LastName, ref string Email, ref string Phone, ref string Address, ref DateTime DateOFBirth, ref int CountryID, ref string ImagePath)
        {
            bool ISFound = false;

            

            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = "Select * from Contacts where ContactID = @ContactID ";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@ContactID", ID);



            try
            {
                Connection.Open();

                SqlDataReader reader = Command.ExecuteReader();

                while (reader.Read())
                {
                    ISFound = true;
                    FirstName = (string)reader["FirstName"];
                    LastName = (string)reader["LastName"];
                    Email = (string)reader["Email"];
                    Phone = (string)reader["Phone"];
                    Address = (string)reader["Address"];
                    DateOFBirth = (DateTime)reader["DateOfBirth"];
                    CountryID = (int)reader["CountryID"];

                    // handel entity if it null

                    if (reader["ImagePath"] !=DBNull.Value)
                    {
                        ImagePath = (string)reader["ImagePath"];
                    }else
                    {
                        ImagePath = "";
                    }

                }

                reader.Close();


            }
            catch (Exception ex)
            {
                ISFound = false;

            }
            finally
            {
                Connection.Close();
            }

            return ISFound;


        }


        static public int AddNewContact(string FirstName, string LastName,  string Email, string Phone, string Address, DateTime DateOfBirth, int CountryID, string ImagePath)
        {

            int NewContactID = -1;


            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = @"insert into Contacts (FirstName,LastName,Email,Phone,Address,DateOfBirth,CountryID , ImagePath)
                            Values (@FirstName,@LastName,@Email,@Phone,@Address ,@DateOfBirth,@CountryID,@ImagePath);
                               SELECT SCOPE_IDENTITY();";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@FirstName", FirstName);
            Command.Parameters.AddWithValue("@LastName", LastName);
            Command.Parameters.AddWithValue("@Email", Email);
            Command.Parameters.AddWithValue("@Phone", Phone);
            Command.Parameters.AddWithValue("@Address", Address);
            Command.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
            Command.Parameters.AddWithValue("@CountryID", CountryID);



            if(ImagePath != "")
            {
                Command.Parameters.AddWithValue("@ImagePath", ImagePath);

            }
            else
            {
                Command.Parameters.AddWithValue("@ImagePath", System.DBNull.Value);

            }




            try
                {
                    Connection.Open();

                    object Result = Command.ExecuteScalar();

                    if (Result != null && int.TryParse(Result.ToString(), out int InsertedID))
                    {

                        NewContactID = InsertedID;

                    }


                }
                catch (Exception ex)
                {
                    NewContactID = -1;
                    Console.WriteLine($"Sql Error : {ex.Message}");

                }
                finally
                {
                    Connection.Close();
                }

            return NewContactID;


        }


    }
}
