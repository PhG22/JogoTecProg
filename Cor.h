#pragma once
class Cor
{
private:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

public:
	Cor(unsigned char red = 0, unsigned char green = 0 , unsigned char blue = 0, unsigned char A = 255);
	~Cor();

	void setRed(const unsigned char red);
	void setGreen(const unsigned char green);
	void setBlue(const unsigned char blue);
	void setOpacity(const unsigned char A);

	unsigned char getRed()const;
	unsigned char getGreen()const;
	unsigned char getBlue()const;
	unsigned char getOpacity()const;
};

