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
        dtEmployees.Columns.Add("Country", typeof(string));
        dtEmployees.Columns.Add("Salary", typeof(double));
        dtEmployees.Columns.Add("Date", typeof(DateTime));


        // Add Data 

        dtEmployees.Rows.Add(1, "Mohamed", "mustafa", "mohameail.com", "khrto12 st 4t", "9049093335", "Sudan", 10000.00, DateTime.Now);
        dtEmployees.Rows.Add(2, "Maher", "mustafa", "mohamed3ail.com", "khrto12 st 4t", "90490899335", "UK", 10500.00, DateTime.Now);
        dtEmployees.Rows.Add(3, "ali", "mustafa", "jkjkmustaf", "khrtoum 12 st", "9049090035", "Sudan", 1000.00, DateTime.Now);
        dtEmployees.Rows.Add(4, "Ahmed", "mustafa", "mohamedml.com", "khrtoum st 4t", "9040903335", "USA", 900.00, DateTime.Now);
        dtEmployees.Rows.Add(5, "Modether", "mustafa", "mohama@gmail.com", "koum 12 st 4t", "9049093335", "Sudan", 2000.00, DateTime.Now);
        dtEmployees.Rows.Add(6, "Taha", "mustafa", "mohamedmuil.com", "khrtou2 st 4t", "9049094335", "Jordan", 15000.00, DateTime.Now);
        dtEmployees.Rows.Add(7, "Alshier", "mustafa", "mohamea@gmail.com", "koum 12 st 4t", "9009093335", "KSA", 14400.00, DateTime.Now);

        // List Employees :

        Console.WriteLine("Employees List ::-\n");
        foreach (DataRow Row in dtEmployees.Rows)
        {
            Console.WriteLine($"ID :{Row["ID"]}  FullName : {Row["FirstName"]} {Row["LastName"]} Phone :{Row["Phone"]}  Email : {Row["Email"]} Address : {Row["Address"]} Country : {Row["Country"]} Salary : {Row["Salary"]} Date : {Row["Date"]}");
        }

        int EmployeesCount = 0;
        double TotalSalary = 0;
        double AvarageSalasries = 0;
        double MinSalary = 0;
        double MaxSalary = 0;

        EmployeesCount = dtEmployees.Rows.Count;

        TotalSalary = Convert.ToDouble(dtEmployees.Compute("sum(Salary)", string.Empty));
        AvarageSalasries = Convert.ToDouble(dtEmployees.Compute("AVG(Salary)", string.Empty));
        MinSalary = Convert.ToDouble(dtEmployees.Compute("Min(Salary)", string.Empty));
        MaxSalary = Convert.ToDouble(dtEmployees.Compute("Max(Salary)", string.Empty));


        Console.WriteLine("Employees Count = " + EmployeesCount);
        Console.WriteLine("Total Salary = " + TotalSalary);
        Console.WriteLine("Avarage Salasries = " + AvarageSalasries);
        Console.WriteLine("Min Salary  = " + MinSalary);
        Console.WriteLine("Max Salary  = " + MaxSalary);



        // Filter Data 

        // Filter By Country Sudan 

        DataRow[] ResultRows = dtEmployees.Select("Country='Sudan'");

        int ResultCount = 0;

        foreach (DataRow Row in ResultRows)
        {

            Console.WriteLine("Filter Sudanese Employees :-");
            Console.WriteLine($"ID :{Row["ID"]}  FullName : {Row["FirstName"]} {Row["LastName"]} Phone :{Row["Phone"]}  Email : {Row["Email"]} Address : {Row["Address"]} Country : {Row["Country"]} Salary : {Row["Salary"]} Date : {Row["Date"]}");
        }

        ResultCount = ResultRows.Count();

        Console.WriteLine("Sudanese Employee Count is " + ResultCount);

        // filter BY Sudan OR Jordan

        ResultRows = dtEmployees.Select("Country='Sudan' or Country='Jordan'");

            Console.WriteLine("Filter Sudanese and Jordan Employees :-");
        foreach (DataRow Row in ResultRows)
        {

            Console.WriteLine($"ID :{Row["ID"]}  FullName : {Row["FirstName"]} {Row["LastName"]} Phone :{Row["Phone"]}  Email : {Row["Email"]} Address : {Row["Address"]} Country : {Row["Country"]} Salary : {Row["Salary"]} Date : {Row["Date"]}");
        }

        double SudaneseTotalSalary = Convert.ToDouble(dtEmployees.Compute("Sum(Salary)", "Country='Sudan'"));

        Console.WriteLine("Sudanese Employees Total Salary = " + SudaneseTotalSalary);



        // Sort Data 

        dtEmployees.DefaultView.Sort = "ID Desc";
        dtEmployees = dtEmployees.DefaultView.ToTable();


        Console.WriteLine("Sort Employees BY ID Descinding :-");

        foreach (DataRow Row in dtEmployees.Rows)
            {

                Console.WriteLine($"ID :{Row["ID"]}  FullName : {Row["FirstName"]} {Row["LastName"]} Phone :{Row["Phone"]}  Email : {Row["Email"]} Address : {Row["Address"]} Country : {Row["Country"]} Salary : {Row["Salary"]} Date : {Row["Date"]}");
            }


        dtEmployees.DefaultView.Sort = "FirstName Desc";
        dtEmployees = dtEmployees.DefaultView.ToTable();


        Console.WriteLine("Sort Employees BY Firast Name Descinding :-");

        foreach (DataRow Row in dtEmployees.Rows)
        {

            Console.WriteLine($"ID :{Row["ID"]}  FullName : {Row["FirstName"]} {Row["LastName"]} Phone :{Row["Phone"]}  Email : {Row["Email"]} Address : {Row["Address"]} Country : {Row["Country"]} Salary : {Row["Salary"]} Date : {Row["Date"]}");
        }





        // delete Data 

        DataRow[] Result = dtEmployees.Select("ID=4");


        foreach( DataRow record in Result)
        {
            record.Delete();
        }


        //if you contected with the database type the following  line to save The Changes

        //dtEmployees.AcceptChanges();

        dtEmployees.DefaultView.Sort = "ID ASC";
        dtEmployees = dtEmployees.DefaultView.ToTable();


        foreach (DataRow Row in dtEmployees.Rows)
        {
            Console.WriteLine($"ID :{Row["ID"]}  FullName : {Row["FirstName"]} {Row["LastName"]}   Country : {Row["Country"]} Salary : {Row["Salary"]}");

        }


        //  Update DataTable Row 

        DataRow[] SudaneseEmployees = dtEmployees.Select("Country='Sudan'");

        foreach (DataRow Sudani in SudaneseEmployees)
        {
            Sudani["Salary"] = "50000";
        }


        //dtEmployees.AcceptChanges();

        Console.WriteLine("---------------------------------");

        Console.WriteLine("Sudanese Employees After The New Update : \n");

        foreach (DataRow Row in dtEmployees.Rows)
        {
            Console.WriteLine($"  FullName : {Row["FirstName"]} {Row["LastName"]}   Country : {Row["Country"]} Salary : {Row["Salary"]}");

        }



        // Create Datatable With Primary Key 

        DataTable dtStudents = new DataTable();

       


        DataColumn dtColumn = new DataColumn();

        dtColumn.DataType = typeof(int);
        dtColumn.ColumnName = "ID";
        dtColumn.AutoIncrement = true;
        dtColumn.AutoIncrementSeed = 1;
        dtColumn.AutoIncrementStep = 1;
        dtColumn.Caption = "Table Primary Key";
        dtColumn.ReadOnly = false;
        dtColumn.Unique = true;

        dtStudents.Columns.Add(dtColumn);

        dtStudents.Columns.Add("Name", typeof(string));
        dtStudents.Columns.Add("Phone", typeof(string));
        dtStudents.Columns.Add("Address", typeof(string));





        DataColumn[] PrimaryKeysColumns = new DataColumn[1];

        PrimaryKeysColumns[0] = dtStudents.Columns["ID"];

        dtStudents.PrimaryKey = PrimaryKeysColumns;



        dtStudents.Rows.Add(null, "mohamed", "0909099909", null);
        dtStudents.Rows.Add(null, "Ahmed", "0909449909", null);
        dtStudents.Rows.Add(null, "Ali", "066099909", null);


        Console.WriteLine("\n\n\nStudents List : ");

        foreach (DataRow Student in dtStudents.Rows)
        {
            Console.WriteLine($"ID : {Student["ID"]}    \t Name: {Student["Name"]}   \t Phone :{Student["Phone"]}");
        }



    }


}