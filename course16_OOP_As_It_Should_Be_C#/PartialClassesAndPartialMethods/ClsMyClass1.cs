using System;


public partial class ClsMyClass { 

    public  void Method1()
    {
        Console.WriteLine("Method One Is Called");
    }

}



public  partial class ClsPerson { 

    public short Age { get; set; }

    // Partial Method
    partial void PrintAge();

    public void BirthDay()
    {
        Age++;
        // if PrintAge Is Impelemented it will be Called OtherWise it will Ignore 
        PrintAge();
    }
}
