#pragma once
#include "stdafx.h"
#include "Desenhavel.h"
#include "ListaDesenhaveis.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;
#include "GerenciadorEventos.h"
using namespace gerenciadorEventos;


class Principal
{
private:
	GerenciadorGrafico janela;
	GerenciadorEventos gEvent;
	ListaDesenhaveis listaDesenhaveis;
	Clock timer;

public:
	Principal();
	~Principal();
	void executar();
};

