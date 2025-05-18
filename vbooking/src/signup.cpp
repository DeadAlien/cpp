#include "signup.h"

SignUp::SignUp(){
    //std::cout << "Signup Object is created" << std::endl;
}

void SignUp::RegisterNewAccount(void){
/* Using this fucntion user can create there account and the given info will save in 
information file (Information file is creating in this function).
*/
    signup b;
    std::cout << "Register New Account" << std::endl;

    // std::cout << "Name: " << endl;
    // std::cin >> b.UserName;
    std::cout << "Email: " << endl;
    if(b.EmailVerification() != true)
    {
        std::cout << "Please enter valid email." << std::endl; 
    }
    // std::cout << "Password: " << endl;
    // std::cin >> b.Password;

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

bool SignUp::EmailVerification(){
/*Email verification code whicle can verify email syntex like name@domain.com
some domain like gmail.com, yahoo.com, yahoo.in, hotmain.in, msn.com
*/
/*
    1. Check string '@' and '.' present or not.
    2. Make sure that it should not present in start and end of the sttring.
    3. '.' should present after '@'. 
    4. Space should not be present.
*/

    signup ev;
    cin >> ev.Email;
    string email = ev.Email;
    int atindex = -1;
    int dotindex = -1;
    int len = email.length();
    char ch;
    for(int i = 0; i < len; i++)
    {
        ch = email[i];

        if((ch == ' ' ))
        {
            cout << "dev_ not valid" << endl;
             return false;
        }
        if(ch == '@')
        {
            atindex = i; 
        }
        if(ch == '.')
        {
            dotindex = i;
        }

        if( (dotindex > atindex) && (atindex != 0) && (atindex != len)
            && (dotindex != 0) && (dotindex != len) 
        )
        {
            return true;
        }
    }
    return false;
}

SignUp::~SignUp(){
   // std::cout << "Signup Object is destroyed" << std::endl;
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