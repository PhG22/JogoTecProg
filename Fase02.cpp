#include "Fase02.h"
#include "Atirador.h"
#include "Inimigo.h"
#include "Chefao.h"
#include "Atirador.h"
#include "Mumia.h"
#include "Projetil.h"
#include "GerenciadorCenas.h"

Fase02::Fase02(GerenciadorGrafico& gg, Player* pjog) : Fase(gg, pjog, "Resources/TileMaps/Fase02.json") {
	inicializar();
}

void Fase02::inicializar() {
	gGraf.resizeCamera({500,450}, pJog->getPos());

	listaDesenhaveis.inserir(new Atirador(Vetor2F(321.f, 242.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(547.f, 209.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(761.f, 177.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(3212.f, 273.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(3526.f, 209.f), Vetor2F(0, 0), this, pJog));

	listaDesenhaveis.inserir(new Mumia(Vetor2F(1459.f, 242.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 1584));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(1811.f, 337.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 2032));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(2156.f, 304.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 2278));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(4500.f, 300.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 4625));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(4680.f, 300.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 4881));

	listaDesenhaveis.inserir(new Chefao(Vetor2F(5258.f, 305.f), Vetor2F(0, 0), this, pJog, 5760));


	pJog->inicializar(gGraf, gEvent, gColisor, this);
	pJog->setPos({ 76,337 });
	listaDesenhaveis.inicializar(gGraf, gEvent, gColisor);

	gTiles.inicializar(gGraf, gEvent);

	gEvent.setJanela(gGraf.getJanela());
	gColisor.setGerenciadorTiles(&gTiles);
	BackgroundTexture.loadFromFile("Resources/Textures/background2.png");

	background.setTexture(BackgroundTexture);

	background.setScale(5.02, 0.69);

	executar();
}

int Fase02::executar() {

	gGraf.getJanela()->draw(background);

	gEvent.tratarEventos();

	pJog->atualizar(timer.getElapsedTime().asSeconds());
	listaDesenhaveis.atualizar(timer.restart().asSeconds());
	gColisor.tratarColisoes();

	gTiles.desenhar(gGraf);
	pJog->desenhar(gGraf);
	listaDesenhaveis.desenhar(gGraf, gEvent);

	//deletar entidades, dica do Skora: colocar entidades a serem deletadas num set que será deletado ao fim do loop e inicializar projeteis via
	//metodo da fase em vez de colocá-los na lista.

	if (!rodando) return terminar;
	if (pausado) {
		despausar();
		return IrMenuPausa;
	}
	else return continuar;
}