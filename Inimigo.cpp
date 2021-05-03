#include "Inimigo.h"

Inimigo::Inimigo(Vetor2F pos, Vetor2F vel, int v, const char* caminhoTextura, Player* pjog, long int p) :
	Colidivel(pos, vel, IdsDesenhaveis::inimigo, caminhoTextura),
	vida{ v },
	pJog {pjog},
	pts {p}
{

}

Inimigo::~Inimigo() {

}

void Inimigo::colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro) {
	if (idOutro == IdsDesenhaveis::player)
		cout << "nhac" << endl;
	if (idOutro == IdsDesenhaveis::projetilPlayer)
		vida -= 50;
	
}

void Inimigo::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
}

void Inimigo::atualizar(float t) {

	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);

}

void Inimigo::Morrer() {
		if(position.x != -11000)
			pJog->addScore(pts);
		position.x = -11000;
		position.y = -11000;
		v.x = 0;
		v.y = 0;
}
