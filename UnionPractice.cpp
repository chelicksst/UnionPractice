#include <iostream>
#include <windows.h>
using namespace std;

struct sensor {
private:
    enum types 
    {
        FLOAT, 
        INT, 
        BOOL
    } type;

    union {
        float temperature;
        int humidity;
        std::byte illumination;
    };

public:

    explicit sensor(float temperature) : type(FLOAT), temperature(temperature) {}
    explicit sensor(int humidity) : type(INT), humidity(humidity) {}
    explicit sensor(std::byte illumination) : type(BOOL), illumination(illumination) {}

    void display() const {
        switch (type)
        {
        case sensor::FLOAT:
            cout << "Temperature: " << temperature << "°C\n";
            break;
        case sensor::INT:
            cout << "Humidity: " << humidity << endl;
            break;
        case sensor::BOOL:
            cout << "Illumination: " << 
                (to_integer<uint8_t>(illumination) == 1 ? "Light" : "Dark")
                << endl;
            break;
        default:
            throw runtime_error("UNDEFINED TYPE!");
            break;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    sensor s1(5);
    s1.display();
    sensor s2(6.7f);
    s2.display();
    std::byte il{ 1 };
    sensor s3(il);
    s3.display();
}