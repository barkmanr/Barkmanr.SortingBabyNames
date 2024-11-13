#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream> 
#include <iostream>
using namespace std;
class Baby
{
public:
	Baby();
	virtual ~Baby();
	
	void ReadFile(int year);
	string getRank(string gender, string name );
	string** FindCommon();
	string** Top10Unique(string gender);

	void toString();

private:
	string** maleNames;
	int* maleNumbers;
	string** femaleNames;
	int* femaleNumbers;

};

