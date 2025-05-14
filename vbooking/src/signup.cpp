#include "signup.h"

SignUp::SignUp(){
    std::cout << "Signup Object is created" << std::endl;
}

void SignUp::RegisterNewAccount(void){
    signup b;
    std::cout << "Register New Account" << std::endl;

    std::cout << "Name: " << endl;
    std::cin >> b.UserName;
    std::cout << "Email: " << endl;
    std::cin >> b.Email;
    std::cout << "Password: " << endl;
    std::cin >> b.Password;

    std::ofstream fopen("information");

    if(!fopen)
    {
        std::cout << "Error:Information: Could not open file for writing." << std::endl;
        return;
    }
    else
    {
        /* follow standard template.*/
    }
    fopen << b.UserName << "--" << b.Email << "--" << b.Password << std::endl;
    fopen.close();
    std::cout << "Info saved!!" << std::endl;
}

bool EmailVerification(){
    return false;
}

SignUp::~SignUp(){
    std::cout << "Signup Object is destroyed" << std::endl;
}

int main(){
    std::cout << "WELCOME TO VEHICLE BOOKING" << std::endl;
    char opt = NULL ;
    while(1)
    {
        std::cout << "1) Register New Account" << std::endl;
        std::cout << "\n2) Login" << std::endl;
        std::cout << "\n3) Exit" << std::endl;
        std::cin >> opt;

        signup a;
        switch(opt)
        {
            case '1':
                   a.RegisterNewAccount();
                   break;
            case '2':break;
            case '3': return 0; break;
            default: [](char opt)
                        {
                            std::cout << opt << " is invalid option. Please choose correct option." << std::endl;
                        }(opt); 
                        break;
        }
    }
}