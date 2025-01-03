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
	
	bool ReadFile(int year);
	string getRank(string gender, string name );
	void FindCommon();
	string** getCommon();
	string** Top10Unique(string gender);

	void toString();

private:
	string** maleNames;
	int* maleNumbers;
	string** femaleNames;
	int* femaleNumbers;
	string** commonNames;

};

