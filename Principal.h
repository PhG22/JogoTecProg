#pragma once
#include "stdafx.h"
#include "Desenhavel.h"
#include "Player.h"
#include "Inimigo.h"
#include "ListaDesenhaveis.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;
#include "GerenciadorEventos.h"
using namespace gerenciadorEventos;
#include "GerenciadorColisoes.h"
using namespace gerenciadorColisoes;



class Principal
{
private:
	GerenciadorGrafico janela;
	GerenciadorEventos gEvent;
	GerenciadorColisoes gColisor;
	ListaDesenhaveis listaDesenhaveis;
	Clock timer;
	unsigned int IDJanelaFechada;
	bool rodando;

public:
	Principal();
	~Principal();
	void executar();
	void fecharJanela(const Event ev);
};

