#pragma once

#include <iostream>
#include "MyLib.h"
using namespace std;



namespace Date{

    struct stDate
    {
        short Day;
        short Month;
        int Year;
    };

    short NumberOfDaysInAMonth(short Month, int Year);

    void SwapDates(Date::stDate &DateOne, Date::stDate &DateTwo)
    {
        Date::stDate Temp = DateOne;
        DateOne = DateTwo;
        DateTwo = Temp;
    }

    namespace checker
    {

        bool isLeapYear(int year)
        {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }


        bool isLastDayInMonth(Date::stDate Date)
        {
            return Date.Day == Date::NumberOfDaysInAMonth(Date.Month, Date.Year);
        }

        bool isLastMonthInYear(Date::stDate Date)
        {
            return Date.Month == 12;
        }


        bool isDateOneEqualDateTwo(stDate DateOne, stDate DateTwo)
        {

            return DateOne.Year == DateTwo.Year &&
             DateOne.Month == DateTwo.Month && 
             DateOne.Day == DateTwo.Day ;
        }


        bool isDateOneBeforeDateTwo(stDate DateOne, stDate DateTwo)
        {

            return (DateOne.Year < DateTwo.Year) ? true :
             (DateOne.Year == DateTwo.Year) ?
              (DateOne.Month < DateTwo.Month) ?true :
               (DateOne.Month == DateTwo.Month) ?
                DateOne.Day < DateTwo.Day: false: false;
        }
    }
    stDate ReadFullDate()
    {
        stDate Date;
        Date.Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");
        Date.Month = UserInputs::ReadNumberInRange("Please Enter The Month", 1, 12);

        short Number_Of_Days_In_Month = NumberOfDaysInAMonth(Date.Month, Date.Year);

        Date.Day = UserInputs::ReadNumberInRange("Please Enter The Day ", 1, NumberOfDaysInAMonth(Date.Month, Date.Year));

        while (Date.Day>Number_Of_Days_In_Month)
        {
            if(Date.Month ==2){
                cout << "Invalid  Input , Month 2 in the Year " << Date.Year << " Have Maximum " << Number_Of_Days_In_Month<<" Days Please Enter Valid Day : ";
                 Date.Day = UserInputs::ReadPositiveNumber("");
            }else{
                cout << "Invalid  Input , Month " << Date.Month << " Have Maximum " << Number_Of_Days_In_Month << " Days Please Enter Valid Day : ";
                Date.Day = UserInputs::ReadPositiveNumber("");
            }
        }

        return Date;
    }

    short NumberOfDaysInAMonth(short Month, int Year)
    {

        short arrNumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (Month == 2) ? checker::isLeapYear(Year) ? 29 : 28 : arrNumberOfDays[Month - 1];
    }

    stDate GetDateFromDayOrderInYear(int NumberOfDays, int Year)
    {

        stDate stDate;
        stDate.Year = Year;
        stDate.Month = 1;

        short RemainingDays = NumberOfDays;

        while (true)
        {
            short NumberOfDaysInMonth = Date::NumberOfDaysInAMonth(stDate.Month, Year);

            if (RemainingDays > NumberOfDaysInMonth)
            {
                RemainingDays -= NumberOfDaysInMonth;
                stDate.Month++;
            }
            else
            {
                stDate.Day = RemainingDays;
                break;
            }
        }

        return stDate;
    }


    namespace Increase{

        Date::stDate Increase_Year_ByXDays(Date::stDate stDate, int &NumberOfIncreaseDays)
        {

            while (NumberOfIncreaseDays >= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365))
            {

                NumberOfIncreaseDays -= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365);
                stDate.Year++;
            }
            return stDate;
        }

        Date::stDate Increase_Month_ByXDays(Date::stDate stDate, int &NumberOfIncreaseDays)
        {

            while (NumberOfIncreaseDays >= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year))
            {

                NumberOfIncreaseDays -= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);

                if (stDate.Month == 12)
                {
                    stDate.Month = 1;
                    stDate.Year++;
                }
                else
                {
                    stDate.Month++;
                }
            }
            return stDate;
        }

        Date::stDate Increase_Date_ByXDays(Date::stDate stDate, int RemainingDays)
        {

            stDate = Increase_Year_ByXDays(stDate, RemainingDays);
            stDate = Increase_Month_ByXDays(stDate, RemainingDays);

            stDate.Day += RemainingDays;

            while (stDate.Day > Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year))
            {
                stDate.Day -= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);
                if (stDate.Month == 12)
                {

                    stDate.Month = 1;
                    stDate.Year++;
                }
                else
                {

                    stDate.Month++;
                }
            }
            return stDate;
        }

        Date::stDate IncreaseDateBy_XWeek(Date::stDate stDate,int WeeksNumber){
            return Increase_Date_ByXDays(stDate, WeeksNumber * 7);
        }

        Date::stDate IncreaseDateBy_XMonth(Date::stDate stDate, int MonthsNumber)
        {
            
            stDate.Month += MonthsNumber;

            while(stDate.Month > 12){

                stDate.Month -= 12;
                stDate.Year++;
            }

            return stDate;
        }

        Date::stDate IncreaseDateBy_XYear(Date::stDate stDate, int YearsNumber)
        {
            stDate.Year += YearsNumber;
            short NumberOfMonthDays = NumberOfDaysInAMonth(stDate.Month, stDate.Year);

            if (stDate.Day > NumberOfMonthDays)
            {
                stDate.Day = NumberOfMonthDays;
            }

            return stDate;
        }

        Date::stDate IncreaseDateByOneDay(Date::stDate stDate)
        {
            if (Date::checker::isLastDayInMonth(stDate))
            {

                if (Date::checker::isLastMonthInYear(stDate))
                {
                    stDate.Day = 1;
                    stDate.Month = 1;
                    stDate.Year++;
                }
                else
                {
                    stDate.Day = 1;
                    stDate.Month++;
                }
            }
            else
            {
                stDate.Day++;
            }
            return stDate;
        } 
        
        

    }

    int GetDifferenceInDays(Date::stDate DateOne, Date::stDate DateTwo, bool IncludeEndDay = false)
    {

        int Days = 0;

        if(!Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
        {
            SwapDates(DateOne, DateTwo);
        }

        while (Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
        {
            Days++;
            DateOne =Increase::IncreaseDateByOneDay(DateOne);
        }

        return IncludeEndDay ? ++Days : Days;
    }
    stDate GetCurrentDate(){
        stDate Date;

        time_t t = time(0);
        tm *now = localtime(&t);

        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;
        return Date;
    }
}