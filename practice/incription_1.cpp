#include<iostream>
#include <termios.h>
#include <unistd.h>
using namespace std;

void setStdinEcho(bool enable) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (!enable)
        tty.c_lflag &= ~(ECHO); // Disable echo
    else
        tty.c_lflag |= ECHO;    // Enable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

int main()
{
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

}

/*
#include <iostream>
#include <termios.h>
#include <unistd.h>

void setStdinEcho(bool enable) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if (!enable)
        tty.c_lflag &= ~(ECHO); // Disable echo
    else
        tty.c_lflag |= ECHO;    // Enable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

int main() {
    std::string password;
    char ch;

    std::cout << "Enter your password: ";
    setStdinEcho(false);  // Disable echo

    while (true) {
        ch = getchar();
        if (ch == '\n') break;      // Enter key ends input
        if (ch == 127 || ch == '\b') {  // Handle backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";
            }
        } else {
            password += ch;
            std::cout << '*';
        }
    }

    setStdinEcho(true);  // Re-enable echo
    std::cout << "\nPassword entered: " << password << std::endl;

    return 0;
}
*/