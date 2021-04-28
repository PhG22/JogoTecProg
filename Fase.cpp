#include "Fase.h"
#include "Inimigo.h"
#include "Atirador.h"
#include "Projetil.h"
#include "GerenciadorCenas.h"

namespace gerenciadorEstados {

	Fase::Fase(GerenciadorGrafico& gg, Player* pjog) :
		gGraf{gg},
		pJog{pjog},
		rodando{ true },
		gTiles{
			{
			 new Tile{IDsDesenhaveis::arbusto, "Resources/Textures/arbusto.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::cacto, "Resources/Textures/cacto.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::caixa, "Resources/Textures/caixa.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::moeda, "Resources/Textures/moeda.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::pedra, "Resources/Textures/pedra.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::placa1, "Resources/Textures/placa1.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::placa2, "Resources/Textures/placa2.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::placa3, "Resources/Textures/placa3.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::placa4, "Resources/Textures/placa4.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::espinho, "Resources/Textures/spike.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::agua, "Resources/Textures/tileAgua.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::chao, "Resources/Textures/tileGround.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::lava, "Resources/Textures/tileLava.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::vaso, "Resources/Textures/vaso.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::final, "Resources/Textures/vazioV1.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::barreira, "Resources/Textures/vazioV2.png", {32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::vida, "Resources/Textures/vida.png", {32.0f, 32.0f}}

			}, { 32, 32 }, "Resources/Tilemaps/fase02.json" },
		IDJanelaFechada{ gEvent.addListenerMisc([this](const Event& ev) {encerrar(ev); }) }
	{
		listaDesenhaveis.inserir(new Atirador(Vetor2F(321.f, 242.f), Vetor2F(0, 0), this, pJog));
		listaDesenhaveis.inserir(new Atirador(Vetor2F(547.f, 209.f), Vetor2F(0, 0), this, pJog));
		listaDesenhaveis.inserir(new Atirador(Vetor2F(761.f, 177.f), Vetor2F(0, 0), this, pJog));
		listaDesenhaveis.inserir(new Atirador(Vetor2F(3212.f, 273.f), Vetor2F(0, 0), this, pJog));
		listaDesenhaveis.inserir(new Atirador(Vetor2F(3526.f, 209.f), Vetor2F(0, 0), this, pJog));

		listaDesenhaveis.inserir(new Inimigo(Vetor2F(1459.f, 242.f), Vetor2F(0, 0),100 , "Resources/Textures/mumia.png", 1584));
		listaDesenhaveis.inserir(new Inimigo(Vetor2F(1811.f, 337.f), Vetor2F(0, 0),100 , "Resources/Textures/mumia.png", 2032));
		listaDesenhaveis.inserir(new Inimigo(Vetor2F(2156.f, 304.f), Vetor2F(0, 0),100 , "Resources/Textures/mumia.png", 2278));
		listaDesenhaveis.inserir(new Inimigo(Vetor2F(4500.f, 300.f), Vetor2F(0, 0),100 , "Resources/Textures/mumia.png", 4625));
		listaDesenhaveis.inserir(new Inimigo(Vetor2F(4680.f, 300.f), Vetor2F(0, 0),100 , "Resources/Textures/mumia.png", 4881));

		listaDesenhaveis.inserir(new Inimigo(Vetor2F(5258.f, 305.f), Vetor2F(0, 0),100 , "Resources/Textures/Anubis.png", 5760));


		pJog->inicializar(gGraf, gEvent, gColisor);
		listaDesenhaveis.inicializar(gGraf, gEvent, gColisor);

		gTiles.inicializar(gGraf, gEvent);

		gEvent.setJanela(gGraf.getJanela());
		gColisor.setGerenciadorTiles(&gTiles);
		BackgroundTexture.loadFromFile("Resources/Textures/background2.png");

		background.setTexture(BackgroundTexture);

		background.setScale(5.02, 0.69);

		executar();
	
	}
	
	Fase::~Fase() {
		listaDesenhaveis.destruir();
		//esvaziarProjeteis();
	}
	
	int Fase::executar() {

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
		else return continuar;
	}
	
	void Fase::encerrar(Event ev) {
		if (ev.type == Event::Closed) rodando = false;
	}

	void Fase::inserirProjetil(Projetil* pProj) {
		if (pProj) {
			pProj->inicializar(gGraf, gEvent, gColisor);
			listaDesenhaveis.inserir(pProj);
		}
	}
	/*void Fase::deletarProjetil() {
		delete filaProjeteis.front();
		filaProjeteis.pop();
	}

	void Fase::esvaziarProjeteis() {

		for (auto i = filaProjeteis.front(); !filaProjeteis.empty(); i = filaProjeteis.front()) {
			delete i;
			filaProjeteis.pop();
		}
	}*/
}