#pragma once

#include <iostream>
#include "MyLib.h"
#include <cmath>
using namespace std;

namespace Date{

    struct stDate
    {
        short Day;
        short Month;
        int Year;
    };

    struct stPeriod
    {
        Date::stDate DateFrom;
        Date::stDate DateTo;
    };

    enum enDateCompare
    {
        Before = -1,
        Equal = 0,
        After = 1,
    };

   


    short NumberOfDaysInAMonth(short Month, int Year);
    int DayOfWeekOrder(Date::stDate Date);
    enDateCompare CompareTwoDates(Date::stDate DateOne, Date::stDate DateTwo);

    void SwapDates(Date::stDate &DateOne, Date::stDate &DateTwo)
    {
        Date::stDate Temp = DateOne;
        DateOne = DateTwo;
        DateTwo = Temp;
    }

    string FormatDate(Date::stDate stDate, string DateFormat = "dd/mm/yyyy")
    {

        string formattedDate = "";

        formattedDate = String::Replace_Word_In_String(DateFormat, "dd", to_string(stDate.Day));
        formattedDate = String::Replace_Word_In_String(formattedDate, "mm", to_string(stDate.Month));
        formattedDate = String::Replace_Word_In_String(formattedDate, "yyyy", to_string(stDate.Year));

        return formattedDate;
    }

    stDate ReadFullDate()
    {
        stDate Date;
        Date.Year = UserInputs::ReadPositiveNumber("Please Enter The Year  : ");
        Date.Month = UserInputs::ReadNumberInRange("Please Enter The Month", 1, 12);

        short NumberOfDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

        Date.Day = UserInputs::ReadNumberInRange("Please Enter The Day ",1, NumberOfDaysInMonth);


        return Date;
    }

    stPeriod ReadPeriod(string PeriodName)
    {
        stPeriod Period;
        cout << "Please Enter " << PeriodName << " Start  Date :\n";
        Period.DateFrom = Date::ReadFullDate();
        cout << "Now Enter The End " << PeriodName << " Date :\n";
        Period.DateTo = Date::ReadFullDate();

        return Period;
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
                   DateOne.Day == DateTwo.Day;
        }

        bool isDateOneBeforeDateTwo(stDate DateOne, stDate DateTwo)
        {

            return (DateOne.Year < DateTwo.Year) ? true : (DateOne.Year == DateTwo.Year) ? (DateOne.Month < DateTwo.Month) ? true : (DateOne.Month == DateTwo.Month) ? DateOne.Day < DateTwo.Day
                                                                                                                                                                     : false
                                                                                         : false;
        }

        bool isValidDate(stDate Date)
        {
            return (Date.Year > 0 ? (Date.Month >= 1 || Date.Month <= 12) ? Date.Day <= NumberOfDaysInAMonth(Date.Month, Date.Year) : false : false);
        }

        bool isEndOfWeek(Date::stDate Date)
        {
            return Date::DayOfWeekOrder(Date) == 6;
        }

        bool isWeekEnd(Date::stDate Date)
        {
            short DayIndex = Date::DayOfWeekOrder(Date);
            return (DayIndex == 5 || DayIndex == 6);
        }

        bool isBusinessDay(Date::stDate Date)
        {
            return (!isWeekEnd(Date));
        }

        bool isItOverLapPeriods(Date::stPeriod PeriodOne, Date::stPeriod PeriodTwo)
        {

            if (CompareTwoDates(PeriodTwo.DateTo, PeriodOne.DateFrom) == enDateCompare::Before ||
                CompareTwoDates(PeriodTwo.DateFrom, PeriodOne.DateTo) == enDateCompare::After)
            {
                return false;
            }
            return true;
        }

        bool isDateinPeriod(Date::stDate Date, Date::stPeriod Period)
        {
            return !(Date::CompareTwoDates(Period.DateFrom, Date) == Date::enDateCompare::Before ||
                     Date::CompareTwoDates(Date, Period.DateTo) == Date::enDateCompare::After);
        }
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

