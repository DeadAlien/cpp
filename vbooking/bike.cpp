#include <iostream>
#include <string>
#include <fstream>
typedef class Bike{
	int RegNo;
	std::string BikeType;
	bool BookedStatus;
public:
	Bike(): RegNo(0), BikeType("NONE"), BookedStatus(0){}

	void storeVehicle_info(int regno, std::string biketype, bool status);
	bool checkAvailability();

	~Bike(){}
}bike;

void bike::storeVehicle_info(int regno, std::string biketype, bool status){

	std::ofstream outFile("data");
	if(!outFile)
	{
		std::cout << "Error: Could not open file for writing." << std::endl;
		return;
	}
	
	outFile << regno << " - " << biketype << " - " <<  status << std::endl;
	
	/*outFile << "Registration Number: " << regno << '\n';
    	outFile << "Bike Type: " << biketype << '\n';
    	outFile << "Status: " << (status ? "Available" : "Unavailable") << '\n';*/
	outFile.close();

	std::cout << "Info saved!!" << std::endl;
}

bool bike::checkAvailability (){
	
	std::string tempbuffer;
	std::ifstream inFile("data");
	if(!inFile)
	{
		std::cout << "Error: could not open for reading." << std::endl;
		return false;
	}
	auto j = 0;
	auto flag = false;
	while(j < 10){
		while(std::getline(inFile, tempbuffer))
		{
			for(int i = 0; i < tempbuffer.length(); i++)
			{
				if(tempbuffer[i] == '-')
				{
					flag = true;
				}
				else if((flag != true) && (tempbuffer[tempbuffer.length()-1] != '1'))
				{
					std::cout << tempbuffer[i];
				}
				if(((tempbuffer[i] == '0') /*|| (tempbuffer[i] == '1')*/) && (tempbuffer[i+1] == '\0'))
				{
					std::cout <<"Avaialble :"<< tempbuffer[i] << std::endl;
				}
			}
			flag = false;
		}
		flag = false;
		j++;
	}
	inFile.close();
	return false;
}

int main(){
	bike a;
		//a.storeVehicle_info(123, "A", 0);
		a.checkAvailability();
	
}
