#include "ListaDesenhaveis.h"

void ListaDesenhaveis::inserir(Desenhavel* info) {
	lista.inserir(info);
}

void ListaDesenhaveis::esvaziar() {
	lista.esvaziar();
}

void ListaDesenhaveis::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	Desenhavel* d = lista.voltarInicio();

	while (d) {
		d->inicializar(janela, gEvent, gColisor);
		d = lista.irProximo();
	}

}

void ListaDesenhaveis::atualizar(float t) {
	Desenhavel* d = lista.voltarInicio();

	while (d) {
		d->atualizar(t);
		d = lista.irProximo();
	}
}

void ListaDesenhaveis::desenhar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent) {
	Desenhavel* d = lista.voltarInicio();

	while (d) {
		d->desenhar(janela);
		d = lista.irProximo();
	}

}

void ListaDesenhaveis::destruir() {
	Desenhavel* d = lista.voltarInicio();

	while (d) {
		delete d;
		d = lista.irProximo();
	}
	esvaziar();
}

