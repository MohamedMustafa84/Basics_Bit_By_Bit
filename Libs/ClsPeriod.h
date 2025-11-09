#pragma once 
#include "ClsDate.h"

class clsPeriod{
    public :
    clsDate StartDate;
    clsDate EndDate;


    clsPeriod(clsDate StartDate,clsDate EndDate){
        this->StartDate=StartDate;
        this->EndDate = EndDate;
    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After)
            return false;
        else
            return true;
    }

    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }


    void Print(){
        cout << "Period Start= : ";
        StartDate.Print();

        cout << "Period End : ";
        EndDate.Print();
    }

    static int PeriodLengthInDays(clsDate StartDate,clsDate EndDate, bool IncludeLastDay = false)
    {

        return clsDate::GetDifferenceInDays(StartDate, EndDate, IncludeLastDay);
    }

    int PeriodLengthInDays(bool IncludeLastDay = false){
        return PeriodLengthInDays(this->StartDate, this->EndDate, IncludeLastDay);
    }

    static bool IsDateinPeriod(clsDate Date, clsDate PeriodStart, clsDate PeriodEnd)
    {
        return !(clsDate::CompareDates(Date, PeriodStart) == clsDate::enDateCompare::Before ||
                  clsDate::CompareDates(Date, PeriodEnd) == clsDate::enDateCompare::After) ;
    }

     bool IsDateinPeriod(clsDate Date){
         return IsDateinPeriod(Date, this->StartDate, this->EndDate);
     }
};