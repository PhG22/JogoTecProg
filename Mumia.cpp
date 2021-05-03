#include "Mumia.h"

Mumia::Mumia(Vetor2F pos, Vetor2F vel, const char* caminhoTextura, int posF, Player* pjog) :
Inimigo(pos, vel, 100, caminhoTextura, pjog, 150),
posIni{ 0 },
posFim{ posF }
{

}

Mumia::~Mumia() {

}

void Mumia::atualizar(float t) {
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
}

void Mumia::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
	posIni = position.x;
}
