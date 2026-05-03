#include <iostream>
#include "../ClsCurrencies.h"
#include "ClsScreen.h"
#include <iomanip>

using namespace std;

class clsCurrenciesListScreen: protected clsScreen
{
private:
    static void PrintCurrencyInfo(clsCurrency &Currency)
    {
        cout << "| " << left << setw(35) << Currency.Country();
        cout << "| " << left << setw(15) << Currency.CurrencyCode();
        cout << "| " << left << setw(35) << Currency.CurrencyName();
        cout << "| " << left << setw(15) << Currency.Rate()<<"\n";
    }

public:
    static void ShowCurrenciesList()
    {

        vector<clsCurrency> vCurrencies;
        vCurrencies = clsCurrency::GetCurrenciesList();

        short CurrenciesNumber = vCurrencies.size();

        string Title = "\t Currencies List Screen ";
        string SubTitle = "\t (" + to_string(CurrenciesNumber) + ") Currencies";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << "\n___________________________________________________________________________________________________________________\n";

        cout << "| " << left << setw(35) << "Country";
        cout << "| " << left << setw(15) << "Currency Code";
        cout << "| " << left << setw(35) << "Currency Name";
        cout << "| " << left << setw(15) << "Currency Rate";
        cout << "\n___________________________________________________________________________________________________________________\n";

        if (CurrenciesNumber == 0)
        {
            cout << "\n\n\t\t\tNo Currencies Available in The System :(";
        }
        else
        {
            for (clsCurrency &Currency : vCurrencies)
            {
                PrintCurrencyInfo(Currency);
            }
        }
        cout << "\n___________________________________________________________________________________________________________________\n";
    }
};
