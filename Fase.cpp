#include "Fase.h"
#include "Inimigo.h"
#include "Atirador.h"
#include "Projetil.h"
#include "GerenciadorCenas.h"
#include "Espinho.h"
#include "Agua.h"
#include "Caixa.h"
#include "Chao.h"
#include "Lava.h"
#include "Vaso.h"
#include "TileCenario.h"
using namespace gerenciadorTiles;

namespace gerenciadorEstados {

	Fase::Fase(GerenciadorGrafico& gg, Player* pjog, const char* caminoTileMap) :
		gGraf{gg},
		pJog{pjog},
		rodando{ true },
		gTiles{
			{
			 new TileCenario{"Resources/Textures/arbusto.png", {32.0f, 32.0f}},
			 new TileCenario{"Resources/Textures/cacto.png", {32.0f, 32.0f}},
			 new Caixa{{32.0f, 32.0f}},
			 new TileCenario{"Resources/Textures/moeda.png", {32.0f, 32.0f}},
			 new TileCenario{"Resources/Textures/pedra.png", {32.0f, 32.0f}},
			 new TileCenario{"Resources/Textures/placa1.png", {32.0f, 32.0f}},
			 new TileCenario{"Resources/Textures/placa2.png", {32.0f, 32.0f}},
			 new TileCenario{"Resources/Textures/placa3.png", {32.0f, 32.0f}},
			 new TileCenario{"Resources/Textures/placa4.png", {32.0f, 32.0f}},
			 new Espinho{{32.0f, 32.0f}},
			 new Agua{{32.0f, 32.0f}},
			 new Chao{{32.0f, 32.0f}},
			 new Lava{{32.0f, 32.0f}},
			 new Vaso{{32.0f, 32.0f}},
			 new Tile{IDsDesenhaveis::final, "Resources/Textures/vazioV1.png", {32.0f, 32.0f}},
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
}