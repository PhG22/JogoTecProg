#pragma once
#include "Colidivel.h"
class Inimigo : public Colidivel
{
private:

public:
	Inimigo(Vetor2F pos, Vetor2F vel);
	~Inimigo();
	void colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);


};

