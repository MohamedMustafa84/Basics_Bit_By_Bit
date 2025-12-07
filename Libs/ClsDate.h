#pragma once 
#include <iostream>
#include "ClsString.h"
#include <vector>
using namespace std ;

class clsDate{
    short _Day;
	short _Month;
	short _Year;

public:
    clsDate(){
        time_t t = time(0);
        tm *now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon+1;
        _Year = now->tm_year +1900;
    }

    clsDate(string sDate){
        vector<string> vDate;
		vDate = clsString::Split(sDate, "/");
		_Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

    clsDate(short Day, short Month,short Year )
    {

        _Day = Day;
        _Month = Month;
        _Year = Year;
    }


    clsDate(short DateOrderInYear, short Year)
	{
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
	    _Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;
	}

    void SetDay(short Day){
        _Day = Day;
    };
    short GetDay(){
        return _Day;
    }

    void SetMonth(short Month)
    {
        _Month = Month;
    };
    short GetMonth()
    {
        return _Month;
    }

    void SetYear(short Year)
    {
        _Year = Year;
    };
    short GetYear()
    {
        return _Year;
    }

    void Print(){
        cout << DateToString() << endl;
    }

    static  string DateToString(clsDate Date, string delim = "/")
    {
        return to_string(Date._Day) + delim + to_string(Date._Month) + delim + to_string(Date._Year);
    }
    
    
    string DateToString()
    {
        return DateToString(*this);
    }

    static bool IsValidDate(clsDate Date)
    {

        if (Date._Day < 1 || Date._Day > 31)
            return false;

        if (Date._Month < 1 || Date._Month > 12)
            return false;

        if (Date._Month == 2)
        {
            if (IsLeapYear(Date._Year))
            {
                if (Date._Day > 29)
                    return false;
            }
            else
            {
                if (Date._Day > 28)
                    return false;
            }
        }
		return true;
	}

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static clsDate GetSystemDate(){
        // system date

        time_t t = time(0);
        tm* now =localtime(&t);

        short Day, Month, Year;
        Year=now->tm_year+1900;
        Month=now->tm_mon +1;
        Day = now->tm_mday;


        return clsDate(Day, Month, Year);
    }

    static bool IsLeapYear(short  year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool IsLeapYear(){
        return IsLeapYear(_Year);
    }

    

  static short NumberOfDaysInAYear(short Year)
  {
      return IsLeapYear(Year) ? 366 : 365;
  }

  short NumberOfDaysInAYear()
  {
      return NumberOfDaysInAYear(_Year);
  }

  static short NumberOfHoursInAYear(short Year)
  {
      return NumberOfDaysInAYear(Year) * 24;
  }

  short NumberOfHoursInAYear()
  {
      return NumberOfHoursInAYear(_Year);
  }

  static int NumberOfMinutesInAYear(short Year)
  {
      return NumberOfHoursInAYear(Year) * 60;
  }

  int NumberOfMinutesInAYear()
  {
      return NumberOfMinutesInAYear(_Year);
  }

  static int NumberOfSecondsInAYear(short Year)
  {
      return NumberOfMinutesInAYear(Year) * 60;
  }

  int NumberOfSecondsInAYear()
  {
      return NumberOfSecondsInAYear(_Year);
  }

  static short NumberOfDaysInAMonth(short Month, short Year)
  {

      if (Month < 1 || Month > 12)
          return 0;

      int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
  }

  short NumberOfDaysInAMonth()
  {
      return NumberOfDaysInAMonth(_Month, _Year);
  }

  static short NumberOfHoursInAMonth(short Month, short Year)
  {
      return NumberOfDaysInAMonth(Month, Year) * 24;
  }

  short NumberOfHoursInAMonth()
  {
      return NumberOfDaysInAMonth(_Month, _Year) * 24;
  }

  static int NumberOfMinutesInAMonth(short Month, short Year)
  {
      return NumberOfHoursInAMonth(Month, Year) * 60;
  }

  int NumberOfMinutesInAMonth()
  {
      return NumberOfHoursInAMonth(_Month, _Year) * 60;
  }

  static int NumberOfSecondsInAMonth(short Month, short Year)
  {
      return NumberOfMinutesInAMonth(Month, Year) * 60;
  }

  int NumberOfSecondsInAMonth()
  {
      return NumberOfMinutesInAMonth(_Month, _Year) * 60;
  }

  static short DayOfWeekOrder(short Day, short Month, short Year)
  {
      short a, y, m;
      a = (14 - Month) / 12;
      y = Year - a;
      m = Month + (12 * a) - 2;
      // Gregorian:
      // 0:sun, 1:Mon, 2:Tue...etc
      return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }

  short DayOfWeekOrder()
  {
      return DayOfWeekOrder(_Day, _Month, _Year);
  }

  static string DayShortName(short DayOfWeekOrder)
  {
      string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

      return arrDayNames[DayOfWeekOrder];
  }

  static string DayShortName(short Day, short Month, short Year)
  {

      string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

      return arrDayNames[DayOfWeekOrder(Day, Month, Year)];
  }

  string DayShortName()
  {

      string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

      return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year)];
  }

  static string MonthShortName(short MonthNumber)
  {
      string Months[12] = {"Jan", "Feb", "Mar",
                           "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep",
                           "Oct", "Nov", "Dec"};

      return (Months[MonthNumber - 1]);
  }

