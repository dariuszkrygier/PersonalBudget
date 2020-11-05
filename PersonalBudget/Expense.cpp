#include "Expense.h"

void Expense :: setExpenseId(int newExpenseId) {
    if (newExpenseId >= 0)
        expenseId = newExpenseId;
}
void Expense :: setUserId(int newUserId) {
    userId = newUserId;
}
void Expense :: setDate (string newDate) {
    date = newDate;
}
void Expense :: setItem (string newItem) {
    item = newItem;
}
void Expense :: setAmount (double newAmount) {
    amount = newAmount;
}

int Expense :: getExpenseId() {
    return expenseId;
}
int Expense :: getUserId() {
    return userId;
}
string Expense :: getDate() {
    return date;
}
string Expense :: getItem() {
    return item;
}
double Expense :: getAmount() {
    return amount;
}
