#include <iostream>
using namespace std;



int readPositiveNumber(string massege){
    int number;
    cout << massege << endl;
    cin >> number;
    while(number<=0){
        cout << " the number most be greter than zero please retry -->";
        cin >> number;
        cout << endl;
    }
    
    return number;
}




int readNumberInRange(int from, int to ){
    int number ;
    cout << " enter a number btween " << from << " - " << to << "-->";
    cin >> number;
    cout << endl;
    while ((number < from) || (number > to))
    {
        cout << " the number must be btween " << from << " - " << to << "-->";
        cin >> number;
        cout << endl;
    };
    return number;
}


// ----------------- 31 ---------------------



struct stPowerOfNum
{
    int powFor2;
    int powFor3;
    int powFor4;
};

stPowerOfNum calculateNumberPower2_3_4(int number ){
    stPowerOfNum power;
    power.powFor2 = number * number;
    power.powFor3 = power.powFor2 * number;
    power.powFor4 = power.powFor3 * number;
    return power;
}
void printNumberPower(stPowerOfNum power,int number){
    cout << "the power of " << number << " to 2 is " << power.powFor2 << endl;
    cout << "the power of " << number << " to 3 is " << power.powFor3 << endl;
    cout << "the power of " << number << " to 4 is " << power.powFor4 << endl;

}
// ----------------- 32 ---------------------
int clculateNumberPower(int number, int power){
    int numberAfterPower=1;
    for (int i = 1; i <= power; i++)
    {
        numberAfterPower *= number;
    }
    return numberAfterPower;
}

    void printTheResult(int number , int power,int powerOfNumber){
        cout << " the power of " << number << " to " << power << " is " << powerOfNumber << endl;
    }

    // ----------------- 33 ---------------------
     char claculateStudantResult(int grade){
        
        if(grade>=90){
            
            return 'A';
        }
        else if (grade>= 80 && grade <= 89){

            return 'B';
        }
        else if (grade >= 70 && grade <= 79)
        {

            return 'C';
        }
        else if (grade >= 80 && grade <= 89)
        {

            return 'B';
        }
        else if (grade >= 60 && grade <= 69)
        {

            return 'D';
        }
        else if (grade >= 50 && grade <= 59)
        {

            return 'E';
        }else{
            return 'F';
        }

    }
    void printTheResult(char result ){
         cout << " your Result based on your grade is " << result << endl;
     }

     // ----------------- 34 ---------------------
     float getComtionPercantage(int totalSalces)
     {
         if (totalSalces >= 1000000)
         {
             return 0.01;
         }
         else if (totalSalces >= 500000)
         {
             return 0.02;
         }
         else if (totalSalces >= 50000)
         {
             return 0.03;
         }
         else
         {
             return 0.00;
         }
     }
     float clculateTotalComtion(float Percantage, float totalSalces)
     {
         return totalSalces * Percantage;
     }

     void printComtion(float totalComtion)
     {

         cout << "########### Result ###########3\n";
         cout << " your total Comation is " << totalComtion << endl;
     }

     // ----------------- 35 ---------------------
     struct stBankContent
     {
         int penny;
         int nickel;
         int dime;
         int quarter;
         int dollar;
     };

     stBankContent readpiggybankcontent()
     {

         stBankContent bankContent;
         cout << " Enter  your pennys count -->";
         cin >> bankContent.penny;
         cout << "\n Enter  your nickels count -->";
         cin >> bankContent.nickel;
         cout << "\n Enter  your dimes count -->";
         cin >> bankContent.dime;
         cout << "\n Enter  your quarters count -->";
         cin >> bankContent.quarter;
         cout << "\n Enter  your dollars count -->";
         cin >> bankContent.dollar;

         return bankContent;
     }

     float clculatePiggyBankMoney(stBankContent bankContent){
         
         int   totalPennys = bankContent.penny + bankContent.nickel * 5 + bankContent.dime * 10 + bankContent.quarter * 25 + bankContent.dollar * 100;
         return (float)totalPennys;
        }

      void PrintResult(float totalPennys){
          cout << " your total pennys is " << totalPennys << " that means you have " << totalPennys / 100 << " Dollars";      

      }

    //       printComtion(caluclateComtion(totalSalces));
      int main()
      {
          // ----------------- 31 ---------------------
          // برنامج ياخد الرقم ثم يقوم وبباعة الرقم للاس 2 و3 و4 لكن بدون فنكشن جاهزة
          // int number =readPositiveNumber("Enter Number and i will give you the number with the power 2,3,4 --> ");
          // printNumberPower(calculateNumberPower2_3_4(number),number);

          // ----------------- 32 ---------------------
          // برنامج ياخذ الرقم والاس ثم يرجع لك الرقم مرفوع للاس
          // ملاحظة لاتنسى ان  اي رقم للاس 0 يساوي واحد ايضا قم بقراة الرقم بفنكشن والقوة بفنكشن اخر
        //    int number = readPositiveNumber(" please Enter  the number you want to power it ");
        //    int power = readPositiveNumber("enter the power ");

        //    printTheResult(number,power,clculateNumberPower(number, power));

          // ----------------- 33 ---------------------
          // لا تنسى ان تقوم بعمل فالدي للرقم  اذا كان بين الصفر و100
          //  برنامج ياخذ الدرجة من المستخدم واذا كانت 100-90 يبع اي من 89- 80 يطبع بي
          //  من  79-70 يطبع سي
          //  من 69-60 يطبع دي
          //  من 59 -50 يطبع e
          //  اقل من 50 يطبع اف
        //   int grade = readNumberInRange(0, 100);
        //   printTheResult(claculateStudantResult(grade));

          // ----------------- 34 ---------------------
          //   برنامج يحسب الكوميشن بناء على التوتال سيلس
          float  totalSalces =(float) readPositiveNumber("please enter you total Salces  ");
          float Comation = clculateTotalComtion(getComtionPercantage(totalSalces), totalSalces);
          printComtion(Comation);

          // ----------------- 35 ---------------------
          //  برنامج يحسب القروش المصبنا
          //  PrintResult(clculatePiggyBankMoney(readpiggybankcontent()));

          return 0;
      }