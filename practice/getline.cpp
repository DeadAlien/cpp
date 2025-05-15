/* File operation to understand getline function */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("data");
    string temp; 

    if(!f)
    {
        cout << "error" << endl; 
    }
    if(getline(f, temp)){
        cout << temp << endl;
    }
}