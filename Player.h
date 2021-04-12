#pragma once
#include "Desenhavel.h"
class Player : public Desenhavel
{
private:
	unsigned int chaveListener;

public:

	Player(Vetor2F pos);
	~Player();
	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent);
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& janela);
	void tratarEvento(const Event& ev);
};

