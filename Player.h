#pragma once
#include "Colidivel.h"
class Player : public Colidivel
{
private:
	unsigned int chaveListener;

public:

	Player(Vetor2F pos);
	~Player();
	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& janela);
	void tratarEvento(const Event& ev);
	void colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
};

