#pragma once
#include "Tile.h"
namespace gerenciadorTiles {
	class Espinho : public Tile
	{
	public:
		Espinho(Vetor2F tamanho = {0,0});
		~Espinho();
		void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);
		//void inicializar(GerenciadorGrafico& gGraf, GerenciadorEventos& gEvent);
	};
}

