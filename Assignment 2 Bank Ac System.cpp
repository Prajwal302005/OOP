#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    string accountType;
    double balance;

public:
    BankAccount() : accountHolder(""), accountNumber(0), accountType("Savings"), balance(0.0) {}

    BankAccount(string holder, int number, string type, double bal) {
        accountHolder = holder;
        accountNumber = number;
        accountType = type;
        balance = bal;
    }

    string getAccountHolder() { return accountHolder; }
    int getAccountNumber() { return accountNumber; }
    string getAccountType() { return accountType; }
    double getBalance() { return balance; }

    void setAccountType(string newType) { accountType = newType; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Depositing " << amount << "..." << endl;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawing " << amount << "..." << endl;
            cout << "New Balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    void displayAccountDetails() {
        cout << "\nAccount Details:" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    string holder, type;
    int number;
    double bal, amount;

    cout << "Enter account holder name: ";
    getline(cin, holder);
    cout << "Enter account number: ";
    cin >> number;
    cout << "Enter account type (Savings/Current): ";
    cin >> type;
    cout << "Enter initial balance: ";
    cin >> bal;

    BankAccount acc(holder, number, type, bal);

    acc.displayAccountDetails();

    cout << "\nEnter amount to deposit: ";
    cin >> amount;
    acc.deposit(amount);

    cout << "\nEnter amount to withdraw: ";
    cin >> amount;
    acc.withdraw(amount);

    cout << "\nEnter new account type: ";
    cin >> type;
    acc.setAccountType(type);
    cout << "Updated Account Type to " << type << "." << endl;

    acc.displayAccountDetails();
    
    return 0;
}

