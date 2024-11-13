#include "MakeHash.h"

MakeHash::MakeHash()
{
	ABCD = new AutonomousCar * [25];
	EFGH = new AutonomousCar * [25];
	IJKL = new AutonomousCar * [25];
	MNOP = new AutonomousCar * [25];
	QRST = new AutonomousCar * [25];
	UVW = new AutonomousCar * [25];
	XYZ = new AutonomousCar * [25];

	for (int i = 0; i < 25; i++)
	{
		ABCD[i] = nullptr;
		EFGH[i] = nullptr;
		IJKL[i] = nullptr;
		MNOP[i] = nullptr;
		QRST[i] = nullptr;
		UVW[i] = nullptr;
		XYZ[i] = nullptr;
	}
}

MakeHash::~MakeHash() 
{
	for (int i = 0; i < 25; i++)
	{
		if (ABCD[i] != nullptr) delete ABCD[i];
		if (EFGH[i] != nullptr) delete EFGH[i];
		if (IJKL[i] != nullptr) delete IJKL[i];
		if (MNOP[i] != nullptr) delete MNOP[i];
		if (QRST[i] != nullptr) delete QRST[i];
		if (UVW[i] != nullptr) delete UVW[i];
		if (XYZ[i] != nullptr) delete XYZ[i];
	}

	delete[] ABCD;
	delete[] EFGH;
	delete[] IJKL;
	delete[] MNOP;
	delete[] QRST;
	delete[] UVW;
	delete[] XYZ;
}

void MakeHash::HasH(AutonomousCar** cars, int size)
{
	for (int i = 0; i < size; i++)
	{
		AutonomousCar* C = cars[i];
		char M = C->getMake()[0];

		switch (M)
		{
		case 'a':
			addList(C, ABCD);
			break;
		case 'b':
			addList(C, ABCD);
			break;
		case 'c':
			addList(C, ABCD);
			break;
		case 'd':
			addList(C, ABCD);
			break;
		case 'A':
			addList(C, ABCD);
			break;
		case 'B':
			addList(C, ABCD);
			break;
		case 'C':
			addList(C, ABCD);
			break;
		case 'D':
			addList(C, ABCD);
			break;

		case 'e':
			addList(C, EFGH);
			break;
		case 'f':
			addList(C, EFGH);
			break;
		case 'g':
			addList(C, EFGH);
			break;
		case 'h':
			addList(C, EFGH);
			break;
		case 'E':
			addList(C, EFGH);
			break;
		case 'F':
			addList(C, EFGH);
			break;
		case 'G':
			addList(C, EFGH);
			break;
		case 'H':
			addList(C, EFGH);
			break;

		case 'i':
			addList(C, IJKL);
			break;
		case 'j':
			addList(C, IJKL);
			break;
		case 'k':
			addList(C, IJKL);
			break;
		case 'l':
			addList(C, IJKL);
			break;
		case 'I':
			addList(C, IJKL);
			break;
		case 'J':
			addList(C, IJKL);
			break;
		case 'K':
			addList(C, IJKL);
			break;
		case 'L':
			addList(C, IJKL);
			break;


		case 'm':
			addList(C, MNOP);
			break;
		case 'n':
			addList(C, MNOP);
			break;
		case 'o':
			addList(C, MNOP);
			break;
		case 'p':
			addList(C, MNOP);
			break;
		case 'M':
			addList(C, MNOP);
			break;
		case 'N':
			addList(C, MNOP);
			break;
		case 'O':
			addList(C, MNOP);
			break;
		case 'P':
			addList(C, MNOP);
			break;

		case 'q':
			addList(C, QRST);
			break;
		case 'r':
			addList(C, QRST);
			break;
		case 's':
			addList(C, QRST);
			break;
		case 't':
			addList(C, QRST);
			break;
		case 'Q':
			addList(C, QRST);
			break;
		case 'R':
			addList(C, QRST);
			break;
		case 'S':
			addList(C, QRST);
			break;
		case 'T':
			addList(C, QRST);
			break;

		case 'u':
			addList(C, UVW);
			break;
		case 'v':
			addList(C, UVW);
			break;
		case 'w':
			addList(C, UVW);
			break;
		case 'U':
			addList(C, UVW);
			break;
		case 'V':
			addList(C, UVW);
			break;
		case 'W':
			addList(C, UVW);
			break;


		case 'x':
			addList(C, XYZ);
			break;
		case 'y':
			addList(C, XYZ);
			break;
		case 'z':
			addList(C, XYZ);
			break;
		case 'X':
			addList(C, XYZ);
			break;
		case 'Y':
			addList(C, XYZ);
			break;
		case 'Z':
			addList(C, XYZ);
			break;

		

		default:
			;
		}
	}
}

void MakeHash::addList(AutonomousCar* car, AutonomousCar** list)
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

void MakeHash::ToString()
{
	cout << endl << "ABCD" << endl;
	stringList(ABCD);

	cout << endl << "EFGH" << endl;
	stringList(EFGH);

	cout << endl << "IJKL" << endl;
	stringList(IJKL);

	cout << endl << "MNOP" << endl;
	stringList(MNOP);

	cout << endl << "QRST" << endl;
	stringList(QRST);

	cout << endl << "UVW" << endl;
	stringList(UVW);

	cout << endl << "XYZ" << endl;
	stringList(XYZ);
}

void MakeHash::stringList(AutonomousCar** list)
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
