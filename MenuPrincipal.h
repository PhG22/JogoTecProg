#pragma once

#include "Menu.h"

class MenuPrincipal: public Menu
{
public:
	MenuPrincipal(GerenciadorGrafico& Ggraf, GerenciadorEventos& Gevento);
	~MenuPrincipal();

	void inicializar();
};

