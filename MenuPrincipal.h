#pragma once

#include "Menu.h"
#include "CampoTexto.h"

class MenuPrincipal: public Menu
{
private:
	//bool imprimiu;
	//CampoTexto campo;

	void inicializar() override;
	int executar() override;

public:
	MenuPrincipal(GerenciadorGrafico& Ggraf);
	~MenuPrincipal();

};

