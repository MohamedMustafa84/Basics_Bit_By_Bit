#pragma once

#include <iostream>
#include <vector>
#include "../../Libs/clsString.h"
#include <fstream>

class clsCurrency
{

    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
    };

    enMode _Mode;

    string _Country = "";
    string _CurrencyCode = "";
    string _CurrencyName = "";
    float _Rate = 0.0f;

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string separator = "#//#")
    {
        vector <string> vCurrencyData = clsString::Split(Line, separator);

        if (vCurrencyData.size() != 4)
        {
            return _GetEmptyCurrencyObject();
        }

        return {
            enMode::UpdateMode,
            vCurrencyData[0],
            vCurrencyData[1],
            vCurrencyData[2],
            stof(vCurrencyData[3]) };
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0.0f);
    }

    static string _ConvertCurrencyObjectToLine(clsCurrency &Currency, string Separator = "#//#")
    {

        string CurrencyRecord = "";

        CurrencyRecord += Currency._Country + Separator;
        CurrencyRecord += Currency._CurrencyCode + Separator;
        CurrencyRecord += Currency._CurrencyName+ Separator;
        CurrencyRecord += to_string(Currency._Rate)+ Separator;


        return CurrencyRecord;
    }

    static vector<clsCurrency> _LoadCurrenciesDataFromFile(string FilePath = "Currencies.txt")
    {
        vector<clsCurrency> vCurrencies;

        fstream CurrenciesFile;

        CurrenciesFile.open(FilePath, ios::in);

        if (CurrenciesFile.is_open())
        {
            string Line;

            while (getline(CurrenciesFile, Line))
            {

                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (!Currency.IsEmpty())
                {
                    vCurrencies.push_back(Currency);
                }
            }

            CurrenciesFile.close();
        }
        return vCurrencies;
        
    }

    static void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies, string FilePath = "Currencies.txt")
    {

        fstream CurrenciesFile;
        CurrenciesFile.open(FilePath, ios::out); 

        string DataLine;

        if (CurrenciesFile.is_open())
        {

            for (clsCurrency &CurrencyObject : vCurrencies)
            {


                DataLine = _ConvertCurrencyObjectToLine(CurrencyObject);

                CurrenciesFile << DataLine << endl;
            }

            CurrenciesFile.close();
        }
    }

    void _Update()
    {
        vector<clsCurrency> vCurrencies;
        vCurrencies = _LoadCurrenciesDataFromFile();

        for (clsCurrency &Currency : vCurrencies)
        {

            if (Currency._CurrencyCode == _CurrencyCode)
            {
                Currency = *this;
                break;
            }
        }

        _SaveCurrenciesDataToFile(vCurrencies);
    }

    


public:

    clsCurrency(){

    }
    clsCurrency (enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
        
    {

        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }
   

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    void UpdateRate(float NewRate){
        _Rate = NewRate;
        _Update();
    }


    float Rate(){
        return _Rate;
    }
   
    static clsCurrency FindByCountry(string Country,string filePath="Currencies.txt")
    {

        vector<clsCurrency> vCurrencies;

        Country = clsString::UpperAllString(Country);

        fstream CurrenciesFile;

        CurrenciesFile.open(filePath, ios::in);
        if (CurrenciesFile.is_open())
        {

            string Line;

            while (getline(CurrenciesFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country)
                {
                    CurrenciesFile.close();
                    return Currency;
                }
                vCurrencies.push_back(Currency);
            }

            CurrenciesFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCode(string CurrencyCode, string filePath = "Currencies.txt")
    {

        vector<clsCurrency> vCurrencies;
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream CurrenciesFile;

        CurrenciesFile.open(filePath, ios::in);
        if (CurrenciesFile.is_open())
        {

            string Line;

            while (getline(CurrenciesFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    CurrenciesFile.close();
                    return Currency;
                }
                vCurrencies.push_back(Currency);
            }

            CurrenciesFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static bool isCurrencyExist(string CurrencyCode){
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        clsCurrency Currency = FindByCode(CurrencyCode);
        return (!Currency.IsEmpty());
    }

    static vector <clsCurrency> GetCurrenciesList(){
        return _LoadCurrenciesDataFromFile();
    }



};
