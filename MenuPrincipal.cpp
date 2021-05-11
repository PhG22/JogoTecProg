#include "MenuPrincipal.h"
#include "GerenciadorCenas.h"
#include <iostream>

MenuPrincipal::MenuPrincipal(GerenciadorGrafico& Ggraf) : Menu(Ggraf) /*imprimiu{ false }, campo( ge, 15, {400.0f, 500.0f}, {200, 50} )*/ {
	inicializar();
}

MenuPrincipal::~MenuPrincipal() {

}

void MenuPrincipal::inicializar() {
	gg.resizeCamera({ 800,600 }, { 400,300 });
	gb.adicionaBotao(new Botao({ 400.f,150.f }, { 200.f,50.f }, "Fase 01: Deserto", [this] {setCodigoRetorno(IrPrimeiraFase); }));
	gb.adicionaBotao(new Botao({ 400.f,250.f }, { 200.f,50.f }, "Fase 02: Piramide", [this] {setCodigoRetorno(IrSegundaFase); }));
	gb.adicionaBotao(new Botao({ 400.f,350.f }, { 200.f,50.f }, "Ranking", [this] {setCodigoRetorno(IrMenuRanking); }));
	gb.adicionaBotao(new Botao({ 400.f,450.f }, { 200.f,50.f }, "Sair do Jogo", [this] {setCodigoRetorno(terminar); }));
	//gb.adicionaBotao(&campo);
}

int MenuPrincipal::executar()
{
	int ret = Menu::executar(); //Chamando a função executar presente na classe Menu

	/*if (!imprimiu && campo.getTextoPronto()) //Verificar se as classes estão funcionando
	{
		imprimiu = true;
		std::cout << "o texto digitado eh: " << campo.getTexto() << std::endl;
		return IrMenuRanking;
	}*/

	return ret;
}