#include <iostream>
#include <cmath>
using namespace std;

// --------------- generic functions --------------------
int readNumberInRange( string message ,int from, int to){
    int number;
    cout << message << " [" <<from<<" - "<<to<<" ]";
    cin >> number;
    cout << endl;
    while (number < from || number > to)
    {
        cout << " the number moust be btween  " << from << " - " << to << " -->";
        cin >> number;
        cout << endl;
    }
    return number;
} 
int readNumber(string massage)
{
    int  number;
    cout << massage << endl;
    cin >> number;
    while (number <= 0)
    {
        cout << " the number most be greter than zero please retry -->";
        cin >> number;
        cout << endl;
    }

    return number;
}
float readPositiveNumber(string massage)
{
    float number;
    cout << massage << endl;
    cin >> number;
    while (number <= 0)
    {
        cout << " the number most be grater than zero please retry -->";
        cin >> number;
        cout << endl;
    }

    return number;
}

// -------------- 41 -----------------
float calulateDaysCount(float hoursCount){
    return hoursCount / 24;
}

float calculateWeeksCount(float daysCount){
    return daysCount / 7;
}
 void printDaysAndWeekCount(float  hoursCount, float  daysCount, float  weeksCount){
     cout << " the days Count in " << hoursCount << " is " << daysCount << " days" <<endl;
     cout << " the weeks count  in " << hoursCount << " is " << weeksCount <<"weeks"<< endl;
 }
 // -------------- 42-----------------
 struct stTimeCeils{
     int days,hours,minutes ,seconds;
 };

 stTimeCeils readTimeCeils(){
     stTimeCeils time;
     time.days = readNumber(" Enter the days count -->");
    time.minutes = readNumber("Enter the minutes count -->");
        time.seconds = readNumber("nEnter the seconds count -->");
    return time;
 }
 int claculateTaskDurationInSeconds(stTimeCeils time ){
     int DurationInSecond = 0;
     DurationInSecond += time.days * 24 * 60 * 60;
     DurationInSecond += time.hours * 60 * 60;
     DurationInSecond += time.minutes * 60;
     DurationInSecond += time.seconds;
     return DurationInSecond;
 }
 void printTaskDurationInSeconds(int Duration){
     cout << "your task duration in second is  " << Duration << endl;
 }
 // -------------- 43-----------------
 stTimeCeils SecondsToTaskDuration(int  totalSeconds){
     stTimeCeils timeCeils;
     const int  secondsPerDay = 24 * 60 * 60;
     const int secondsPerHour = 60 * 60;
     const int secondsPerminute = 60;



     timeCeils.days =(int) floor(totalSeconds / secondsPerDay);
     int Remainder = totalSeconds % secondsPerDay;
     timeCeils.hours =(int)floor( Remainder / secondsPerHour);
     Remainder = Remainder % secondsPerHour;
     timeCeils.minutes =(int) floor(Remainder / secondsPerminute);
     timeCeils.seconds = Remainder % secondsPerminute;
     return timeCeils;
 }

 void pritTaskResult(stTimeCeils time){
     cout <<"your task  will take this duration  " << endl;
     cout << time.days << " : " << time.hours << " : " << time.minutes << " : " << time.seconds << endl;
 }
 // -------------- 44 -----------------
 enum enDaysOfWeek
 {
     Monday=1,
     Teuseday=2,
     Wednesday=3,
     Throuthday=4,
     Friday=5,
     Seterday=6,
     Sunday=7,

 };
 enDaysOfWeek ReadDay (){
     int day;
     cout <<"1-monday \n";
     cout <<"2-Teuseday\n";
     cout <<"3-Wednesday\n";
     cout <<"4-Throuthday\n";
     cout <<"5-Friday\n";
     cout <<"6-Seterday\n";
     cout <<"7-Sunday\n";
     day = readNumberInRange(" please enter the number of the day from  the flowing list",1, 7);

    return (enDaysOfWeek)day;
 }
  string  getCurrentDay( enDaysOfWeek CurrentDay){
    switch (CurrentDay)
    {
    case enDaysOfWeek::Monday:
        return "Monday";
    case enDaysOfWeek::Teuseday:
        return "Teuseday";
    case enDaysOfWeek::Wednesday:
        return "Wednesday";
    case enDaysOfWeek::Throuthday:
        return "Throuthday";
    case enDaysOfWeek::Friday:
        return "Friday";
    case enDaysOfWeek::Seterday:
        return "Seterday ";
    default:
        return "Sunday";
        break;
    }
  }
  void PrintCurrentDay(string currentDay ){
      cout << " ################ result ####################" << endl;
      cout << "your current day is " << currentDay << endl;
    }
    
    // -------------- 45 -----------------
    enum enManthsOfYear
    {
        januarey=1,
        fepruarey=2,
        march=3,
        April=4,
        May=5,
        June=6,
        Julay=7,
        Augest=8,
        Septemper=9,
        Octoper=10,
        November=11,
        December=12
    };

    enManthsOfYear ReadManth()
    {
        int manth;
        cout << " manths of the year :\n";

        cout << "januarey = 1\n";
        cout << "fepruarey = 2\n";
        cout << "march = 3\n";
        cout << "April = 4\n";
        cout << "May = 5\n";
        cout << "June = 6\n";
        cout << "Julay = 7\n";
        cout << "Augest = 8\n";
        cout << "Septemper = 9\n";
        cout << "Octoper = 10\n";
        cout << "November = 11\n";
        cout << "December = 1\n";


        manth = readNumberInRange(" please enter the number of the manth from  the Previous list", 1, 12);
        return (enManthsOfYear)manth;
    }

    string getCurrentManth(enManthsOfYear CurrentManth)
    {
        switch (CurrentManth)
        {
        case  enManthsOfYear::januarey:
            return "januarey";
        case  enManthsOfYear::fepruarey:
            return "fepruarey";
        case  enManthsOfYear::march:
            return "march";
        case  enManthsOfYear::April:
            return "April";
        case  enManthsOfYear::May:
            return "May";
        case enManthsOfYear::June:
            return "June";
        case enManthsOfYear::Julay:
            return "Julay";
        case enManthsOfYear::Augest:
            return "Augest";
        case enManthsOfYear::Septemper:
            return "Septemper";
        case enManthsOfYear::Octoper:
            return "Octoper";
        case enManthsOfYear::November:
            return "November";
        default:
            return "December";
            break;
        }
    }
    void PrintCurrentManth(string currentManth)
    {
        cout << " ################ result ####################" << endl;
        cout << "your current Manth is " << currentManth<< endl;
    }

 int main()
 {

     // -------------- 41 -----------------
     // float hoursCount = readPositiveNumber(" please enter the hour count  and i will calculate the day and week ");
     // float daysCount = calulateDaysCount(hoursCount);
     // float weeksCount = calculateWeeksCount(daysCount);
     // printDaysAndWeekCount(hoursCount, daysCount, weeksCount);
     // -------------- 42-----------------

    //  int Duration = claculateTaskDurationInSeconds(readTimeCeils());
    //  printTaskDurationInSeconds(Duration);

     // -------------- 43-----------------
    //  int  totalSeconds =(int) readPositiveNumber("please enter the total seconds ");
    //  pritTaskResult(SecondsToTaskDuration(totalSeconds));
     // -------------- 44-----------------
     
        //  PrintCurrentDay(getCurrentDay(ReadDay()));
      

         // -------------- 45-----------------
        //  PrintCurrentManth(getCurrentManth(ReadManth()));

         return 0;
     }