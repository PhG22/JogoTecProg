#include "Cor.h"

namespace gerenciadorBotoes {
	Cor::Cor(unsigned char red, unsigned char green, unsigned char blue, unsigned char A)
	{
		r = red;
		g = green;
		b = blue;
		a = A;
	}

	Cor::~Cor()
	{

	}

	void Cor::setRed(const unsigned char red)
	{
		r = red;
	}

	void Cor::setGreen(const unsigned char green)
	{
		g = green;
	}

	void Cor::setBlue(const unsigned char blue)
	{
		b = blue;
	}

	void Cor::setOpacity(const unsigned char A)
	{
		a = A;
	}

	unsigned char Cor::getRed()const
	{
		return r;
	}

	unsigned char Cor::getGreen()const
	{
		return g;
	}

	unsigned char Cor::getBlue()const
	{
		return b;
	}

	unsigned char Cor::getOpacity()const
	{
		return a;
	}
}