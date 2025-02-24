#include <iostream>
using namespace std;

class Celsius {
protected:
    double tempC;
public:
    void getTemperature() {
        cout << "Enter temperature in Celsius: ";
        cin >> tempC;
    }
};

class Fahrenheit : public Celsius {
public:
    double toFahrenheit() {
        return (tempC * 9 / 5) + 32;
    }
};

class Kelvin : public Fahrenheit {
public:
    double toKelvin() {
        return tempC + 273.15;
    }
};

int main() {
    Kelvin obj;
    obj.getTemperature();

    cout << "Temperature in Fahrenheit: " << obj.toFahrenheit() << "°F" << endl;
    cout << "Temperature in Kelvin: " << obj.toKelvin() << "K" << endl;

    return 0;
}
