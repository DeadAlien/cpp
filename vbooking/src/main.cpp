#include "main.h"
#include "signup.h"
#include <iostream>
#include <cstdlib>

void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/macOS
#endif
}

int main(){


    std::cout << "WELCOME TO VEHICLE BOOKING" << std::endl;
    char opt = '\0' ;
    signup signupObj;
    while(1)
    {
        clearScreen();
        std::cout << "1) Register New Account" << std::endl;
        std::cout << "\n2) Login" << std::endl;
        std::cout << "\n3) Exit" << std::endl;
        std::cin >> opt;

        signup a;
        switch(opt)
        {
            case '1':
                        signupObj.RegisterNewAccount();
                        break;
            case '2':break;
            case '3': 
                        std::cout << "Exiting the program. Thank you for using Vehicle Booking!" << std::endl;return 0; break;
            default: [](char opt)
                        {
                            std::cout << opt << " is invalid option. Please choose correct option." << std::endl;
                        }(opt); 
                        break;
        }
    }
}