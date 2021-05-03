#pragma once
#include "Inimigo.h"
#include "Player.h"

namespace gerenciadorEstados {
	class Fase;
}
using namespace gerenciadorEstados;

class Chefao : public Inimigo
{
private:
	int posIni;
	int posFim;
	Player* pJog;
	Fase* pFase;
	Clock timer;

public:
	Chefao(Vetor2F pos = { 0,0 }, Vetor2F vel = { 0,0 }, Fase* pfase = nullptr, Player* pjog = nullptr, int posF = 0);
	~Chefao();
	void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);
	void atualizar(float t);
	void atirar();
	void setPlayer(Player* pjog);
};

