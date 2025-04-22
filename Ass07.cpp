#include <iostream>
#include <string>
#include <stdexcept>

class InsufficientFundsException : public std::exception {
public:
    const char* what() const noexcept override {  
        return "Error: Insufficient funds!";
    }
};

class InvalidTransactionException : public std::exception {
public:
    const char* what() const noexcept override { 
        return "Error: Invalid transaction!";
    }
};

class DivideByZeroException : public std::exception {
public:
    const char* what() const noexcept override { 
        return "Error: Cannot divide by zero!";
    }
};

class BankAccount {
private:
    std::string ownerName; 
    double balance;        

public:
    BankAccount(const std::string& name, double initialDeposit) {
        ownerName = name;
        if (initialDeposit < 0) {
            throw InvalidTransactionException();  
        }
        balance = initialDeposit;
        std::cout << "Creating Account for " << ownerName << " with Initial Deposit: ?" << balance << std::endl;
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw InvalidTransactionException();  
        }
        balance += amount;
        std::cout << "Depositing ?" << amount << " into " << ownerName << "'s Account" << std::endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException(); 
        }
        balance -= amount;
        std::cout << "Withdrawing ?" << amount << " from " << ownerName << "'s Account" << std::endl;
    }

    void transfer(BankAccount& to, double amount) {
        if (amount > balance) {
            throw InsufficientFundsException();  
        }
        withdraw(amount);  
        to.deposit(amount); 
        std::cout << "Transferring ?" << amount << " from " << ownerName << " to " << to.ownerName << std::endl;
    }

    void divideBalance(double divisor) {
        if (divisor == 0) {
            throw DivideByZeroException(); 
        }
        balance /= divisor;
        std::cout << "Dividing balance by " << divisor << ". New balance: ?" << balance << std::endl;
    }

    void display() const {
        std::cout << "Account Owner: " << ownerName << std::endl;
        std::cout << "Account Balance: ?" << balance << std::endl;
    }
};

int main() {
    try {
        BankAccount rahul("Rahul Sharma", 5000);
        BankAccount priya("Priya Verma", 2000);

        rahul.deposit(1000);

        try {
            rahul.withdraw(7000); 
        } catch (const InsufficientFundsException& e) {
            std::cout << e.what() << std::endl;
        }

        rahul.transfer(priya, 3000);

        rahul.display();
        priya.display();

        try {
            rahul.divideBalance(0);  
        } catch (const DivideByZeroException& e) {
            std::cout << e.what() << std::endl;
        }

    } catch (const InvalidTransactionException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