    int DayOfWeekOrder(Date::stDate Date)
    {
        int a, y, m;
        a = (14 - Date.Month) / 12;
        y = Date.Year - a;
        m = Date.Month + (12 * a) - 2;
        return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    }
    string DayShortName(int DayOfWeekOrder)
    {
        string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return arrDayNames[DayOfWeekOrder];
    }
    enDateCompare CompareTwoDates(Date::stDate DateOne, Date::stDate DateTwo)
    {

        if (Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
        {
            return enDateCompare::Before;
        }
        else if (Date::checker::isDateOneEqualDateTwo(DateOne, DateTwo))
        {
            return enDateCompare::Equal;
        }
        return enDateCompare::After;
    }

    namespace Increase{

        Date::stDate IncreaseYearByXDays(Date::stDate stDate, int &NumberOfIncreaseDays)
        {

            while (NumberOfIncreaseDays >= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365))
            {

                NumberOfIncreaseDays -= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365);
                stDate.Year++;
            }
            return stDate;
        }

        Date::stDate IncreaseMonthByXDays(Date::stDate stDate, int &NumberOfIncreaseDays)
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

        Date::stDate IncreaseDateByXDays(Date::stDate stDate, int RemainingDays)
        {

            stDate = IncreaseYearByXDays(stDate, RemainingDays);
            stDate = IncreaseMonthByXDays(stDate, RemainingDays);

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

        Date::stDate IncreaseDateByXWeek(Date::stDate stDate,int WeeksNumber){
            return IncreaseDateByXDays(stDate, WeeksNumber * 7);
        }

        Date::stDate IncreaseDateByXMonth(Date::stDate stDate, int MonthsNumber)
        {
            
            stDate.Month += MonthsNumber;

            while(stDate.Month > 12){

                stDate.Month -= 12;
                stDate.Year++;
            }

            return stDate;
        }

        Date::stDate IncreaseDateByXYear(Date::stDate stDate, int YearsNumber)
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

   
   namespace Decrease{

       Date::stDate DecreaseDateByOneDay(Date::stDate stDate)
       {
           if (1 == stDate.Day)
           {

               if (1 == stDate.Month)
               {
                   stDate.Day = 31;
                   stDate.Month = 12;
                   stDate.Year--;
               }
               else
               {
                   stDate.Day = Date::NumberOfDaysInAMonth(stDate.Month - 1, stDate.Year);
                   stDate.Month--;
               }
           }
           else
           {
               stDate.Day--;
           }
           return stDate;
       }

       Date::stDate DecreaseYearByXDays(Date::stDate stDate, int &NumberOfSubtractDays)
       {

           while (NumberOfSubtractDays >= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365))
           {

               NumberOfSubtractDays -= (Date::checker::isLeapYear(stDate.Year) ? 366 : 365);
               stDate.Year--;
           }

           return stDate;
       }
       Date::stDate DecreaseMonthByXDays(Date::stDate stDate, int &NumberOfSubstractDays)
       {
           while (NumberOfSubstractDays >= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year))
           {
               NumberOfSubstractDays -= Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);

               if (stDate.Month == 1)
               {
                   stDate.Month = 12;
                   stDate.Year--;
               }
               else
               {
                   stDate.Month--;
               }
           }

           while (NumberOfSubstractDays > 0)
           {
               stDate = DecreaseDateByOneDay(stDate);
               NumberOfSubstractDays--;
           }

