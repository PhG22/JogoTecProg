#pragma once
#include "Desenhavel.h"
#include "Lista.h"

class ListaDesenhaveis
{
private:
	Lista<Desenhavel*> lista;
public:
	ListaDesenhaveis() : lista() {}
	~ListaDesenhaveis() { destruir(); }

	void esvaziar();
	void inserir(Desenhavel* info);

	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent);
	void destruir();

};

