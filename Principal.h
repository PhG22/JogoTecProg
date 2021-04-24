#pragma once
#include "stdafx.h"
#include "Player.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;
#include "GerenciadorCenas.h"
using namespace gerenciadorEstados;


class Principal
{
private:
	GerenciadorGrafico janela;
	Player jogador;
	GerenciadorCenas gScene;
	bool rodando;

public:
	Principal();
	~Principal();
	void executar();
};

