#pragma once
#include "Colidivel.h"
#include "Player.h"
class Inimigo : public Colidivel
{
protected:
	int vida;
	Player* pJog;
	long int pts;

public:
	Inimigo(Vetor2F pos = {0,0}, Vetor2F vel = { 0,0 }, int v = 100, const char* caminhoTextura = nullptr, Player* pjog = nullptr, long int p = 100);
	virtual ~Inimigo();
	void colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
	virtual void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);
	virtual void atualizar(float t) = 0;
	void Morrer();


};

