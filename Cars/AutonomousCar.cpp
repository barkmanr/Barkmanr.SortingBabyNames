#include "AutonomousCar.h"

AutonomousCar::AutonomousCar() 
{
	year = NULL;
}

AutonomousCar::AutonomousCar(string _make, string _model, int _year, string _ai)
{
	make = _make;
	model = _model;
	year = _year;
	setAi(_ai);
}

AutonomousCar::AutonomousCar(const AutonomousCar& _car)
{
	make = _car.make;
	model = _car.model;
	year = _car.year;
	ai = _car.ai;
}

AutonomousCar::~AutonomousCar() { cout << "Deleted" << endl; }

string AutonomousCar::getMake() 
{
	return make;
}

string AutonomousCar::getModel()
{
	return model;
}

int AutonomousCar::getYear()
{
	return year;
}

string AutonomousCar::getAi()
{
	return ai;
}


void AutonomousCar::setAi(string _ai) 
{
	if (_ai == "Alexa" || _ai == "Cortana" || _ai == "Echo" || _ai == "Siri") 
	{
		ai = _ai;
		return;
	}
	cout << "Not suitable Ai" << endl;
}


string AutonomousCar::toString()
{
	return make + ", " + model + ", " + to_string(year) + ", " + ai;
}

