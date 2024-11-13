#include "Phone.h"
#include "PhoneApp.h"

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

	PhoneApp* adt = new PhoneApp();
	string input;

	while (true) 
	{
		cout << "What would you like to do?" << endl;
		cout << "[q]uit, [a]dd, [d]elete, [r]etrive, [so]rt, [sa]ve, [l]oad, [sh]ow all" << endl;
		getline(cin, input);

		if (input == "q") 
		{
			break;
		}

		else if (input == "a")
		{
			long long phone;
			while(true)
			{
				cout << "What is the phone number? (length == 10)";
				cin >> phone;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (to_string(phone).size() == 10) 
				{
					break;
				}
				cout << "Sorry: Length must be 10" << endl;
			}

			string fname;
			cout << "What is your first name? (start with cap please)" << endl;
			getline(cin, fname);

			string lname;
			cout << "What is your last name? (start with cap please)" << endl;
			getline(cin, lname);

			Phone* P = new Phone(phone, fname, lname);
			adt->Add(P);
		}

		else if (input == "d")
		{
			string lname;
			cout << "What is your last name? (start with cap please)" << endl;
			getline(cin, lname);

			adt->Delete(lname);
		}

		else if (input == "r") 
		{
			string lname;
			cout << "What is your last name? (start with cap please)" << endl;
			getline(cin, lname);

			Phone* P = adt->Retrieve(lname);
			if (P != nullptr)
			{
				cout << P->toString() << endl;
			}
		}

		else if (input == "so")
		{
			adt->Sort();
		}

		else if (input == "sa")
		{
			adt->Save();
		}

		else if (input == "l")
		{
			adt->Load();
		}

		else if (input == "sh")
		{
			adt->ShowAll();
		}

		else
		{
			cout << "input " << input << " dosen't match request" << endl;
		}

	}

	delete adt;

}
