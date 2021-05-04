#include "Fase.h"
#include "Inimigo.h"
#include "Atirador.h"
#include "Projetil.h"
#include "GerenciadorCenas.h"

namespace gerenciadorEstados {

	Fase::Fase(GerenciadorGrafico& gg, Player* pjog, const char* caminoTileMap) :
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

			}, { 32, 32 }, caminoTileMap},
		IDJanelaFechada{ gEvent.addListenerMisc([this](const Event& ev) {encerrar(ev); }) },
		pausado{ false }
	{}
	
	Fase::~Fase() {
		listaDesenhaveis.destruir();
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

	void Fase::pausar() {
		pausado = true;
	}

	void Fase::despausar() {
		pausado = false;
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