#include "MenuPausa.h"
#include "GerenciadorCenas.h"

MenuPausa::MenuPausa(GerenciadorGrafico& Ggraf) : Menu(Ggraf) {
	inicializar();
}

MenuPausa::~MenuPausa() {

}

void MenuPausa::inicializar() {
	gg.resizeCamera({ 800,600 }, { 400,300 });
	gb.adicionaBotao(new Botao({ 400.f,150.f }, { 200.f,50.f }, "Resumir Jogada", [this] {setCodigoRetorno(voltar); }));
	gb.adicionaBotao(new Botao({ 400.f,300.f }, { 200.f,50.f }, "Voltar ao Menu Principal", [this] {setCodigoRetorno(IrMenu); }));
	gb.adicionaBotao(new Botao({ 400.f,450.f }, { 200.f,50.f }, "Sair do Jogo", [this] {setCodigoRetorno(terminar); }));

}
