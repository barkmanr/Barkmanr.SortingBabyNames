#include "Phone.h"

void Phone::save(ofstream& stream) 
{
	stream.write(reinterpret_cast<char*>(&phoneNum), sizeof(phoneNum));

	int fsize = firstname->size();
	stream.write(reinterpret_cast<char*>(&fsize), sizeof(fsize));
	for (int i = 0; i < fsize; i++) 
	{
		stream.write(reinterpret_cast<char*>(&(*firstname)[i]), sizeof((*firstname)[i]));
	}

	int lsize = lastname->size();
	stream.write(reinterpret_cast<char*>(&lsize), sizeof(lsize));
	for (int i = 0; i < lsize; i++)
	{
		stream.write(reinterpret_cast<char*>(&(*lastname)[i]), sizeof((*lastname)[i]));
	}
}

void Phone::load(ifstream& stream) 
{
	stream.read(reinterpret_cast<char*>(&phoneNum), sizeof(phoneNum));

	int fsize;
	if (firstname == nullptr) 
	{
		firstname = new string();
	}
		*firstname = "";

	stream.read(reinterpret_cast<char*>(&fsize), sizeof(fsize));
	for (int i = 0; i < fsize; i++)
	{
		char temp;
		stream.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		*firstname += temp;
	}

	int lsize;
	if (lastname == nullptr)
	{
		lastname = new string();
	}
	*lastname = "";
	stream.read(reinterpret_cast<char*>(&lsize), sizeof(lsize));
	for (int i = 0; i < lsize; i++)
	{
		char temp;
		stream.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		*lastname += temp;
	}
}
