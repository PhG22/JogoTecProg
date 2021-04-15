#include "Principal.h"

Principal::Principal() : 
	rodando{ true }, 
	IDJanelaFechada{ gEvent.addListenerMisc([this](const Event& ev) {fecharJanela(ev);})} 
{

	listaDesenhaveis.inserir(new Player(Vetor2F(0.f, 0.f)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(300.f, 0.f), Vetor2F(0, 0)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(0.f, 300.f), Vetor2F(150, 150)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(400.f, 0.f), Vetor2F(200, 200)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(0.f, 400.f), Vetor2F(250, 250)));
	listaDesenhaveis.inserir(new Inimigo(Vetor2F(700.f, 500.f), Vetor2F(250, 250)));

	listaDesenhaveis.inicializar(janela, gEvent, gColisor);
	gEvent.setJanela(janela.getJanela());

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
		janela.mostrar();

		//timer.restart();
	}


}

void Principal::fecharJanela(const Event ev) {
	if (ev.type == Event::Closed) rodando = false;
}