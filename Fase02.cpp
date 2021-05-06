#include "Fase02.h"
#include "Atirador.h"
#include "Inimigo.h"
#include "Chefao.h"
#include "Atirador.h"
#include "Mumia.h"
#include "Projetil.h"
#include "Coletavel.h"
#include "GerenciadorCenas.h"

Fase02::Fase02(GerenciadorGrafico& gg, Player* pjog) : Fase(gg, pjog, "Resources/TileMaps/Fase02.json") {
	inicializar();
}

void Fase02::inicializar() {
	gGraf.resizeCamera({500,450}, pJog->getPos());

	//instanciando inimigos
	listaDesenhaveis.inserir(new Atirador(Vetor2F(321.f, 242.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(547.f, 209.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(761.f, 177.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(3212.f, 273.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(3526.f, 209.f), Vetor2F(0, 0), this, pJog));

	listaDesenhaveis.inserir(new Mumia(Vetor2F(1459.f, 242.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 1584, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(1811.f, 337.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 2032, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(2156.f, 304.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 2278, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(4500.f, 300.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 4625, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(4680.f, 300.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 4881, pJog));

	listaDesenhaveis.inserir(new Chefao(Vetor2F(5258.f, 305.f), Vetor2F(0, 0), this, pJog, 5760));

	//instanciando coletáveis
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(1904.f, 369.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(4173.f, 174.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(4781.f, 336.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(5516.f, 175.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));

	listaDesenhaveis.inserir(new Coletavel(Vetor2F(400.f, 238.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(619.f, 209.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(847.f, 177.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(1380.f, 244.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(2225.f, 337.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(2766.f, 369.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(3055.f, 337.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(3376.f, 273.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(6193.f, 368.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(6258.f, 368.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(6321.f, 368.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));



	pJog->inicializar(gGraf, gEvent, gColisor, this);
	pJog->setPos({ 113,337 });
	pJog->resetScore();
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

	float dt = tempoPausa.restart().asSeconds();
	gGraf.getJanela()->draw(background);

	gEvent.tratarEventos();

	pJog->atualizar(timer.getElapsedTime().asSeconds() - dt);
	listaDesenhaveis.atualizar(timer.restart().asSeconds() - dt);
	gColisor.tratarColisoes();

	gTiles.desenhar(gGraf);
	pJog->desenhar(gGraf);
	listaDesenhaveis.desenhar(gGraf, gEvent);

	//deletar entidades, dica do Skora: colocar entidades a serem deletadas num set que será deletado ao fim do loop

	tempoPausa.restart();

	if (!rodando) return terminar;
	if (pausado) {
		despausar();
		tempoPausa.restart();
		return IrMenuPausa;
	}
	if (!pJog->getVivo()) {
		gGraf.resizeCamera({ 800,600 }, { 400,300 });
		return voltar;
	}
	else return continuar;
}