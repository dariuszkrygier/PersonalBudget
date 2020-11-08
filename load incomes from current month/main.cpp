#include <iostream>

using namespace std;
vector <Income> FinancialOperationsManager::loadIncomesOnlyFromCurrentMonth() {
    Income income;
    vector <Income> incomesOnlyFromCurrentMonth;
    int currentYear = auxiliaryMethods.downloadCurrentYear();
    int currentMonth = auxiliaryMethods.downloadCurrentMonth();
    vector <Income>::iterator itr = incomes.begin();
    while (itr != incomes.end()) {
        string date = itr -> downloadDate();
        int yearFromUsersDate = auxiliaryMethods.downloadYearFromOperationDate(date);
        int monthFromUsersDate = auxiliaryMethods.downloadMonthFromOperationDate(date);
        if (yearFromUsersDate == currentYear && monthFromUsersDate == currentMonth) {
            income.setIncomeId(itr -> downloadIncomeId());
            income.setUserId(itr -> downloadUserId());
            income.setDate(itr -> downloadDate());
            income.setItem(itr -> downloadItem());
            income.setAmount(itr -> downloadAmount());
            income.setDateAsUnixTime(auxiliaryMethods.changeDateFormatForUnixTime(itr -> downloadDate()));
            incomesOnlyFromCurrentMonth.push_back(income);
        }
        itr++;
    }
    return incomesOnlyFromCurrentMonth;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
