#include "Baby.h"

typedef struct Signature {
	string school;
	string semester;
	string course;
	string name;
	string studentid;
	void ToString() { cout << school << " " << semester << " " << course << " " << name << " " << studentid << endl << endl; }
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

	Baby* babys = new Baby();

	int key;
	cout << "what year would you like to search in? (2009-2021)" << endl;
	cin >> key;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	babys->ReadFile(key);

	string gender;
	cout << "What is the gender? (male/m or female/f)" << endl;
	getline(cin, gender);

	string name;
	cout << "What is the name? (Start with Capitol)" << endl;
	getline(cin, name);

	cout << babys->getRank(gender, name) << endl << endl;


	cout << "continue?";
	string temp;
	getline(cin, temp);

	cout << "Common names in that year" << endl;
	string** common = babys->FindCommon();
	int i = 0;
	while (common[i] != nullptr)
	{
		cout << *common[i] << endl;
		i++;
	}
	cout << "Those are the " << i << " common names in " << key << endl;

	cout << "continue?";
	getline(cin, temp);

	string** topm = babys->Top10Unique("m");
	string** topf = babys->Top10Unique("f");

	cout << "Top 10 Unique Men" << endl;
	for (int i = 0; i < 10; i++) 
	{
		cout << *topm[i] << endl;
	}
	cout << endl <<  "Top 10 Unique Women" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << *topf[i] << endl;
	}


	delete[] topm;
	delete[] topf;
	delete[] common;
	delete babys;

	//added to portfolio
}