#pragma once
#include "AutonomousCar.h"

class YearHash
{
public:
	YearHash();
	virtual ~YearHash();
	void HasH(AutonomousCar** cars, int size);

	AutonomousCar** get2018() { return y2018; }
	AutonomousCar** get2019() { return y2019; }
	AutonomousCar** get2020() { return y2020; }
	AutonomousCar** get2021() { return y2021; }
	AutonomousCar** get2022() { return y2022; }
	AutonomousCar** get2023() { return y2023; }
	AutonomousCar** get2024() { return y2024; }
	AutonomousCar** getB() { return B2024; }
	AutonomousCar** getL() { return L2018; }

	void ToString();

private:
	AutonomousCar** y2018;
	AutonomousCar** y2019;
	AutonomousCar** y2020;
	AutonomousCar** y2021;
	AutonomousCar** y2022;
	AutonomousCar** y2023;
	AutonomousCar** y2024;
	AutonomousCar** B2024; //more
	AutonomousCar** L2018; //less

	void addList(AutonomousCar* car, AutonomousCar** list);
	void stringList(AutonomousCar** list);

};

