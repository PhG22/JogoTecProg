#include "MenuRanking.h"
#include "Player.h"

MenuRanking::MenuRanking(GerenciadorGrafico& gg, Player* pjog) : Menu(gg), 
pJog{ pjog }, campo(ge, 15, { 400.0f, 500.0f }, { 200, 50 }), adicionandoScore{ false }, imprimiu{false} {
	inicializar();
}

MenuRanking::~MenuRanking() {

}

void MenuRanking::inicializar() {
	gg.resizeCamera({ 800,600 }, { 400,300 });
	gb.adicionaBotao(new Botao({ 250.f,100.f }, { 200.f,50.f }, "Menu Principal", [this] {setCodigoRetorno(IrMenu); }));
	gb.adicionaBotao(&campo);

	ranking.inicializar(&gg, &ge);
	ranking.setPos({ 800 / 8, 600 * 1.5 / 10 });
	ranking.setTam({ 800 * 6 / 8, 600 * 9 / 10 });
}

void MenuRanking::addNovaPontuacao() {
	adicionandoScore = true;
}

int MenuRanking::executar() {
	int ret = Menu::executar();

	ranking.desenhar();

	if (!imprimiu && campo.getTextoPronto()) //Verificar se as classes estão funcionando
	{
		imprimiu = true;
		ranking.inscrever();
		if(campo.getTexto() != "")
			ranking.addPontuacao(pJog->getScore(), campo.getTexto());
		pJog->resetScore();
		adicionandoScore = false;
	}

	ranking.rmListeners();
	adicionandoScore = false;
	//pJog->resetScore();

	return ret;
}