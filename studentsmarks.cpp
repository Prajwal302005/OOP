#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    float marks;

public:
    // Function to set student details
    void setDetails(string n, int a, float m) {
        name = n;
        age = a;
        marks = m;
    }

    // Function to display student details
    void display() {
        cout << "Student Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s1; // Object of Student class

    // Setting details
    s1.setDetails("John", 20, 85.5);

    // Displaying details
    s1.display();

    return 0;
}
