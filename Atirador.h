#pragma once
#include "Inimigo.h"
#include "Player.h"
namespace gerenciadorEstados{
	class Fase;
}
using namespace gerenciadorEstados;

class Atirador : public Inimigo
{
private:
	Player* pJog;
	Fase* pFase;
	Clock timer;

public:
	Atirador(Vetor2F pos = { 0,0 }, Vetor2F vel = { 0,0 }, Fase* pfase = nullptr, Player* pjog = nullptr);
	~Atirador();
	void atualizar(float t);
	void setPlayer(Player* pjog);
	void atirar();
};

