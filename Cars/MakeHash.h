#pragma once
#include "AutonomousCar.h"

class MakeHash
{
public:
	MakeHash();
	virtual ~MakeHash();
	void HasH(AutonomousCar** cars, int size);

	AutonomousCar** getABCD() { return ABCD; }
	AutonomousCar** getEFGH() { return EFGH; }
	AutonomousCar** getIJKL() { return IJKL; }
	AutonomousCar** getMNOP() { return MNOP; }
	AutonomousCar** getQRST() { return QRST; }
	AutonomousCar** getUVW() { return UVW; }
	AutonomousCar** getXYZ() { return XYZ; }

	void ToString();

private:
	AutonomousCar** ABCD;
	AutonomousCar** EFGH;
	AutonomousCar** IJKL;
	AutonomousCar** MNOP;
	AutonomousCar** QRST;
	AutonomousCar** UVW;
	AutonomousCar** XYZ;

	void addList(AutonomousCar* car, AutonomousCar** list);
	void stringList(AutonomousCar** list);

};

