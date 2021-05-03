#pragma once

#include "Menu.h"

class MenuPausa : public Menu
{
private:
	void inicializar() override;

public:
	MenuPausa(GerenciadorGrafico& Ggraf);
	~MenuPausa();

};

