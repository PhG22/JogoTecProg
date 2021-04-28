#pragma once
#include "Colidivel.h"
class Projetil : public Colidivel
{
private:
	int dano;
public:
	Projetil(Vetor2F pos = { 0,0 }, Vetor2F vel = { 0,0 }, IDsDesenhaveis id = padrao, const char* caminhoTextura = nullptr);
	virtual ~Projetil();
	void colidir(const IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
	void atualizar(float t);
	void inicializar(GerenciadorGrafico& gGraf, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);

public:
};

