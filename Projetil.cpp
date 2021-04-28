#include "Projetil.h"

Projetil::Projetil(Vetor2F pos, Vetor2F vel, IDsDesenhaveis id, const char* caminhoTextura) : Colidivel(pos, vel, id, caminhoTextura), dano{ 10 }
{

}

Projetil::~Projetil() {

}

void Projetil::colidir(const IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro) {
	if (idOutro == IdsDesenhaveis::player || idOutro == IdsDesenhaveis::chao || idOutro == IdsDesenhaveis::caixa || idOutro == IdsDesenhaveis::vaso)
		position = { -10000, -10000 };
}

void Projetil::atualizar(float t) {
	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);
}

void Projetil::inicializar(GerenciadorGrafico& gGraf, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	gGraf.carregarTextura(caminho);
	dimensoes = gGraf.getTamanho(caminho);
	gColisor.addColidivel(this);
}