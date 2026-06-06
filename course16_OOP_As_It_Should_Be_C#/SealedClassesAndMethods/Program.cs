using System;



// when we dont want a class to be inherited we declare it as sealed class using keyword sealed
 sealed public class clsA {
    int x, y;

    public void Method1()
    {
        Console.WriteLine("iam the method one from the sealed class");
    }

}

// the folowing code will give you an error becouse you trying to Inherit sealed class

// public class clsB : clsA
//{

//}



//Sealed Method :
 //using  method overriding if we dont want an overridden method to be further overridden by anthoer class we can declare it as Sealed method .

 public class  clsPerosn { 
     
    public virtual void Greet()
    {
        Console.WriteLine("Person Creat You");
    }


}

public class clsEmployee : clsPerosn {
    
    public sealed  override void Greet()
    {
        Console.WriteLine("Employee Great you ");
    }
}


public class clsManeger : clsEmployee{

    // the folowing code will preduce compile time error becouse the greet method in the employee is sealed

    //public sealed override void Greet()
    //{
    //    Console.WriteLine("Employee Great you ");
    //}
}
