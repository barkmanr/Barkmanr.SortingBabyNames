#include <iostream>
#include <string>
using namespace std;


typedef struct Pixel
{
	Pixel() { X = 0; Y = 0; Z = 0; color = Color(); }
	Pixel(unsigned int _x, unsigned int _y, unsigned int _z, Color _c)
	{
		X = _x;
		Y = _y;
		Z = _z;
		color = _c;
	}

	unsigned int X;
	unsigned int Y;
	unsigned int Z;
	Color color;
} Pixel;

typedef struct Color
{
	Color(unsigned char _a, unsigned char _r, unsigned char _g, unsigned char _b)
	{

		A = _a;
		R = _r;
		G = _g;
		B = _b;
	}
	Color()
	{
		A = 255;
		R = 0;
		G = 0;
		B = 0;
	}

	unsigned char A;
	unsigned char R;
	unsigned char G;
	unsigned char B;
} Color;



int main()
{
	Color c = { 255,40,50,30 };
	Pixel p = { 20,30,40,c };
	Pixel p = { 10,10,10,{255,0,255,255} };
}