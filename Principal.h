#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include "ListaPersonagens.h"

class Principal
{
private:
	RenderWindow* janela;
	ListaPersonagens listaPersonagens;
	Clock timer;

public:
	Principal();
	~Principal();
	void executar();
};

