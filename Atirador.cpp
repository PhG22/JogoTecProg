#include "Atirador.h"
#include "Projetil.h"
#include "Fase.h"

Atirador::Atirador(Vetor2F pos/* = { 0,0 }*/, Vetor2F vel /*= { 0,0 }*/, Fase* pfase /* = nullptr*/, Player* pjog) : Inimigo(pos, vel, 50, "Resources/Textures/atirador.png", pjog, 100), pFase{ pfase }{

}

Atirador::~Atirador() {
	
}

void Atirador::atualizar(float t) {

	if (vida == 0)
		Morrer();

	if (fabs(pJog->getPos().x - position.x) <= 300 && timer.getElapsedTime().asSeconds() >= 3.f) {
		atirar();
		timer.restart();
	}

}

void Atirador::atirar() {

	Vetor2F vel = { 300,0 };
	vel = (pJog->getPos() - position).versor() * vel.modulo();



	Projetil* p = new Projetil(position, vel , IdsDesenhaveis::projetil, "Resources/Textures/projetilAtirador.png");
	pFase->inserirProjetil(p);
	

}
