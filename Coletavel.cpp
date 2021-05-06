#include "Coletavel.h"

Coletavel::Coletavel(Vetor2F pos, IDsDesenhaveis id, const char* caminhoTextura) :Colidivel(pos, {0,0}, id, caminhoTextura) {

}

Coletavel::~Coletavel() {

}

void Coletavel::colidir(const IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro){
	if (idOutro == IdsDesenhaveis::player)
		position = { -12000, -12000 };

}

void Coletavel::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
}