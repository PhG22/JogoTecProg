#include "ListaPersonagens.h"

ListaPersonagens::ElementoLista::ElementoLista(Personagem* inf, ElementoLista* ant, ElementoLista* pro) {
	info = inf;
	Ante = ant;
	Prox = pro;
}

ListaPersonagens::ElementoLista* ListaPersonagens::ElementoLista::getAnterior()const{
	return Ante;
}

void ListaPersonagens::ElementoLista::setAnterior(ElementoLista* ant) {
	Ante = ant;
}

ListaPersonagens::ElementoLista* ListaPersonagens::ElementoLista::getProximo()const {
	return Prox;
}

void ListaPersonagens::ElementoLista::setProximo(ElementoLista* pro) {
	Prox = pro;
}

Personagem* ListaPersonagens::ElementoLista::getInfo()const {
	return info;
}

void ListaPersonagens::ElementoLista::setInfo(Personagem* perso) {
	info = perso;
}

void ListaPersonagens::inserir(Personagem* info) {
	if (info) {
		ElementoLista* novo = new ElementoLista(info);

		if (!Inicio) {
			Inicio = novo;
			Fim = novo;
			Atual = novo;
		}
		else {
			Fim->setProximo(novo);
			novo->setAnterior(Fim);
			Fim = novo;
		}
	}
}

void ListaPersonagens::esvaziar() {
	ElementoLista* paux = Inicio;
	Atual = Inicio;
	while (Atual != nullptr) {
		paux = Atual->getProximo();
		delete Atual;
		Atual = paux;
	}
	Inicio = nullptr;
	Fim = nullptr;
	Atual = nullptr;

}

Personagem* ListaPersonagens::voltarInicio() {
	Atual = Inicio;
	
	return (Atual) ? Atual->getInfo() : nullptr;
}

Personagem* ListaPersonagens::irProximo() {
	Atual = Atual->getProximo();

	return (Atual) ? Atual->getInfo() : nullptr;
}


void ListaPersonagens::atualizar(float t) {
	Personagem* p = voltarInicio();

	while (p) {
		p->atualizar(t);
		p = irProximo();
	}
}

void ListaPersonagens::desenhar(sf::RenderWindow* janela) {
	Personagem* p = voltarInicio();

	while (p) {
		p->desenhar(janela);
		p = irProximo();
	}

}

void ListaPersonagens::destruir() {
	Personagem* p = voltarInicio();

	while (p) {
		delete p;
		p = irProximo();
	}
	esvaziar();
}