           return stDate;
       }

       Date::stDate DecreaseDateByXDays(Date::stDate stDate, int RemainingDays)
       {

           stDate = DecreaseYearByXDays(stDate, RemainingDays);
           stDate = DecreaseMonthByXDays(stDate, RemainingDays);
           while (RemainingDays > 0)
           {
               if (RemainingDays >= stDate.Day)
               {
                   RemainingDays -= stDate.Day;

                   if (stDate.Month == 1)
                   {
                       stDate.Month = 12;
                       stDate.Year--;
                   }
                   else
                   {
                       stDate.Month--;
                   }

                   stDate.Day = Date::NumberOfDaysInAMonth(stDate.Month, stDate.Year);
               }
               else
               {
                   stDate.Day -= RemainingDays;
                   RemainingDays = 0;
               }
           }

           return stDate;
       }

       Date::stDate DecreaseDateByXMonth(Date::stDate Date, int NumOfSubtractMonths)
       {
           int totalMonths = (Date.Year * 12 + Date.Month - 1) - NumOfSubtractMonths;
           Date.Year = totalMonths / 12;
           Date.Month = totalMonths % 12 + 1;

           return Date;
       }
       Date::stDate DecreaseDateByXYear(Date::stDate Date, int NumOfSubtractYears)
       {
           Date.Year = Date.Year - NumOfSubtractYears;
           short maxDays = Date::NumberOfDaysInAMonth(Date.Month, Date.Year);
           if (Date.Day > maxDays)
               Date.Day = maxDays;

           return Date;
       }
   }

   int calculateActualVacationDays(stPeriod Period)
   {

       int VacationDays = 0;
       while (Date::checker::isDateOneBeforeDateTwo(Period.DateFrom, Period.DateTo))
       {
           if (Date::checker::isBusinessDay(Period.DateFrom))
           {
               VacationDays++;
           }
           Period.DateFrom = Date::Increase::IncreaseDateByOneDay(Period.DateFrom);
       }
       return VacationDays;
   }



    int GetDifferenceInDays(Date::stDate DateOne, Date::stDate DateTwo, bool IncludeEndDay = false)
    {

        int DiffDays = 0;

        if (checker::isDateOneEqualDateTwo(DateOne, DateTwo))
        {
            return IncludeEndDay ? ++DiffDays : DiffDays;
        }

        if(!Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
        {
            SwapDates(DateOne, DateTwo);
        }

        while (Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo))
        {
            DateOne = Increase::IncreaseDateByXYear(DateOne, 1);
            DiffDays +=(checker::isLeapYear(DateOne.Year) ? 366 : 365);
            
        }
        
        DiffDays -= (checker::isLeapYear(DateOne.Year) ? 366 : 365);
        DateOne.Year--;

        while (Date::checker::isDateOneBeforeDateTwo(DateOne, DateTwo)){
        
            DateOne = Increase::IncreaseDateByXMonth(DateOne, 1);
            DiffDays += NumberOfDaysInAMonth(DateOne.Month, DateOne.Year);
            if (DateOne.Year == DateTwo.Year && DateOne.Month == DateTwo.Month)
            {
                DiffDays += abs(DateTwo.Day - DateOne.Day);
            }
        }
        return IncludeEndDay ? ++DiffDays : DiffDays;
    }

    int calculatePeriodLength(Date::stPeriod Period, bool IncludeLastDay=false){
    
        return Date::GetDifferenceInDays(Period.DateFrom, Period.DateTo, IncludeLastDay);
    }

    stDate GetCurrentDate()
    {
        stDate Date;

        time_t t = time(0);
        tm *now = localtime(&t);

        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;
        return Date;
    }
    namespace Convert{
        Date::stDate ConvertStringToDate(string StringDate)
        {

            Date::stDate stDate;

            vector<string> vDate = String::splitString(StringDate, "/");

            stDate.Day = stoi(vDate[0]);
            stDate.Month = stoi(vDate[1]);
            stDate.Year = stoi(vDate[2]);

            return stDate;
        }

        string ConvertDateToString(Date::stDate Date, string delim ="/") {
            return to_string(Date.Day) + delim + to_string(Date.Month) + delim + to_string(Date.Year);
        }
    }
}
