#include "Principal.h"

Principal::Principal() : 
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

		}, { 32, 32 }, "Resources/Tilemaps/fase01.json" },
	IDJanelaFechada{ gEvent.addListenerMisc([this](const Event& ev) {fecharJanela(ev);})} 
{

	listaDesenhaveis.inserir(new Player(Vetor2F(40.f, 40.f)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(50.f, 10.f), Vetor2F(0, 0)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(50.f, 100.f), Vetor2F(150, 150)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(100.f, 25.f), Vetor2F(200, 200)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(0.f, 400.f), Vetor2F(250, 250)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(700.f, 500.f), Vetor2F(250, 250)));

	listaDesenhaveis.inicializar(janela, gEvent, gColisor);
	
	gTiles.inicializar(janela, gEvent);
	
	gEvent.setJanela(janela.getJanela());
	gColisor.setGerenciadorTiles(&gTiles);

	executar();
}

Principal::~Principal() {
	listaDesenhaveis.destruir();
}

void Principal::executar() {

	timer.restart();

	while (janela.getJanela()->isOpen()) {

		gEvent.tratarEventos();

		if(!rodando)
			janela.getJanela()->close();

		//Time t = timer.getElapsedTime();

		janela.limpar();
		listaDesenhaveis.atualizar(timer.restart().asSeconds());
		gColisor.tratarColisoes();
		listaDesenhaveis.desenhar(janela, gEvent);
		gTiles.desenhar(janela);
		janela.mostrar();

		//timer.restart();
	}


}

void Principal::fecharJanela(const Event ev) {
	if (ev.type == Event::Closed) rodando = false;
}