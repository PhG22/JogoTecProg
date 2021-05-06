#pragma once
#include "Tile.h"

namespace gerenciadorTiles {
	class Vaso :
		public Tile
	{
	public:
		Vaso(Vetor2F tamanho = { 0,0 });
		~Vaso();
		void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);
	};
}

