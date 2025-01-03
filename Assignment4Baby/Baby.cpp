#include "Baby.h"

Baby::Baby() 
{
	maleNames = new string*[1000];
	maleNumbers = new int[1000];
	femaleNames = new string*[1000];
	femaleNumbers = new int[1000];
	commonNames = new string*[1000];

	for (int i = 0; i < 1000; i++)
	{
		maleNames[i] = nullptr;
		femaleNames[i] = nullptr;
		commonNames[i] = nullptr;
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
	delete[] commonNames;
}

bool Baby::ReadFile(int year) //read the file of a given year and return completion status
{
	string txt = ""; //line of text from file
	string txt2 = "";//item from line
	int count = 0;

	if(year >= 2009 && year <= 2021)
	{
		ifstream readFile("../Texts/babynamesranking" + to_string(year) + ".txt"); //open file
		while(getline(readFile, txt)) //read line of text
		{
			stringstream ss(txt);
			vector<string> v;//[Rank,MName,MNum,FName,FNum]
			while (getline(ss, txt2, '	')) //spaces in text
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
			v[2] = mfinal; //Removes the comma from the males number

			string FN = v[4];
			stringstream fs(FN);
			string mfinal2;
			while (fs.good())
			{
				string sub;
				getline(fs, sub, ',');
				mfinal2 = mfinal2 + sub;
			}
			v[4] = mfinal2; //Removes the comma from the females number

			maleNames[count] = new string(v[1]);
			maleNumbers[count] = stoi(v[2]);
			femaleNames[count] = new string(v[3]);
			femaleNumbers[count] = stoi(v[4]);

			count++;
		}

		readFile.close();
		FindCommon();
		return true;
	}
	return false;
}

string Baby::getRank(string gender, string name) //go through list to find which rank given name is
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

void Baby::FindCommon() //see if any names match in both lists
{
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++) 
		{
			if (*maleNames[i] == *femaleNames[j]) 
			{
				commonNames[count] = maleNames[i];
				count++;
				break;
			}
		}
	}
}

string** Baby::getCommon() { return commonNames; }

void Baby::toString() 
{
	for (int i = 0; i < 1000; i++)
	{
		cout << i+1 << " " << *maleNames[i] << " " << maleNumbers[i] << " " << *femaleNames[i] << " " << femaleNumbers[i] << endl;
	}
}

string** Baby::Top10Unique(string gender) //given a gender check if the name is in top 10 and not in the other list
{
	string** top = new string * [10];
	int count = 0;

	if (gender == "m")
	{
		for (int i = 0; i < 1000; i++)
		{
			bool match = false;
			int j = 0;
			while (commonNames[j] != nullptr)
			{
				if (maleNames[i] == commonNames[j]) 
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
			while (commonNames[j] != nullptr)
			{
				if (femaleNames[i] == commonNames[j])
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

