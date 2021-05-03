#include "MenuPrincipal.h"
#include "GerenciadorCenas.h"

MenuPrincipal::MenuPrincipal(GerenciadorGrafico& Ggraf) : Menu(Ggraf) {
	inicializar();
}

MenuPrincipal::~MenuPrincipal() {

}

void MenuPrincipal::inicializar() {
	gg.resizeCamera({ 800,600 }, { 400,300 });
	gb.adicionaBotao(new Botao({ 400.f,150.f }, { 200.f,50.f }, "Fase 01: Deserto", [this] {setCodigoRetorno(IrPrimeiraFase); }));
	gb.adicionaBotao(new Botao({ 400.f,300.f }, { 200.f,50.f }, "Fase 02: Piramide", [this] {setCodigoRetorno(IrSegundaFase); }));
	gb.adicionaBotao(new Botao({ 400.f,450.f }, { 200.f,50.f }, "Sair do Jogo", [this] {setCodigoRetorno(terminar); }));

}