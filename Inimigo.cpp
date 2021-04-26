#include "Inimigo.h"

Inimigo::Inimigo(Vetor2F pos, Vetor2F vel, int v) : Colidivel(pos, vel, IdsDesenhaveis::inimigo, "Resources/Textures/mumia.png") {

}

Inimigo::~Inimigo() {

}

void Inimigo::colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro) {
	if (idOutro == IdsDesenhaveis::player)
		cout << "nhac" << endl;
	//else
		//cout << "bateu" << endl;

	Vetor2F dist = position - posOutro;

	v = v * -1;
	position = position + dist * 0.1;
}

void Inimigo::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
}
