#include "Desenhavel.h"

Desenhavel::Desenhavel(Vetor2F pos, Vetor2F vel, const char* caminhoTextura) :
	position{ pos }, 
	v{vel},
	caminho{caminhoTextura}
{

}

Desenhavel::~Desenhavel() {
}

void Desenhavel::atualizar(float t) {
	
	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);


	//body.setPosition(position);
}

void Desenhavel::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent) {

	janela.carregarTextura(caminho);

}

void Desenhavel::desenhar(GerenciadorGrafico& janela) {

	janela.desenhar(caminho, position);

}