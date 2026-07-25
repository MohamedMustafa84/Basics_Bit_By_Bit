using System;
using System.Linq;
using System.Data;



internal class Program
{

    static void Main(string[] args)
    {
        //  DataView :
        //  represent Data Bindable,Customized View of Data Table For Sorting ,Filtring ,Searching And Navigation

        DataTable dtEmployees = new DataTable();

        DataColumn Id = new DataColumn();

        Id.ColumnName = "ID";
        Id.DataType = typeof(int);
        Id.AutoIncrement = true;
        Id.AutoIncrementSeed = 1;
        Id.AutoIncrementStep = 1;
        Id.Unique = true;

        dtEmployees.Columns.Add(Id);

        dtEmployees.Columns.Add("Name",typeof(string));
        dtEmployees.Columns.Add("Phone",typeof(string));
        dtEmployees.Columns.Add("Salary",typeof(double));


        DataColumn[] PrimaryKeyColumns = new DataColumn[1];
        PrimaryKeyColumns[0] = dtEmployees.Columns["ID"];

        dtEmployees.PrimaryKey = PrimaryKeyColumns;


        dtEmployees.Rows.Add(null, "Mohamed", "0909998988", 10000);
        dtEmployees.Rows.Add(null, "Ahmed", "0909998988", 1000);
        dtEmployees.Rows.Add(null, "Modather", "0909998988", 100);
        dtEmployees.Rows.Add(null, "ali", "0909998988", 10000);



        foreach(DataRow Employee in dtEmployees.Rows)
        {
            Console.WriteLine($" ID : {Employee["ID"]}  \t Name : {Employee["Name"]} \t Phone : {Employee["Phone"]} \t Salary : {Employee["Salary"]}");
        }

        // Create DataView

        //DataView dataView1 = new DataView(dtEmployees);

        DataView dataView1 = new DataView();

        dataView1 = dtEmployees.DefaultView;



        Console.WriteLine("\t Data View Content :-");

        for (int i=0; i<dataView1.Count; i++)
        {
            Console.WriteLine($" ID : {dataView1[i][0]}  \t Name : {dataView1[i][1]} \t Phone :  {dataView1[i][2]} \t Salary : {dataView1[i][1]}");

        }


        // Filtering Data in DataView 


        dataView1.RowFilter = "Salary =10000";

        Console.WriteLine("Employees With The Salary 10000 :");

        for (int i = 0; i < dataView1.Count; i++)
        {
            Console.WriteLine($" ID : {dataView1[i][0]}  \t Name : {dataView1[i][1]} \t Phone :  {dataView1[i][2]} \t Salary : {dataView1[i][3]}");

        }


        // Sorting DataView  


        dataView1.Sort = "Name Asc";


        Console.WriteLine("\n\n\nDataVeiw Sorted By Name ASC :");
        

        for (int i = 0; i < dataView1.Count; i++)
        {
            Console.WriteLine($" ID : {dataView1[i][0]}  \t Name : {dataView1[i][1]} \t Phone :  {dataView1[i][2]} \t Salary : {dataView1[i][3]}");

        }


    }



}
