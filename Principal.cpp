#include "Principal.h"

Principal::Principal() : 
	rodando{ true },
	jogador{ Vetor2F(40.f, 40.f) },
	gScene{janela, &jogador}
{

	executar();
}

Principal::~Principal() {
}

void Principal::executar() {


	while (janela.getJanela()->isOpen()) {


		if(!rodando)
			janela.getJanela()->close();

		rodando = gScene.executar();
		janela.mostrar();

	}


}