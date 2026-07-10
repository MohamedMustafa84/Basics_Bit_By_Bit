using System;
using System.Data;
using System.Net;
using Microsoft.SqlServer.Server;

using System.Data.SqlClient;

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
                    ImagePath = (string)reader["ImagePath"];

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





    }
}
