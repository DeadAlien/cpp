// #include <iostream>
// #include <string>
// #include <fstream>
// typedef class Bike{
// 	int RegNo;
// 	std::string BikeType; /* which kind of bike it*/
// 	bool BookedStatus; /* Showing status bike is booked or not */
// 	int NumberOfBikes[3]; /*1st index: Total number of bike; 2nd index: Available bikes; 3rd index: Booked bikes*/
// public:
// 	Bike(): RegNo(0), BikeType("NONE"), BookedStatus(0){}

// 	void storeVehicle_info(int regno, std::string biketype, bool status);
// 	bool checkAvailability();
// 	int BikeCount();

// 	~Bike(){}
// }bike;

// int bike::BikeCount(){
// 	// std::ifstream inFile("data");
// 	// int count = NULL; 

// 	// if(!inFile)
// 	// {
// 	// 	std::cout << "Error: could not open for reading." << std::endl;
// 	// 	return;
// 	// }

// 	// while()
// 	return 0;

// }

// void bike::storeVehicle_info(int regno, std::string biketype, bool status){

// 	std::ofstream outFile("data");
// 	if(!outFile)
// 	{
// 		std::cout << "Error: Could not open file for writing." << std::endl;
// 		return;
// 	}
	
// 	outFile << regno << " - " << biketype << " - " <<  status << std::endl;
	
// 	outFile.close();

// 	std::cout << "Info saved!!" << std::endl;
// }

// bool bike::checkAvailability (){
	
// 	std::string tempbuffer;
// 	std::ifstream inFile("data");
// 	if(!inFile)
// 	{
// 		std::cout << "Error: could not open for reading." << std::endl;
// 		return false;
// 	}
// 	std::cout << "Available Bikes:" << std::endl;
// 	while(std::getline(inFile, tempbuffer))
// 	{
// 		if((tempbuffer[tempbuffer.length()-1]) != '1')
// 		{
// 			std::cout << tempbuffer << std::endl;
// 		}
// 	}
// 	inFile.close();
// 	return false;
// }

// int main(){
// 	bike a;
// 		//a.storeVehicle_info(123, "A", 0);
// 		a.checkAvailability();
	
// }
