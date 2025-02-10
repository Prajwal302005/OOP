#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double salary;

public:
    Employee(string empName, double empSalary) {
        name = empName;
        salary = empSalary;
    }

    void increaseSalary(double percentage) {
        salary += (salary * percentage / 100);
    }

    void display() {
        cout << "Employee: " << name << ", Salary: " << salary << endl;
    }
};

int main() {
    Employee e1("John", 50000);
    e1.increaseSalary(10);
    e1.display();

    return 0;
}
