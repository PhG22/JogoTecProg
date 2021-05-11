#include "MenuRanking.h"
#include "Player.h"

MenuRanking::MenuRanking(GerenciadorGrafico& gg, Player* pjog) : Menu(gg), 
pJog{ pjog }, campo(ge, 15, { 400.0f, 550.0f }, { 200, 50 }), imprimiu{false} {
	inicializar();
}

MenuRanking::~MenuRanking() {

}

void MenuRanking::inicializar() {
	gg.resizeCamera({ 800,600 }, { 400,300 });
	gb.adicionaBotao(new Botao({ 150.f,50.f }, { 200.f,50.f }, "Menu Principal", [this] {setCodigoRetorno(IrMenu); }));
	gb.adicionaBotao(&campo);

	ranking.inicializar(&gg, &ge);
	ranking.setPos({ 800 / 8, 600 * 1.5 / 10 });
	ranking.setTam({ 800 * 6 / 8, 600 * 9 / 10 });
}

void MenuRanking::addNovaPontuacao() {
	//adicionandoScore = true;
}

int MenuRanking::executar() {
	int ret = Menu::executar();

	ranking.desenhar();
	gg.desenharTexto("Insira seu nome abaixo: ", { 400.0f,500.0f }, 15);

	if (!imprimiu && campo.getTextoPronto()) //Verificar se as classes estão funcionando
	{
		imprimiu = true;
		ranking.inscrever();
		if(campo.getTexto() != "" && pJog->getScore() > 0)
			ranking.addPontuacao(pJog->getScore(), campo.getTexto());
		pJog->resetScore();
		//adicionandoScore = false;
		ranking.salvarRanking();
	}

	ranking.rmListeners();
	//adicionandoScore = false;
	//pJog->resetScore();

	return ret;
}