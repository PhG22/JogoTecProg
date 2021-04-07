#pragma once
#include "Personagem.h"

class ListaPersonagens
{
private:
	class ElementoLista {
	private:
		ElementoLista* Ante;
		ElementoLista* Prox;
		Personagem* info;

	public:
		ElementoLista(Personagem* inf = nullptr, ElementoLista* ant = nullptr, ElementoLista* pro = nullptr);
		~ElementoLista() {}
		ElementoLista* getAnterior() const;
		void setAnterior(ElementoLista* ant);
		ElementoLista* getProximo() const;
		void setProximo(ElementoLista* pro);
		Personagem* getInfo() const;
		void setInfo(Personagem* perso);
	};

	ElementoLista* Inicio;
	ElementoLista* Fim;
	ElementoLista* Atual;

public:
	ListaPersonagens() { Inicio = nullptr; Fim = nullptr; Atual = nullptr; }
	~ListaPersonagens() { esvaziar(); }
	void esvaziar();
	void inserir(Personagem* info);
	Personagem* voltarInicio();
	Personagem* irProximo();
	void inicializar(GerenciadorGrafico& janela);
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& janela);
	void destruir();

};

