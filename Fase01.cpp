#include "Fase01.h"
#include "Atirador.h"
#include "Inimigo.h"
#include "Mumia.h"
#include "Atirador.h"
#include "Projetil.h"
#include "Coletavel.h"
#include "GerenciadorCenas.h"

Fase01::Fase01(GerenciadorGrafico& gg, Player* pjog) : Fase(gg, pjog, "Resources/TileMaps/Fase01.json") {
	inicializar();
}

void Fase01::inicializar() {
	//instanciando inimigos
	listaDesenhaveis.inserir(new Atirador(Vetor2F(1647.f, 241.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(2286.f, 208.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(2604.f, 241.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(2768.f, 304.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(3822.f, 208.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(4109.f, 209.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(5452.f, 274.f), Vetor2F(0, 0), this, pJog));
	listaDesenhaveis.inserir(new Atirador(Vetor2F(5933.f, 309.f), Vetor2F(0, 0), this, pJog));

	listaDesenhaveis.inserir(new Mumia(Vetor2F(330.f, 273.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 493, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(623.f, 336.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 845, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(1204.f, 333.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 1424, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(1833.f, 336.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 2002, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(3656.f, 337.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 3824, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(4111.f, 337.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 4366, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(4908.f, 338.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 5100, pJog));
	listaDesenhaveis.inserir(new Mumia(Vetor2F(5711.f, 336.f), Vetor2F(0, 0), "Resources/Textures/mumia.png", 5804, pJog));

	//instanciando coletáveis
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(397.f, 303.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(1774.f, 366.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(2926.f, 369.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(4300.f, 368.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(5774.f, 360.f), IdsDesenhaveis::vida, "Resources/Textures/vida.png"));

	listaDesenhaveis.inserir(new Coletavel(Vetor2F(587.f, 325.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(921.f, 324.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(1327.f, 327.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(2202.f, 254.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(2604.f, 255.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(2765.f, 332.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(3214.f, 256.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(3966.f, 293.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(4490.f, 262.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));
	listaDesenhaveis.inserir(new Coletavel(Vetor2F(6211.f, 336.f), IdsDesenhaveis::reliquia, "Resources/Textures/Reliquia.png"));


	pJog->inicializar(gGraf, gEvent, gColisor, this);
	pJog->setPos({ 107,368 });
	pJog->resetScore();
	listaDesenhaveis.inicializar(gGraf, gEvent, gColisor);

	gTiles.inicializar(gGraf, gEvent);

	gEvent.setJanela(gGraf.getJanela());
	gColisor.setGerenciadorTiles(&gTiles);
	BackgroundTexture.loadFromFile("Resources/Textures/background.png");

	background.setTexture(BackgroundTexture);

	background.setScale(5.02, 0.69);

	executar();
}

int Fase01::executar() {

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
	if (pJog->getPos().x >= 6360) {
		return IrMenuRanking;
	}

	else return continuar;
}