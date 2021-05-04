#pragma once

#include "stdafx.h"
#include <string>
#include "GerenciadorEventos.h"
using namespace gerenciadorEventos;

class PromessaString
{
private:
	std::string Texto;
	unsigned int idOuvinteTeclado;
	bool capturaIniciada;
	bool textoPronto;
	GerenciadorEventos& ge;
	unsigned short comprimentoMax;

public:

	PromessaString(GerenciadorEventos& GE, unsigned short compMax);
	~PromessaString();

	void começar();
	bool getTextoPronto()const;
	const std::string& getTexto()const;
	void adquirir(const sf::Event& e);
};

