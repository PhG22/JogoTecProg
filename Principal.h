#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "ListaPersonagens.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;

class Principal
{
private:
	GerenciadorGrafico janela;
	ListaPersonagens listaPersonagens;
	Clock timer;

public:
	Principal();
	~Principal();
	void executar();
};

