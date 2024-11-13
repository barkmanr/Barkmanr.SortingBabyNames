#include "PhoneApp.h"

PhoneApp::PhoneApp() 
{
	phones = new Phone*[1000];
	for (int i = 0; i < 1000; i++) 
	{
		phones[i] = nullptr;
	}
	size = 0;
}

PhoneApp::~PhoneApp() 
{
	for (int i = 0; i < size; i++)
	{
			delete phones[i];
	}
	delete[] phones;
}

void PhoneApp::ShowAll() 
{
	for (int i = 0; i < size; i++) 
	{
		cout << phones[i]->toString() << endl;
	}
}

void PhoneApp::Add(Phone* phone) 
{
	phones[size] = phone;
	size++;
}

void PhoneApp::Delete(string _name)
{
	for (int i = 0; i < size; i++)
	{
		if (phones[i]->getLastName() == _name)
		{
			delete phones[i];
			phones[i] = nullptr;
			size--;
			for (int j = i; j < size; j++) 
			{
				dswap(j);
			}
			return;
		}
	}
	cout << "sorry - couldn't find name" << endl;
}

void PhoneApp::dswap(int index) 
{
	phones[index] = phones[index + 1];
	phones[index + 1] = nullptr;
}

Phone* PhoneApp::Retrieve(string _name)
{
	for (int i = 0; i < size; i++)
	{
		if (phones[i]->getLastName() == _name)
		{
			return phones[i];
		}
	}
	cout << "sorry - couldn't find name" << endl;
	return nullptr;
}

void PhoneApp::Sort() 
{
	QuickSort(0, size-1);
}


void PhoneApp::QuickSort(int start, int end) 
{
	if (start >= end) 
	{
		return;
	}
	int Pindex = Partion(start, end);
	QuickSort(start, Pindex - 1);
	QuickSort(Pindex + 1, end);
}


int PhoneApp::Partion(int start, int end) 
{
	Phone* pivot = phones[end];
	int Pindex = start;
	for (int i = start; i < end; i++) 
	{
		if (compareAlphabetically(phones[i]->getLastName(), pivot->getLastName()) == 2)
		{
			swap(i, Pindex);
			Pindex +=1;
		}
	}
	swap(Pindex, end);
	return Pindex;
}

int PhoneApp::compareAlphabetically(string str1, string str2)

{

	for (int i = 0; i < str1.length() && i < str2.length(); i++)
	{
		if (str1[i] == str2[i]) 
		{
			continue;
		}
		else if (str1[i] > str2[i])
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	return 2;
}

void PhoneApp::swap(int f, int s) 
{
	Phone* temp = phones[f];
	phones[f] = phones[s];
	phones[s] = temp;
}

void PhoneApp::Save()
{
	ofstream writeStream("phone.bin", ios::out | ios::binary);
	writeStream.write(reinterpret_cast<char*>(&size), sizeof(size));
	for (int i = 0; i < size; i++)
	{
		phones[i]->save(writeStream);
	}

	writeStream.close();
}

void PhoneApp::Load()
{
	for (int i = 0; i < size; i++)
	{
		delete phones[i];
		phones[i] = nullptr;
	}

	ifstream readStream("phone.bin", ios::out | ios::binary);
	readStream.read(reinterpret_cast<char*>(&size), sizeof(size));
	for (int i = 0; i < size; i++)
	{
		Phone* P = new Phone();
		P->load(readStream);
		phones[i] = P;
	}

	readStream.close();
}
