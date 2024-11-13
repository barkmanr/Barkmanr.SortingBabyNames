#include "AiHash.h"

AiHash::AiHash()
{
	Alexa = new AutonomousCar * [50];
	Cortana = new AutonomousCar * [50];
	Echo = new AutonomousCar * [50];
	Siri = new AutonomousCar * [50];
	Other = new AutonomousCar * [50];

	for (int i = 0; i < 50; i++)
	{
		Alexa[i] = nullptr;
		Cortana[i] = nullptr;
		Echo[i] = nullptr;
		Siri[i] = nullptr;
		Other[i] = nullptr;
	}
}

AiHash::~AiHash()
{
	for (int i = 0; i < 50; i++)
	{
		if (Alexa[i] != nullptr) delete Alexa[i];
		if (Cortana[i] != nullptr) delete Cortana[i];
		if (Echo[i] != nullptr) delete Echo[i];
		if (Siri[i] != nullptr) delete Siri[i];
		if (Other[i] != nullptr) delete Other[i];
	}


	delete[] Alexa;
	delete[] Cortana;
	delete[] Echo;
	delete[] Siri;
	delete[] Other;
}

void AiHash::HasH(AutonomousCar** cars, int size)
{
	for (int i = 0; i < size; i++)
	{
		AutonomousCar* C = cars[i];

		if (C->getAi() == "Alexa") 
		{
			addList(C, Alexa);
		}
		else if (C->getAi() == "Cortana")
		{
			addList(C, Cortana);
		}
		else if (C->getAi() == "Echo")
		{
			addList(C, Echo);

		}
		else if (C->getAi() == "Siri")
		{
			addList(C, Siri);
		}
		else
		{
			addList(C, Other);
		}
	}
}

void AiHash::addList(AutonomousCar* car, AutonomousCar** list)
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

void AiHash::ToString()
{
	cout << endl << "Alexa" << endl;
	stringList(Alexa);

	cout << endl << "Cortana" << endl;
	stringList(Cortana);

	cout << endl << "Echo" << endl;
	stringList(Echo);

	cout << endl << "Siri" << endl;
	stringList(Siri);

	cout << endl << "Other" << endl;
	stringList(Other);
}

void AiHash::stringList(AutonomousCar** list)
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
