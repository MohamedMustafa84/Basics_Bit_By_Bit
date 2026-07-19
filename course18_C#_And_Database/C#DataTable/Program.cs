using System;
using System.Data;
using System.Linq;

internal class Program
{
    static void Main(string[] args)
    {
        DataTable dtEmployees = new DataTable();

        // Specify the Atrributes

        dtEmployees.Columns.Add("ID", typeof(int));
        dtEmployees.Columns.Add("FirstName", typeof(string));
        dtEmployees.Columns.Add("LastName", typeof(string));
        dtEmployees.Columns.Add("Email", typeof(string));
        dtEmployees.Columns.Add("Address", typeof(string));
        dtEmployees.Columns.Add("Phone", typeof(string));
        dtEmployees.Columns.Add("Salary", typeof(double));
        dtEmployees.Columns.Add("Date", typeof(DateTime));


        // Add Data 

        dtEmployees.Rows.Add(1, "Mohamed", "mustafa", "mohameail.com", "khrto12 st 4t", "9049093335", 10000.00, DateTime.Now);
        dtEmployees.Rows.Add(2, "Maher", "mustafa", "mohamed3ail.com", "khrto12 st 4t", "90490899335", 10500.00, DateTime.Now);
        dtEmployees.Rows.Add(3, "ali", "mustafa", "jkjkmustaf", "khrtoum 12 st", "9049090035", 1000.00, DateTime.Now);
        dtEmployees.Rows.Add(4, "Ahmed", "mustafa", "mohamedml.com", "khrtoum st 4t", "9040903335", 900.00, DateTime.Now);
        dtEmployees.Rows.Add(5, "Modether", "mustafa", "mohama@gmail.com", "koum 12 st 4t", "9049093335", 2000.00, DateTime.Now);
        dtEmployees.Rows.Add(6, "Taha", "mustafa", "mohamedmuil.com", "khrtou2 st 4t", "9049094335", 15000.00, DateTime.Now);
        dtEmployees.Rows.Add(7, "Alshier", "mustafa", "mohamea@gmail.com", "koum 12 st 4t", "9009093335", 14400.00, DateTime.Now);

        // List Employees :

           foreach(DataRow Row in dtEmployees.Rows)
        {
            Console.WriteLine($"ID :{Row["ID"]}  FullName : {Row["FirstName"]} {Row["LastName"]} Phone :{Row["Phone"]}  Email : {Row["Email"]} Address : {Row["Address"]} Salary : {Row["Salary"]} Date : {Row["Date"]}");
        }
    }
}