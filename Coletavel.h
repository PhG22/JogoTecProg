#pragma once
#include "Colidivel.h"
class Coletavel : public Colidivel
{
private:

public:
	Coletavel(Vetor2F pos = {0,0}, IDsDesenhaveis id = IdsDesenhaveis::padrao, const char* caminhoTextura = nullptr);
	~Coletavel();
	void colidir(const IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);
};

