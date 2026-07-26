using System;
using System.Linq;
using System.Data;
using Microsoft.Data.SqlClient;

internal class Program
{
    static void Main(string[])
    {
        string ConnectionString = "Server=.;Database=ContactsDB;Integrated Security= True; TrustServerCertificate = True ;";


        // Creat New DataSet 
        DataSet dataSet = new DataSet();

        // Create DataAdapter With A select query and connection String 

        string query = "Select * from Contacts ;";

        DataAdapter dataAdapter = new DataAdapter(query,ConnectionString);











    }
}