  string MonthShortName()
  {

      return MonthShortName(_Month);
  }

  static void PrintMonthCalendar(short Month, short Year)
  {
      int NumberOfDays;

      int current = DayOfWeekOrder(1, Month, Year);

      NumberOfDays = NumberOfDaysInAMonth(Month, Year);

      printf("\n  _______________%s_______________\n\n",
             MonthShortName(Month).c_str());

      printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

      int i;
      for (i = 0; i < current; i++)
          printf("     ");

      for (int j = 1; j <= NumberOfDays; j++)
      {
          printf("%5d", j);

          if (++i == 7)
          {
              i = 0;
              printf("\n");
          }
      }

      printf("\n  _________________________________\n");
  }

  void PrintMonthCalendar()
  {
      PrintMonthCalendar(_Month, _Year);
  }

  static void PrintYearCalendar(int Year)
  {
      printf("\n  _________________________________\n\n");
      printf("           Calendar - %d\n", Year);
      printf("  _________________________________\n");

      for (int i = 1; i <= 12; i++)
      {
          PrintMonthCalendar(i, Year);
      }

      return;
  }

  void PrintYearCalendar()
  {
      printf("\n  _________________________________\n\n");
      printf("           Calendar - %d\n", _Year);
      printf("  _________________________________\n");

      for (int i = 1; i <= 12; i++)
      {
          PrintMonthCalendar(i, _Year);
      }

      return;
  }

  static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
  {

      short TotalDays = 0;

      for (int i = 1; i <= Month - 1; i++)
      {
          TotalDays += NumberOfDaysInAMonth(i, Year);
      }

      TotalDays += Day;

      return TotalDays;
  }

  short DaysFromTheBeginingOfTheYear()
  {

      short TotalDays = 0;

      for (int i = 1; i <= _Month - 1; i++)
      {
          TotalDays += NumberOfDaysInAMonth(i, _Year);
      }

      TotalDays += _Day;

      return TotalDays;
  }

  static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
  {

      clsDate Date;
      short RemainingDays = DateOrderInYear;
      short MonthDays = 0;

      Date._Year = Year;
      Date._Month = 1;

      while (true)
      {
          MonthDays = NumberOfDaysInAMonth(Date._Month, Year);

          if (RemainingDays > MonthDays)
          {
              RemainingDays -= MonthDays;
              Date._Month++;
          }
          else
          {
              Date._Day = RemainingDays;
              break;
          }
      }

      return Date;
  }

  void AddDays(short Days)
  {

      short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
      short MonthDays = 0;

      _Month = 1;

      while (true)
      {
          MonthDays = NumberOfDaysInAMonth(_Month, _Year);

          if (RemainingDays > MonthDays)
          {
              RemainingDays -= MonthDays;
              _Month++;

              if (_Month > 12)
              {
                  _Month = 1;
                  _Year++;
              }
          }
          else
          {
              _Day = RemainingDays;
              break;
          }
      }
  }

  static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
  {
      return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
  }

  bool IsDateBeforeDate2(clsDate Date2)
  {
      // note: *this sends the current object :-)
      return IsDate1BeforeDate2(*this, Date2);
  }

  static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
  {
      return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
  }

  bool IsDateEqualDate2(clsDate Date2)
  {
      return IsDate1EqualDate2(*this, Date2);
  }

  static bool IsLastDayInMonth(clsDate Date)
  {

      return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));
  }

  bool IsLastDayInMonth()
  {

      return IsLastDayInMonth(*this);
  }

  static bool IsLastMonthInYear(short Month)
  {
      return (Month == 12);
  }


  static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}

	static void  SwapDates(clsDate & Date1, clsDate & Date2)
	{

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;

		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}

		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static short CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
	}
	//above no need to have nonstatic function for the object because it does not depend on any data from it.

	static clsDate IncreaseDateByOneWeek(clsDate & Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	clsDate IncreaseDateByOneMonth(clsDate& Date)
	{

		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth()
	{

		IncreaseDateByOneMonth(*this);

	}

	clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days)
	{

		IncreaseDateByXDays(Days, *this);
	}

	clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date._Year += Years;
		return Date;
		
	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		Date._Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date._Year += Decade * 10;
		return Date;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		Date._Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		Date._Year += 1000;
		return Date;
	}

	clsDate IncreaseDateByOneMillennium()
	{
		return IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else
			{

				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate &Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate &Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks ,*this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate &Date)
	{

		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date._Month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}


		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate &Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate &Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths( Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate &Date)
	{

		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate &Date)
	{

		Date._Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years ,*this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate &Date)
	{
		//Period of 10 years
		Date._Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate &Date)
	{

		Date._Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate &Date)
	{
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate &Date)
	{
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}


	static short IsEndOfWeek(clsDate Date)
	{
		return  DayOfWeekOrder(Date._Day, Date._Month, Date._Year) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		
		return !IsWeekEnd(Date);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{

		clsDate EndOfMontDate;
		EndOfMontDate._Day = NumberOfDaysInAMonth(Date1._Month, Date1._Year);
		EndOfMontDate._Month = Date1._Month;
		EndOfMontDate._Year = Date1._Year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1)
	{

		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date1._Year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{

		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;

	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		

		return CalculateBusinessDays(DateFrom, DateTo);

	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = AddOneDay(DateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDateAfterDate2( clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;

	}

	enDateCompare CompareDates( clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

};
