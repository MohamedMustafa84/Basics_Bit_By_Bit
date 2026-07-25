using System;
using System.Linq;
using System.Data;
using System.Runtime.InteropServices;




internal class Program
{

    static void Main(string[] args)
    {


        DataTable dtTeachers = new DataTable();

        DataColumn Id = new DataColumn();

        Id.ColumnName = "ID";
        Id.DataType = typeof(int);
        Id.AutoIncrement = true;
        Id.AutoIncrementSeed = 1;
        Id.AutoIncrementStep = 1;
        Id.Unique = true;

        dtTeachers.Columns.Add(Id);

        dtTeachers.Columns.Add("Name", typeof(string));
        dtTeachers.Columns.Add("Phone", typeof(string));
        dtTeachers.Columns.Add("Salary", typeof(double));


        DataColumn[] PrimaryKeyColumns = new DataColumn[1];
        PrimaryKeyColumns[0] = dtTeachers.Columns["ID"];

        dtTeachers.PrimaryKey = PrimaryKeyColumns;


        dtTeachers.Rows.Add(null, "Mohamed", "0909998988", 10000);
        dtTeachers.Rows.Add(null, "Ahmed", "0909998988", 1000);
        dtTeachers.Rows.Add(null, "Modather", "0909998988", 100);
        dtTeachers.Rows.Add(null, "ali", "0909998988", 10000);





        DataTable dtStudents = new DataTable();

        DataColumn StudentsId = new DataColumn();

        StudentsId.ColumnName = "ID";
        StudentsId.DataType = typeof(int);
        StudentsId.AutoIncrement = true;
        StudentsId.AutoIncrementSeed = 1;
        StudentsId.AutoIncrementStep = 1;
        StudentsId.Unique = true;

        dtStudents.Columns.Add(StudentsId);

        dtStudents.Columns.Add("Name", typeof(string));
        dtStudents.Columns.Add("Phone", typeof(string));


        DataColumn[] StudentsPrimaryKeyColumns = new DataColumn[1];
        StudentsPrimaryKeyColumns[0] = dtStudents.Columns["ID"];

        dtStudents.PrimaryKey = StudentsPrimaryKeyColumns;


        dtStudents.Rows.Add(null, "Osama", "0909998988");
        dtStudents.Rows.Add(null, "Sayeed", "0909998988");
        dtStudents.Rows.Add(null, "Maher", "0909998988");
        dtStudents.Rows.Add(null, "Osman", "0909998988");


        Console.WriteLine("\nTeachers Info :");

        foreach (DataRow Teacher in dtTeachers.Rows)
        {
            Console.WriteLine($"ID : {Teacher["ID"]} \t Name : {Teacher["Name"]}  \t  Phone : {Teacher["Phone"]}  Salary : {Teacher["Salary"]}");
        }


        Console.WriteLine("------------------------------------------------------");

        Console.WriteLine("\nStudents Info :");

        foreach (DataRow Student in dtStudents.Rows)
        {
            Console.WriteLine($"ID : {Student["ID"]} \t Name : {Student["Name"]}  \t  Phone : {Student["Phone"]}");
        }





        // DataSet : Contain Many DataTable Its Like Local Copy Of the DataBase 

        //Create DataSet 

        DataSet dataSet1 = new DataSet();

        dataSet1.Tables.Add(dtTeachers);
        dataSet1.Tables.Add(dtStudents);



        Console.WriteLine("---------------------------------------------------\n\n");
        Console.WriteLine("Printing Teachers Data From The Data Set :-\n");



        foreach (DataRow Teacher in dataSet1.Tables[0].Rows)
        {
            Console.WriteLine($"ID : {Teacher["ID"]} \t Name : {Teacher["Name"]}  \t  Phone : {Teacher["Phone"]}  Salary : {Teacher["Salary"]}");
        }





        Console.WriteLine("---------------------------------------------------\n\n");
        Console.WriteLine("Printing Students Data From The Data Set :-\n");

        foreach (DataRow Student in dataSet1.Tables[1].Rows)
        {
            Console.WriteLine($"ID : {Student["ID"]} \t Name : {Student["Name"]}  \t  Phone : {Student["Phone"]}");
        }





    }





}