#include "IncomesFile.h"

IncomesFile :: IncomesFile(string incomesFileName) : INCOMES_FILE_NAME (incomesFileName)
{
    lastIncomeId = 0;
}

vector <Income> IncomesFile :: loadIncomesOfLoggedInUserFromFile(int loggedInUserId) {
    Income income;
    vector <Income> incomes;
    CMarkup incomesFile;
    incomesFile.Load( INCOMES_FILE_NAME );
    //xml.ResetPos();

    incomesFile.FindElem(); // root Incomes element
    incomesFile.IntoElem(); // inside Incomes
    while ( incomesFile.FindElem("Income") ) {
        incomesFile.IntoElem();
        incomesFile.FindElem( "IncomeId" );
        int incomeId = atoi( MCD_2PCSZ(incomesFile.GetData()) );
        income.setIncomeId (incomeId);
        incomesFile.FindElem( "UserId" );
        int userId = atoi( MCD_2PCSZ(incomesFile.GetData()) );
        income.setUserId (userId);
        incomesFile.FindElem( "Date" );
        MCD_STR date = incomesFile.GetData();
        income.setDate (date);
        incomesFile.FindElem( "Item" );
        MCD_STR item = incomesFile.GetData();
        income.setItem (item);
        incomesFile.FindElem( "Amount" );
        double amount = AuxiliaryMethods :: convertStringToDouble(incomesFile.GetData());
        income.setAmount (amount);
        lastIncomeId++;
        if (loggedInUserId == income.getUserId()) {
            incomes.push_back(income);
        }
        incomesFile.OutOfElem();
    }
    return incomes;


}

int IncomesFile :: getTheLastIncomeId() {
    return lastIncomeId;
}

void IncomesFile :: saveIncomeToFile(Income income) {
    CMarkup incomesFile;

    bool fileExists = incomesFile.Load(INCOMES_FILE_NAME);

    if (!fileExists) {
        incomesFile.AddElem("Incomes");
    }

    incomesFile.FindElem();
    incomesFile.IntoElem();
    incomesFile.AddElem ("Income");
    incomesFile.IntoElem();
    incomesFile.AddElem( "IncomeId", AuxiliaryMethods :: convertIntToString (income.getIncomeId()) );
    incomesFile.AddElem( "UserId", AuxiliaryMethods :: convertIntToString (income.getUserId()) );
    incomesFile.AddElem( "Date", income.getDate() );
    incomesFile.AddElem( "Item", income.getItem() );
    incomesFile.AddElem( "Amount", AuxiliaryMethods :: convertDoubleToString (income.getAmount()) );
    incomesFile.Save( INCOMES_FILE_NAME );
    lastIncomeId++;

}
