#pragma once

#include "GerenciadorBotoes.h"
#include "GerenciadorEventos.h"
#include "GerenciadorCenas.h"
#include "Estado.h"
using namespace gerenciadorBotoes;
using namespace gerenciadorEventos;
using namespace gerenciadorEstados;

class Menu : public Estado
{
private:
	int CodigoRetorno;

protected:
	GerenciadorEventos ge;
	GerenciadorBotoes gb;
	GerenciadorGrafico& gg;

	void setCodigoRetorno(const int codigo);

public:

	Menu(GerenciadorGrafico& GG);
	~Menu() {};

	int executar() override; //comando para realizar para auxiliar numa sobrecarga de métodos
};

