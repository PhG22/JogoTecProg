#pragma once

#include "Menu.h"

class MenuPrincipal: public Menu
{
private:
	void inicializar() override;

public:
	MenuPrincipal(GerenciadorGrafico& Ggraf);
	~MenuPrincipal();

};

