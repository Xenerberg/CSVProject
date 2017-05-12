// CSVProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CSVStream.h"
#include "DS.h"
#include "Utility.h"
#include <string>
using namespace std;
using namespace NM_CSVProject;
using namespace NM_DS;
using namespace NM_Utility;
int main(int argc, char* argv[])
{
	
	string strin;
	string strout;
	std::cout << "Test for CSV file operations\n";
	if (argc != 3)
	{
		std::cout << "Number of arguments is not correct. Proceeding with default. \n";
		std::cout << "Enter valid input filename with correct path:" << std::endl;		
		std::cin >> strin;
		std::cout << "Enter valid output filename with correct path:" << std::endl;
		std::cin >> strout;
	}
	else if (argc == 3)
	{
		strin = argv[1];
		strout = argv[2];		
	}
	struct stat buffer;
	if (stat(strin.c_str(), &buffer) == 0) {
		CSVStream obj(strin);
		NM_DS::mat_obj matObj = obj.read();
		Funct_MeanInterp functObj(matObj);
		NM_DS::mat_obj filteredObj = functObj();
		obj.writeMat(strout, filteredObj);
		cout << "File was filtered and stored.";

	}
	else
	{
		cout << "File was not found. Please try again.";

	}
	//getchar();
	if (getchar() > 0)
		return 0;
	
}

