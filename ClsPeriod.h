#pragma once 
#include "ClsDate.h"


class ClsPeriod{
    public :
    ClsDate StartDate;
    ClsDate EndDate;


    ClsPeriod(ClsDate StartDate,ClsDate EndDate){
        this->StartDate=StartDate;
        this->EndDate = EndDate;
    }

    static bool IsOverlapPeriods(ClsPeriod Period1, ClsPeriod Period2)
    {

        if (
            ClsDate::CompareDates(Period2.EndDate, Period1.StartDate) == ClsDate::enDateCompare::Before ||
            ClsDate::CompareDates(Period2.StartDate, Period1.EndDate) == ClsDate::enDateCompare::After)
            return false;
        else
            return true;
    }

    bool IsOverLapWith(ClsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }


    void Print(){
        cout << "Period Start= : ";
        StartDate.Print();

        cout << "Period End : ";
        EndDate.Print();
    }

    static int PeriodLengthInDays(ClsDate StartDate,ClsDate EndDate, bool IncludeLastDay = false)
    {

        return ClsDate::GetDifferenceInDays(StartDate, EndDate, IncludeLastDay);
    }

    int PeriodLengthInDays(bool IncludeLastDay = false){
        return PeriodLengthInDays(this->StartDate, this->EndDate, IncludeLastDay);
    }

    static bool IsDateinPeriod(ClsDate Date, ClsDate PeriodStart, ClsDate PeriodEnd)
    {
        return !(ClsDate::CompareDates(Date, PeriodStart) == ClsDate::enDateCompare::Before ||
                  ClsDate::CompareDates(Date, PeriodEnd) == ClsDate::enDateCompare::After) ;
    }

     bool IsDateinPeriod(ClsDate Date){
         return IsDateinPeriod(Date, this->StartDate, this->EndDate);
     }
};