#include "Chefao.h"
#include "Projetil.h"
#include "Fase.h"

Chefao::Chefao(Vetor2F pos, Vetor2F vel, Fase* pfase, Player* pjog, int posF) :
Inimigo(pos, vel, 500, "Resources/Textures/Anubis.png", pjog, 1000),
posIni{ 0 },
posFim{ posF },
pFase{ pfase }
{

}

Chefao::~Chefao() {

}

void Chefao::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
	posIni = position.x;
}

void Chefao::atualizar(float t) {
	if (vida == 0) {
		Morrer();
		posIni = -11000;
		posFim = -11000;
	}

	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);

	if (position.x <= posIni)
		v.x = 100;
	else if (position.x >= posFim)
		v.x = -100;


	if (fabs(pJog->getPos().x - position.x) <= 300 && timer.getElapsedTime().asSeconds() >= 3.f) {
		atirar();
		timer.restart();
	}
}

void Chefao::atirar() {

	Vetor2F vel = { 300,0 };
	vel = (pJog->getPos() - position).versor() * vel.modulo();

	Projetil* p = new Projetil(position, vel, IdsDesenhaveis::projetil, "Resources/Textures/projetilChefe.png");
	pFase->inserirProjetil(p);

}
