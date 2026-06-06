using System;



public partial class ClsMyClass { 
    
    public  void Method2()
    {
        Console.WriteLine("Method Two Is Called ");
    }

}

public partial class ClsPerson { 

    // the Partial Method Will Be Called once its Implemented if its not implemented the compiler will Ignore it without error :)
    partial void PrintAge()
    {

        Console.WriteLine("The Current Age is {0}",Age);
    }

}