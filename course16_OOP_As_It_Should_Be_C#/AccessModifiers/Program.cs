using System;

namespace AccessModifiers { 
    
    class clsA {
        public int X1 = 10;

        private int X2 = 20;
        protected int X3 = 30;

        public int  Function1()
        {
            return 100;
        }


        private int Function2()
        {
            return 200;
        }

        protected int Function3()
        {
            return 300;
        }
    
    
    }


    class clsB : clsA { 
    
      public int Function4()
        {
            // X1 is public and X3 is protected in the base class so you can Acsess them
            return X1 * X3;
        }

        
    
    }



    internal class Program
    {

        static void Main(string[] args)
        {

            clsA A1 = new clsA();
            Console.WriteLine("All Public Member Are Accessable ");
            Console.WriteLine("X1={0}",A1.X1);
            Console.WriteLine("Result of Funtion1 ={0}", A1.Function1());

            //you can not Access Private members in the folowing Line 
            //Console.WriteLine("X2={0}",A1.X2);


            //you can not Access Private members in the folowing Line 
            //Console.WriteLine("X3={0}",A1.X3);


            //you can not Access Private members in the folowing Line 
            //Console.WriteLine("Result of Funtion2 ={0}", A1.Function2());


            // you can Access the Protected members throw the derive Class 

            clsB B1 = new clsB();

            Console.WriteLine("result of function4 ={0}",B1.Function4());


        }
    }

}

