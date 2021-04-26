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

	Texture BackgroundTexture;
	Sprite background;
	BackgroundTexture.loadFromFile("Resources/Textures/background.png");

	background.setTexture(BackgroundTexture);

	background.setScale(5.02, 0.69 );

	while (janela.getJanela()->isOpen()) {


		if(!rodando)
			janela.getJanela()->close();


		janela.limpar();
		janela.getJanela()->draw(background);
		rodando = gScene.executar();
		janela.mostrar();

	}


}