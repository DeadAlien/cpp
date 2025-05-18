#include<iostream>
#include<fstream>

using namespace std;

class FileOperation {
	string readData;
public:
	void write_file(){

		ofstream outFile("dev"); //open file in write mode and file name is dev
		
		if(outFile.is_open())
		{
			outFile << "enter data in file" << endl;
			outFile.close();
		}
		else
		{
			cout << "error" << endl;
		}

	}

	void read_file(){
		ifstream inFile("dev");

		if(inFile.is_open()){
			while(getline(inFile, readData))
			{
				cout << readData << endl;
			}
			inFile.close();
		}
		else
		{
			cout << "error in reading" << endl;
		}
	}
};

int main()
{
	FileOperation a; 

	a.write_file();
	a.read_file();
}
