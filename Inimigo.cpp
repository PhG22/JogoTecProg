#include "Inimigo.h"

Inimigo::Inimigo(Vetor2F pos, Vetor2F vel, int v, const char* caminhoTextura, int posF) : 
	Colidivel(pos, vel, IdsDesenhaveis::inimigo, caminhoTextura),
	posIni{0},
	posFim{posF}
{

}

Inimigo::~Inimigo() {

}

void Inimigo::colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro) {
	if (idOutro == IdsDesenhaveis::player)
		cout << "nhac" << endl;
	//else
		//cout << "bateu" << endl;
	/*if (idOutro != IdsDesenhaveis::projetil) {
		Vetor2F dist = position - posOutro;

		v = v * -1;
		position = position + dist * 0.1;
	}*/
}

void Inimigo::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
	posIni = position.x;
}

void Inimigo::atualizar(float t) {

	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);

	if (position.x <= posIni)
		v.x = 100;
	else if (position.x >= posFim)
		v.x = -100;

}
