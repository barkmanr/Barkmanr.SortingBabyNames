#pragma once
#include "AutonomousCar.h"
class AiHash
{
public:
	AiHash();
	virtual ~AiHash();
	void HasH(AutonomousCar** cars, int size);

	AutonomousCar** getAlexa() { return Alexa; }
	AutonomousCar** getCortana() { return Cortana; }
	AutonomousCar** getEcho() { return Echo; }
	AutonomousCar** getSiri() { return Siri; }
	AutonomousCar** getOther() { return Other; }

	void ToString();


private:
	AutonomousCar** Alexa;
	AutonomousCar** Cortana;
	AutonomousCar** Echo;
	AutonomousCar** Siri;
	AutonomousCar** Other;

	void addList(AutonomousCar* car, AutonomousCar** list);
	void stringList(AutonomousCar** list);
};

