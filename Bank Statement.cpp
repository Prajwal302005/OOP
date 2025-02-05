#include <iostream>
using namespace std;

struct Record {
    int serialNo;
    int transactionAmount;
    int currentBalance;
};

int main() {
    int balance = 0, choice, amount, transactionCount = 0;
    Record transactions[100]; 

    while (true) {
        cout << "\n========= BANK MENU =========\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. View Transactions\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    transactions[transactionCount].serialNo = transactionCount + 1;
                    transactions[transactionCount].transactionAmount = amount;
                    transactions[transactionCount].currentBalance = balance;
                    transactionCount++;
                    cout << "Deposit successful!\n";
                } else {
                    cout << "Invalid amount.\n";
                }
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    transactions[transactionCount].serialNo = transactionCount + 1;
                    transactions[transactionCount].transactionAmount = -amount;
                    transactions[transactionCount].currentBalance = balance;
                    transactionCount++;
                    cout << "Withdrawal successful!\n";
                } else if (amount > balance) {
                    cout << "Insufficient funds.\n";
                } else {
                    cout << "Invalid amount.\n";
                }
                break;

            case 3:
                if (transactionCount == 0) {
                    cout << "No transactions available.\n";
                } else {
                    cout << "\n========== TRANSACTION RECORD ==========" << endl;
                    cout << "| No | Amount      | Balance     |" << endl;
                    cout << "------------------------------------" << endl;
                    for (int i = 0; i < transactionCount; i++) {
                        cout << "| " << transactions[i].serialNo << "  | "
                             << transactions[i].transactionAmount << "          | "
                             << transactions[i].currentBalance << "         |" << endl;
                    }
                    cout << "------------------------------------\n";
                }
                break;

            case 4:
                cout << "Exiting program. Have a great day!\n";
                return 0;

            default:
                cout << "Invalid selection. Please try again.\n";
        }
    }

    return 0;
}

