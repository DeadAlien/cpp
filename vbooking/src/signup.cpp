/*use can enter there details and crate account, info going to save in flile 
future scope: integrate with Data base management system.
.*/


#include "signup.h"

void signup::SignUp(void){

    string name, email, password;

    std::cout << "Name: " << endl;
    std::cin >> name;
    std::cout << "Email ID: " << std::endl;
    std::cin >> email;
    std::cout << "Password: " << std::endl;
    PasswordCheck();
}

/* use A-Z, a-z, 0-9, !@#$%^&* */
bool PasswordCheck(){
    std::string password;
    char ch;
    char i = 0;
    setStdinEcho(false);
    while (i < 12) {
    ch = getchar();
    if ((ch == '\n') && (i > 11)) break;    // Enter pressed → break loop

    if (ch == 127 || ch == '\b') {  // Backspace
        if (!password.empty()) {
            password.pop_back();         // Remove last char
            std::cout << "\b \b";        // Move back, print space, move back again
        }
    } else {
        password += ch;
        std::cout << '*';                // Show * instead of char
    }
    i++;
    setStdinEcho(true);
}

int main(){

}