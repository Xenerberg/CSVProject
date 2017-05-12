// Sorter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "Funct_Sorter.h"
using namespace NM_Utility;

int main()
{
	std::vector<double> vecObj{ 1,5,2,7,-10,9,10 };	
	std::vector<std::string> strObj{ "a","x","y","e","de","ef","e" };	
	Funct_Sorter<double,string> functObj;
	functObj(vecObj, strObj);
	
	cout << "The sorted values are: "<<"\n";
	for (auto i : vecObj)
	{
		cout << i << "\t";
	}
	
	if (getchar() > 0)
		return 0;
}

