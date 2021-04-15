#include "Desenhavel.h"

Desenhavel::Desenhavel(Vetor2F pos, Vetor2F vel, IDsDesenhaveis id, const char* caminhoTextura) :
	position{ pos }, 
	v{vel},
	caminho{caminhoTextura},
	ID{id}
{

}

Desenhavel::~Desenhavel() {
}

void Desenhavel::atualizar(float t) {
	
	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);


	//body.setPosition(position);
}

void Desenhavel::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor) {

	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);

}

void Desenhavel::desenhar(GerenciadorGrafico& janela) {

	janela.desenhar(caminho, position);

}

const Vetor2U Desenhavel::getDimensoes() const {
	return dimensoes;
}

const Vetor2F Desenhavel::getPos() const {
	return position;
}

const IDsDesenhaveis Desenhavel::getID() const {
	return ID;
}