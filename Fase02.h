#pragma once
#include "Fase.h"
using namespace gerenciadorEstados;

class Fase02 :   public Fase{
public:
	Fase02(GerenciadorGrafico& gg, Player* pjog = nullptr);

	void inicializar();

	int executar();

};

