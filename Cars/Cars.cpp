#include <iostream>
#include "AutonomousCar.h"
#include "YearHash.h"
#include "AiHash.h"
#include "MakeHash.h"

typedef struct Signature {
	string school;
	string semester;
	string course;
	string name;
	string studentid;
	void ToString() { cout << school << " " << semester << " " << course << " " << name << " " << studentid << endl; }
} Signature;



int main()
{
	Signature Ryan;
	Ryan.school = "Sheridan Colledge";
	Ryan.semester = "2024W";
	Ryan.course = "PROG23672";
	Ryan.name = "Ryan Barkman";
	Ryan.studentid = "991690389";
	Ryan.ToString();


	AutonomousCar* c1 = new AutonomousCar("Tesla", "Model 3", 2024, "Alexa");
	AutonomousCar* c2 = new AutonomousCar("Chrysler", "Pacifica", 2021, "Echo");
	AutonomousCar* c3 = new AutonomousCar("Kia", "Niro", 2022, "Siri");
	AutonomousCar* c4 = new AutonomousCar("Volkswagen", "Jetta", 2023, "Alexa");
	AutonomousCar* c5 = new AutonomousCar("Hyundai", "Ioniq", 2024, "Siri");
	AutonomousCar* c6 = new AutonomousCar("Toyota", "Prius", 2023, "Cortana");
	AutonomousCar* c7 = new AutonomousCar("Audi", "Model 3", 2022, "Echo");
	AutonomousCar* c8 = new AutonomousCar("Ford", "Maverick", 2020, "Cortana");
	AutonomousCar* c9 = new AutonomousCar("GM", "Model 3", 2021, "Cortana");
	AutonomousCar* c10 = new AutonomousCar("Hyundai", "Santa Fe", 2018, "Echo");

	AutonomousCar** List = new AutonomousCar * [10];
	List[0] = c1;
	List[1] = c2;
	List[2] = c3;
	List[3] = c4;
	List[4] = c5;
	List[5] = c6;
	List[6] = c7;
	List[7] = c8;
	List[8] = c9;
	List[9] = c10;

	MakeHash* hasher = new MakeHash();
	hasher->HasH(List, 10);
	hasher->ToString();

	delete hasher;
	delete[] List;

}