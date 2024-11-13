#pragma once
#include <string>
#include <iostream>
using namespace std;

class AutonomousCar
{
public:
	AutonomousCar();
	AutonomousCar(string _make, string _model, int _year, string _ai);
	AutonomousCar(const AutonomousCar& _car);
	virtual ~AutonomousCar();

	string getMake();
	string getModel();
	int getYear();
	string getAi();
	void setAi(string _ai);


	string toString();

private:
	string make;
	string model;
	int year;
	string ai;

};

