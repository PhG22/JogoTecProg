#pragma once
#include "Fase.h"
using namespace gerenciadorEstados;

class Fase01 : public Fase {
public:
	Fase01(GerenciadorGrafico& gg, Player* pjog = nullptr);

	void inicializar();

	int executar();

};

