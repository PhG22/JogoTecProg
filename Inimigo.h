#pragma once
#include "Colidivel.h"
class Inimigo : public Colidivel
{
protected:
	int vida;

public:
	Inimigo(Vetor2F pos = {0,0}, Vetor2F vel = { 0,0 }, int v = 100, const char* caminhoTextura = nullptr);
	virtual ~Inimigo();
	void colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
	virtual void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);
	virtual void atualizar(float t);
	void Morrer();


};

