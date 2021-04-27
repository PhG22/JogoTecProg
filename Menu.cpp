#include "Menu.h"


Menu::Menu(GerenciadorGrafico& GG) : CodigoRetorno(IdRetorno::continuar), gb{ge, GG}, gg{GG}
{
	ge.setJanela(gg.getJanela());
}

void Menu::setCodigoRetorno(const int codigo)
{
	CodigoRetorno = codigo;
}

int Menu::executar()
{
	CodigoRetorno = IdRetorno::continuar;
	ge.tratarEventos();
	gb.desenhar();
	return CodigoRetorno;
}