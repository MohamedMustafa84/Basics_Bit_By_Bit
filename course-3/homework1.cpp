#include <iostream>
using namespace std;

enum enDaysOfTheWeek
{
    Sunday = 1,
    Monday = 2,
    Tuesday = 3,
    Wednesday = 4,
    Thursday = 5,
    friday = 6,
    seturday = 7
};

void showWeekDaysMenu(){
    cout << "plz enter the NUMBER  of the day based on the flowing menu : \n";
    cout << "1- sunday\n";
    cout << "2-monday\n";
    cout << "3-tuesday\n";
    cout << "4-wednesday\n";
    cout << "5-thurday\n";
    cout << "6-friday\n";
    cout << "7-seturday\n";
}
enDaysOfTheWeek getTheUSerDay(){
    enDaysOfTheWeek weekday;
    int wd;

    cout << "please enter your current day --> ";
    cin >> wd;

    return  weekday = (enDaysOfTheWeek)wd;
}
string printTheUserDay(enDaysOfTheWeek weekday){

    switch(weekday){
        case enDaysOfTheWeek::Sunday:
            return " Sunday";
            break;
        case enDaysOfTheWeek::Monday:
            return " Monday";
            break;
        case enDaysOfTheWeek::Tuesday:
            return " Tuesday"; 
            break;
        case enDaysOfTheWeek::Wednesday:
            return "Wednesday";
            break;
        case enDaysOfTheWeek::Thursday:
            return "Thursday";
            break;
        case enDaysOfTheWeek::friday:
            return "friday ";
            break;
        
        case enDaysOfTheWeek::seturday:
            return "seturday";
            break;
        
        default:
        return  "you entered unvalid number of a day plz retry  ";
     };
};

int main(){

    enDaysOfTheWeek day;

    showWeekDaysMenu();

     cout <<"today is " << printTheUserDay(getTheUSerDay());

    return 0;
}