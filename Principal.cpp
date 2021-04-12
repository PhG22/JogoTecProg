#include "Principal.h"

Principal::Principal(){
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(0.f, 0.f), Vetor2F(500, 500), "player.png"));
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(300.f, 0.f), Vetor2F(100, 100), "player.png"));
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(0.f, 300.f), Vetor2F(150, 150), "player.png"));
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(400.f, 0.f), Vetor2F(200, 200), "player.png"));
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(0.f, 400.f), Vetor2F(250, 250), "player.png"));
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(700.f, 500.f), Vetor2F(250, 250), "player.png"));
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(0.f, 500.f), Vetor2F(250, 250), "player.png"));
	listaDesenhaveis.inserir(new Desenhavel(Vetor2F(700.f, 0.f), Vetor2F(250, 250), "player.png"));

	listaDesenhaveis.inicializar(janela, gEvent);

	executar();
}

Principal::~Principal() {
	listaDesenhaveis.destruir();
}

void Principal::executar() {

	timer.restart();

	while (janela.getJanela()->isOpen()) {
		Event event;

		while (janela.getJanela()->pollEvent(event)) {
			if (event.type == Event::Closed)
				janela.getJanela()->close();
		}
		Time t = timer.getElapsedTime();

		janela.limpar();
		listaDesenhaveis.atualizar(t.asSeconds());
		listaDesenhaveis.desenhar(janela, gEvent);
		janela.mostrar();

		timer.restart();
	}


}
