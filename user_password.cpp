#include <iostream>
#include <cctype>
using namespace std;

class Input {
protected:
    string password;
public:
    void getPassword() {
        cout << "Enter a password: ";
        cin >> password;
    }
};

class LengthCheck : public Input {
public:
    bool isLongEnough() {
        return password.length() >= 8;
    }
};

class ComplexityCheck : public LengthCheck {
public:
    bool hasUppercase() {
        for (char c : password)
            if (isupper(c)) return true;
        return false;
    }

    bool hasDigit() {
        for (char c : password)
            if (isdigit(c)) return true;
        return false;
    }

    bool hasSpecialChar() {
        for (char c : password)
            if (!isalnum(c)) return true;
        return false;
    }
};

class PasswordStrength : public ComplexityCheck {
public:
    void checkStrength() {
        if (!isLongEnough()) 
            cout << "Weak Password: Too short (minimum 8 characters required)." << endl;
        else if (!hasUppercase() || !hasDigit() || !hasSpecialChar()) 
            cout << "Moderate Password: Add uppercase, digits, or special characters for strength." << endl;
        else 
            cout << "Strong Password!" << endl;
    }
};

int main() {
    PasswordStrength obj;
    obj.getPassword();
    obj.checkStrength();
    return 0;
}
