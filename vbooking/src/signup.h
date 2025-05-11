#include <iostream>
using namespace std;

typedef class SignUp{
    string UserName;
    string Email;
    string Password;
public:
    SignUp();
    void SignUp(void);
    bool EmailVerification();
    bool PasswordCheck(); /* use A-Z, a-z, 0-9, !@#$%^&* */
    void PasswordEncription(); /* need to learn first*/

    ~SignUp();
}signup;
