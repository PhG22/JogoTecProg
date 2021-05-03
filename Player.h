#pragma once
#include "Colidivel.h"

namespace gerenciadorEstados {
	class Fase;
}
using namespace gerenciadorEstados;

class Player : public Colidivel
{
private:
	unsigned int chaveListener;
	int vida;
	long int score;
	Fase* pFase;
	Clock timer;

public:

	Player(Vetor2F pos = {0,0});
	~Player();
	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor, Fase* pfase);
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& janela);
	void tratarEvento(const Event& ev);
	void colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro);
	void setPos(Vetor2F pos);
	void atirar();
	void addScore(long int pts);
	void resetScore();
	long int getScore();
};

