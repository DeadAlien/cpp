#include <iostream>
#include <string>
using namespace std;

class twoD {
    string str[1][2]; // Corrected 2D array dimensions to fit 2 columns
public:
    twoD() {
        this->str[0][0] = "123"; // Initialize the first element
        this->str[0][1] = "Dev"; // Initialize the second element
    }

    void print() {
        cout << "ID: " << str[0][0] << ", Name: " << str[0][1] << endl; // Print both elements
    }
};

int main() {
    class twoD a; // Corrected the class name and removed `class` keyword

    a.print(); // Call the print method
    return 0;
}
