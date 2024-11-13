#include "Baby.h"

Baby::Baby() 
{
	maleNames = new string*[1000];
	maleNumbers = new int[1000];
	femaleNames = new string*[1000];
	femaleNumbers = new int[1000];

	for (int i = 0; i < 1000; i++)
	{
		maleNames[i] = nullptr;
		femaleNames[i] = nullptr;
	}
}

Baby::~Baby()
{
	for (int i = 0; i < 1000; i++)
	{
		if(maleNames[i] != nullptr)
		{
			delete maleNames[i];
		}
		if (femaleNames[i] != nullptr)
		{
			delete femaleNames[i];
		}
	}

	delete[] maleNames;
	delete[] maleNumbers;
	delete[] femaleNames;
	delete[] femaleNumbers;
}

void Baby::ReadFile(int year) 
{
	string txt = "";
	string txt2 = "";
	int count = 0;

	if(year >= 2009 && year <= 2021)
	{
		ifstream readFile("../Texts/babynamesranking" + to_string(year) + ".txt");
		while(getline(readFile, txt))
		{
			stringstream ss(txt);
			vector<string> v;
			while (getline(ss, txt2, '	'))
			{
				v.push_back(txt2);
			}

			string MN = v[2];
			stringstream ms(MN);
			string mfinal;
			while (ms.good()) 
			{
				string sub;
				getline(ms, sub, ',');
				mfinal = mfinal + sub;
			}
			v[2] = mfinal;

			string FN = v[4];
			stringstream fs(FN);
			string mfinal2;
			while (fs.good())
			{
				string sub;
				getline(fs, sub, ',');
				mfinal2 = mfinal2 + sub;
			}
			v[4] = mfinal2;

			string* mname = new string();
			*mname = v[1];
			maleNames[count] = mname;

			stringstream man(v[2]);
			man >> maleNumbers[count];

			string* fname = new string();
			*fname = v[3];
			femaleNames[count] = fname;

			stringstream fan(v[4]);
			fan >> femaleNumbers[count];

			count++;
		}

		readFile.close();
	}
}

string Baby::getRank(string gender, string name)
{
	if (gender == "male" || gender == "m" || gender == "Male" || gender == "M") 
	{
		for (int i = 0; i < 1000; i++) 
		{
			if (name == *maleNames[i]) 
			{
				return "Rank: " + to_string(i + 1) + " Amount: " + to_string(maleNumbers[i]);
			}
		}
		return "name not found in top 1000";
	}
	else if(gender == "female" || gender == "f" || gender == "Female" || gender == "F")
	{
		for (int i = 0; i < 1000; i++)
		{
			if (name == *femaleNames[i])
			{
				return "Rank: " + to_string(i + 1) + " Amount: " + to_string(femaleNumbers[i]);
			}
		}
		return "name not found in top 1000";
	}
	return "Incorect gender input";
}

string** Baby::FindCommon() 
{
	string** common = new string * [1000];
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++) 
		{
			if (*maleNames[i] == *femaleNames[j]) 
			{
				common[count] = maleNames[i];
				count++;
				break;
			}
		}
	}
		common[count] = nullptr;
	return common;
}

void Baby::toString() 
{
	for (int i = 0; i < 1000; i++)
	{
		cout << i+1 << " " << *maleNames[i] << " " << maleNumbers[i] << " " << *femaleNames[i] << " " << femaleNumbers[i] << endl;
	}
}

string** Baby::Top10Unique(string gender) {

	static string** common = FindCommon();
	string** top = new string * [10];
	int count = 0;

	if (gender == "m")
	{
		for (int i = 0; i < 1000; i++)
		{
			bool match = false;
			int j = 0;
			while (common[j] != nullptr)
			{
				if (maleNames[i] == common[j]) 
				{
					match = true;
					break;
				}
				j++;
			}
			if (match == false)
			{
				top[count] = maleNames[i];
				count++;
			}
			if (count >= 10) 
			{
				break;
			}
		}
		return top;

	}
	else if ("f")
	{
		for (int i = 0; i < 1000; i++)
		{
			bool match = false;
			int j = 0;
			while (common[j] != nullptr)
			{
				if (femaleNames[i] == common[j])
				{
					match = true;
					break;
				}
				j++;
			}
			if (match == false)
			{
				top[count] = femaleNames[i];
				count++;
			}
			if (count >= 10)
			{
				break;
			}
		}
		return top;
	}
}

