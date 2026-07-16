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

                Console.WriteLine("Error :"+ex.Message);
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



        static public int UpdateContact(int ContactID ,string FirstName, string LastName, string Email, string Phone, string Address, DateTime DateOfBirth, int CountryID, string ImagePath)
        {



            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = @"Update Contacts set
                            FirstName =@FirstName,
                            LastName =@LastName,
                            Email =@Email,
                            Phone =@Phone,
                            Address =@Address,
                            DateOfBirth =@DateOfBirth,
                            CountryID=@CountryID
                                where ContactID = @ContactID";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@ContactID", ContactID);
            Command.Parameters.AddWithValue("@FirstName", FirstName);
            Command.Parameters.AddWithValue("@LastName", LastName);
            Command.Parameters.AddWithValue("@Email", Email);
            Command.Parameters.AddWithValue("@Phone", Phone);
            Command.Parameters.AddWithValue("@Address", Address);
            Command.Parameters.AddWithValue("@DateOfBirth", DateOfBirth);
            Command.Parameters.AddWithValue("@CountryID", CountryID);



            if (ImagePath != "")
            {
                Command.Parameters.AddWithValue("@ImagePath", ImagePath);

            }
            else
            {
                Command.Parameters.AddWithValue("@ImagePath", System.DBNull.Value);

            }


            int RowsEffected = 0;

            try
            {
                Connection.Open();

                RowsEffected = Command.ExecuteNonQuery();


            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return RowsEffected;
            


        }




        static public bool DeleteContact(int ContactID)
        {



            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = @"delete Contacts where ContactID =@ContactID";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@ContactID", ContactID);


            int RowsEffected = 0;

            try
            {
                Connection.Open();

                RowsEffected = Command.ExecuteNonQuery();


            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return (RowsEffected >0);



        }


        static public bool IsExist(int ContactID)
        {

            bool IsFound = false;

            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = @"select found =1 from Contacts where ContactID =@ContactID";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@ContactID", ContactID);



            try
            {
                Connection.Open();

                SqlDataReader reader = Command.ExecuteReader();

                if (reader.HasRows)
                {
                    IsFound = true;
                }

                reader.Close();

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return IsFound;



        }



        static public DataTable GetAllContacts()
        {
            DataTable ContactsTable = new DataTable();  


            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = "select * from Contacts";

            SqlCommand Command = new SqlCommand(query, Connection);




            try
            {
                Connection.Open();

                SqlDataReader reader = Command.ExecuteReader();

                if (reader.HasRows)
                {
                    ContactsTable.Load(reader);
                }
                reader.Close();

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return ContactsTable;



        }




        static public bool FindCountryByID(int ID, ref string CountryName)
        {
            bool ISFound = false;



            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = "Select CountryName from Countries where CountryID = @CountryID ";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@CountryID", ID);



            try
            {
                Connection.Open();

                SqlDataReader reader = Command.ExecuteReader();

                while (reader.Read())
                {
                    ISFound = true;
                    CountryName = (string)reader["CountryName"];
                  
                }

                reader.Close();


            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
                ISFound = false;

            }
            finally
            {
                Connection.Close();
            }

            return ISFound;


        }

        static public bool FindCountryByName(ref int ID, string CountryName)
        {
            bool ISFound = false;



            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = "Select CountryID from Countries where CountryName = @CountryName ";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@CountryName", CountryName);



            try
            {
                Connection.Open();

                SqlDataReader reader = Command.ExecuteReader();

                while (reader.Read())
                {
                    ISFound = true;
                    ID = (int)reader["CountryID"];

                }

                reader.Close();


            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
                ISFound = false;

            }
            finally
            {
                Connection.Close();
            }

            return ISFound;


        }


        static public int AddNewCountry( string CountryName)
        {

            int NewCountryID = -1;


            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = @"insert into Countries (CountryName)
                            Values (@CountryName);
                               SELECT SCOPE_IDENTITY();";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@CountryName", CountryName);





            try
            {
                Connection.Open();

                object Result = Command.ExecuteScalar();

                if (Result != null && int.TryParse(Result.ToString(), out int InsertedID))
                {

                    NewCountryID = InsertedID;

                }


            }
            catch (Exception ex)
            {
                NewCountryID = -1;
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return NewCountryID;


        }




        static public int UpdateCountry( int ID ,string CountryName)
        {
            int EffectedRow = 0;

            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = @"Update Countries set CountryName=@countryName where CountryID=@CountryID";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@CountryID", ID);
            Command.Parameters.AddWithValue("@CountryName", CountryName);





            try
            {
                Connection.Open();

                EffectedRow = Command.ExecuteNonQuery();

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return EffectedRow;


        }


         public static bool DeleteCountry(int ID)
        {
            int EffectedRow = 0;

            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = @"Delete Countries  where CountryID=@CountryID";

            SqlCommand Command = new SqlCommand(query, Connection);

            Command.Parameters.AddWithValue("@CountryID", ID);





            try
            {
                Connection.Open();

                EffectedRow = Command.ExecuteNonQuery();

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return (EffectedRow >0);


        }

        
        public static DataTable GetAllCountries()
        {
            DataTable dtCountries = new DataTable();


            SqlConnection Connection = new SqlConnection(DataAccessSettings.ConnectionString);

            string query = "select * from Countries";

            SqlCommand Command = new SqlCommand(query, Connection);




            try
            {
                Connection.Open();

                SqlDataReader reader = Command.ExecuteReader();

                if (reader.HasRows)
                {
                    dtCountries.Load(reader);
                }
                else
                {
                    dtCountries = null;
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sql Error : {ex.Message}");

            }
            finally
            {
                Connection.Close();
            }

            return dtCountries;

        }

    }




}
