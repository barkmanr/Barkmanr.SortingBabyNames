#pragma once
#include "Phone.h"

class PhoneApp
{
public:
	PhoneApp();
	virtual ~PhoneApp();

	void Add(Phone* phone);
	void Delete(string _name);
	Phone* Retrieve(string _name);
	void Sort();
	void Save();
	void Load();

	void ShowAll();

private:
	Phone** phones;
	int size;
	
	void dswap(int index);
	void QuickSort(int start, int end);
	int Partion(int start, int end);
	int compareAlphabetically(string str1, string str2);
	void swap(int f, int s);
};

