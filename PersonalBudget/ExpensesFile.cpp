#include "ExpensesFile.h"

ExpensesFile :: ExpensesFile(string expensesFileName) : EXPENSES_FILE_NAME (expensesFileName)
{
    lastExpenseId = 0;
}

vector <Expense> ExpensesFile :: loadExpensesOfLoggedInUserFromFile(int loggedInUserId) {
    Expense expense;
    vector <Expense> expenses;
    CMarkup expensesFile;
    expensesFile.Load( EXPENSES_FILE_NAME );
    //xml.ResetPos();

    expensesFile.FindElem(); // root Expenses element
    expensesFile.IntoElem(); // inside Expenses
    while ( expensesFile.FindElem("Expense") ) {
        expensesFile.IntoElem();
        expensesFile.FindElem( "ExpenseId" );
        int expenseId = atoi( MCD_2PCSZ(expensesFile.GetData()) );
        expense.setExpenseId (expenseId);
        expensesFile.FindElem( "UserId" );
        int userId = atoi( MCD_2PCSZ(expensesFile.GetData()) );
        expense.setUserId (userId);
        expensesFile.FindElem( "Date" );
        MCD_STR date = expensesFile.GetData();
        expense.setDate (date);
        expensesFile.FindElem( "Item" );
        MCD_STR item = expensesFile.GetData();
        expense.setItem (item);
        expensesFile.FindElem( "Amount" );
        double amount = AuxiliaryMethods :: convertStringToDouble(expensesFile.GetData());
        expense.setAmount (amount);
        lastExpenseId++;
        expenses.push_back(expense);
        expensesFile.OutOfElem();
    }
    return expenses;


}

int ExpensesFile :: getTheLastExpenseId() {
    return lastExpenseId;
}

void ExpensesFile :: saveExpenseToFile(Expense expense) {
    CMarkup expensesFile;

    bool fileExists = expensesFile.Load(EXPENSES_FILE_NAME);

    if (!fileExists) {
        expensesFile.AddElem("Expenses");
    }

    expensesFile.FindElem();
    expensesFile.IntoElem();
    expensesFile.AddElem ("Expense");
    expensesFile.IntoElem();
    expensesFile.AddElem( "ExpenseId", AuxiliaryMethods :: convertIntToString (expense.getExpenseId()) );
    expensesFile.AddElem( "UserId", AuxiliaryMethods :: convertIntToString (expense.getUserId()) );
    expensesFile.AddElem( "Date", expense.getDate() );
    expensesFile.AddElem( "Item", expense.getItem() );
    expensesFile.AddElem( "Amount", AuxiliaryMethods :: convertDoubleToString (expense.getAmount()) );
    expensesFile.Save( EXPENSES_FILE_NAME );
    lastExpenseId++;

}
