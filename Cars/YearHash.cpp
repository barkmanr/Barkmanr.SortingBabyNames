#include "YearHash.h"

YearHash::YearHash() 
{
	y2018 = new AutonomousCar * [50];
	y2019 = new AutonomousCar * [50];
	y2020 = new AutonomousCar * [50];
	y2021 = new AutonomousCar * [50];
	y2022 = new AutonomousCar * [50];
	y2023 = new AutonomousCar * [50];
	y2024 = new AutonomousCar * [50];
	B2024 = new AutonomousCar * [50];
	L2018 = new AutonomousCar * [50];

	for (int i = 0; i < 50; i++)
	{
		y2018[i] = nullptr;
		y2019[i] = nullptr;
		y2020[i] = nullptr;
		y2021[i] = nullptr;
		y2022[i] = nullptr;
		y2023[i] = nullptr;
		y2024[i] = nullptr;
		B2024[i] = nullptr;
		L2018[i] = nullptr;
	}
}

YearHash::~YearHash() 
{
	for (int i = 0; i < 50; i++)
	{
		if(y2018[i] != nullptr) delete y2018[i];
		if (y2019[i] != nullptr) delete y2019[i];
		if (y2020[i] != nullptr) delete y2020[i];
		if (y2021[i] != nullptr) delete y2021[i];
		if (y2022[i] != nullptr) delete y2022[i];
		if (y2023[i] != nullptr) delete y2023[i];
		if (y2024[i] != nullptr) delete y2024[i];
		if (B2024[i] != nullptr) delete B2024[i];
		if (L2018[i] != nullptr) delete L2018[i];
	}
	delete[] y2018;
	delete[] y2019;
	delete[] y2020;
	delete[] y2021;
	delete[] y2022;
	delete[] y2023;
	delete[] y2024;
	delete[] B2024;
	delete[] L2018;
}

void YearHash::HasH(AutonomousCar** cars, int size)
{
	for (int i = 0; i < size; i++) 
	{
		AutonomousCar* C = cars[i];
		
		switch (C->getYear()) 
		{
		case 2018:
			addList(C, y2018);
			break;
		case 2019:
			addList(C, y2019);
			break;
		case 2020:
			addList(C, y2020);
			break;
		case 2021:
			addList(C, y2021);
			break;
		case 2022:
			addList(C, y2022);
			break;
		case 2023:
			addList(C, y2023);
			break;
		case 2024:
			addList(C, y2024);
			break;

		default:
			if (C->getYear() > 2024) 
			{
				addList(C, B2024);
			}
			else if (C->getYear() < 2018) 
			{
				addList(C, L2018);
			}
		}
	}
}

void YearHash::addList(AutonomousCar* car, AutonomousCar** list)
{
	for (int i = 0; i < 50; i++) 
	{
		if (list[i] == nullptr) 
		{
			list[i] = car;
			return;
		}
	}
	cout << "Out of space" << endl;
}

void YearHash::ToString() 
{
	cout << endl << "2018" << endl;
	stringList(y2018);

	cout << endl << "2019" << endl;
	stringList(y2019);

	cout << endl << "2020" << endl;
	stringList(y2020);

	cout << endl << "2021" << endl;
	stringList(y2021);

	cout << endl << "2022" << endl;
	stringList(y2022);

	cout << endl << "2023" << endl;
	stringList(y2023);

	cout << endl << "2014" << endl;
	stringList(y2024);

	cout << endl << "More than 2024" << endl;
	stringList(B2024);

	cout << endl << "Less than 2018" << endl;
	stringList(L2018);
}

void YearHash::stringList(AutonomousCar** list) 
{
	for (int i = 0; i < 50; i++)
	{
		if (list[i] == nullptr)
		{
			if (i == 0)
			{
				cout << "none" << endl;
			}
			return;
		}
		cout << list[i]->toString() << endl;
	}
}