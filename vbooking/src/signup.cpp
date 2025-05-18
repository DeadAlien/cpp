#include "signup.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


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


bool SignUp::PasswordCheck(){
    /* 
        use (A-Z), (a-z), (0-9), (@,#,$,%,*) 
        spcae should not be there    
    */

    signup p;
    cin >> p.Password;
    string pas = p.Password;
    int len = pas.length();
    bool capFlag = false;
    bool smallFlag = false;
    bool SpecialCharFlag = false;

    if(len < 12)
    {
        return false;
    }

    for(int i = 0; i < len; i++)
    {
        if((pas[i] >= 'A') && (pas[i] <= 'Z'))
        {
            capFlag = true;
        }
        if((pas[i] >= 'a') && (pas[i] <= 'z'))
        {
            smallFlag = true;
        }
        if((pas[i] == '@') || (pas[i] == '#') 
            || (pas[i] == '$') || (pas[i] == '%') 
            || (pas[i] == '*'))
        {
            SpecialCharFlag = true;
        }
    }

    if((capFlag == true) && (smallFlag == true) && (SpecialCharFlag == true))
    {
        return true;
    }
    
    return false;
}

void SignUp::RegisterNewAccount(void){
/* Using this fucntion user can create there account and the given info will save in 
information file (Information file is creating in this function).
*/
    signup b;
    std::cout << "Register New Account" << std::endl;

    std::cout << "Name: " << endl;
    std::cin >> b.UserName;
    std::cout << "Email: " << endl;
    if(b.EmailVerification() != true)
    {
        std::cout << "Please enter valid email." << std::endl; 
        return;
    }
    std::cout << "Password: " << endl;
    if(b.PasswordCheck() != true)
    {
        std::cout << "Pasword should contain: Atlist 12 char (A-Z), (a-z), (0-9), (@,#,$,%,*)" << std::endl;
        return;
    }

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

    std::cout << "Press Enter to return to the main menu..." << std::endl;
    std::cin.get();
}
