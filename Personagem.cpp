#include "Personagem.h"

Personagem::Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura) : 
	position{ pos }, 
	v{vel},
	caminho{caminhoTextura}
{

}

Personagem::~Personagem() {
}

void Personagem::atualizar(float t) {
	
	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);


	//body.setPosition(position);
}

void Personagem::inicializar(GerenciadorGrafico& janela) {

	janela.carregarTextura(caminho);

}

void Personagem::desenhar(GerenciadorGrafico& janela) {

	janela.desenhar(caminho, position);

}