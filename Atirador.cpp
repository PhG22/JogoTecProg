#include "Atirador.h"
#include "Projetil.h"
#include "Fase.h"

Atirador::Atirador(Vetor2F pos/* = { 0,0 }*/, Vetor2F vel /*= { 0,0 }*/, Fase* pfase /* = nullptr*/, Player* pjog) : Inimigo(pos, vel, 100, "Resources/Textures/atirador.png"), pFase{ pfase }, pJog{pjog}{

}

Atirador::~Atirador() {

}

void Atirador::atualizar(float t) {

	if (fabs(pJog->getPos().x - position.x) <= 300 && timer.getElapsedTime().asSeconds() >= 3.f) {
		atirar();
		timer.restart();
	}

}

void Atirador::setPlayer(Player* pjog) {
	pJog = pjog;
}

void Atirador::atirar() {

	Vetor2F vel = { 100,0 };
	vel = vel.projOrtogonal(pJog->getPos());



	Projetil* p = new Projetil(position, vel , IdsDesenhaveis::projetil, "Resources/Textures/projetilAtirador.png");
	pFase->inserirProjetil(p);
	

}