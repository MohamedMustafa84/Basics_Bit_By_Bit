using System;

namespace AccessModifiers
{
     class clsA {
        public int X1;

        // X2 is shered for all objects  on the class level
        public  static int X2;

        public  int Method1()
        {
            // not static can always access static members 
            return X1 + X2;
        }

        public static int Method2()
        {
            // static method connot access nonstatic members coz they is no object 
            //static methods can call at the class level
            //return clsA.X1 + X2;

            return X2;
        }



    }

    internal class program { 
        
        static void Main(string[] args)
        {
            clsA Obj1 = new clsA();
            clsA Obj2 = new clsA();

            Obj1.X1 = 10;
            Obj2.X1 = 20;

            // X2 is shered  for all Objects becouse it is on the class  level  you can access it using class name 
            clsA.X2 = 30;


            Console.WriteLine("Obj1.X1 ={0}",Obj1.X1);

            Console.WriteLine("Obj2.X1 ={0}", Obj2.X1);

            Console.WriteLine("Obj1.Method1 results={0}", Obj1.Method1());
            Console.WriteLine("Obj2.Method1 results={0}", Obj2.Method1());


            // method2 connot be access through  objects only through the class itself 

            //Console.WriteLine(Obj1.Method2());


            Console.WriteLine("Static method2 result = {0}",clsA.Method2());

            Console.WriteLine("Static X2 ={0}",clsA.X2);





        }

    }


}