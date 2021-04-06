#include "Principal.h"

Principal::Principal(){
	janela = new RenderWindow(VideoMode(800, 600), "Jogo");
	listaPersonagens.inserir(new Personagem(Vector2f(0.f, 0.f), Vector2f(500, 500), "player.png"));
	listaPersonagens.inserir(new Personagem(Vector2f(300.f, 0.f), Vector2f(100, 100), "player.png"));
	listaPersonagens.inserir(new Personagem(Vector2f(0.f, 300.f), Vector2f(150, 150), "player.png"));
	listaPersonagens.inserir(new Personagem(Vector2f(400.f, 0.f), Vector2f(200, 200), "player.png"));
	listaPersonagens.inserir(new Personagem(Vector2f(0.f, 400.f), Vector2f(250, 250), "player.png"));

	executar();
}

Principal::~Principal() {

	delete janela;
	listaPersonagens.destruir();
}

void Principal::executar() {

	timer.restart();

	while (janela->isOpen()) {
		Event event;

		while (janela->pollEvent(event)) {
			if (event.type == Event::Closed)
				janela->close();
		}
		Time t = timer.getElapsedTime();

		janela->clear();
		listaPersonagens.atualizar(t.asSeconds());
		listaPersonagens.desenhar(janela);
		janela->display();

		timer.restart();
	}


}
