#pragma once
#include "Colidivel.h"
class Inimigo : public Colidivel
{
protected:
	int vida;

public:
	Inimigo(Vetor2F pos, Vetor2F vel, int v = 100);
	~Inimigo();
	void colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);


};

