#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Phone
{
public:
	Phone() 
	{
		phoneNum = 0;
		firstname = nullptr;
		lastname = nullptr;
	}
	Phone(long long num, string _first, string _last)
	{
		phoneNum = num;

		string* first = new string();
		*first = _first;
		firstname = first;

		string* last = new string();
		*last = _last;
		lastname = last;
	}

	Phone(long long num, string* _first, string* _last)
	{
		phoneNum = num;
		firstname = _first;
		lastname = _last;
	}

	virtual ~Phone() 
	{
		delete firstname;
		delete lastname;
	}
	
	long long getPhoneNum() 
	{
		return phoneNum;
	}

	string getFirstName() 
	{
		return *firstname;
	}

	string getLastName() 
	{
		return *lastname;
	}

	string toString() 
	{
		string n = to_string(phoneNum);
		return *lastname + ", " + *firstname + ": (" + n[0] + n[1] + n[2] + ") " + n[3] + n[4] + n[5] + "-" + n[6] + n[7] + n[8] + n[9];
	}

	void save(ofstream& stream);
	void load(ifstream& stream);

private:
	long long phoneNum;
	string* firstname;
	string* lastname;
};