#include "Vaso.h"

namespace gerenciadorTiles {
	Vaso::Vaso(Vetor2F tamanho) : Tile(IdsDesenhaveis::vaso, "Resources/Textures/vaso.png", tamanho) {
	}

	Vaso::~Vaso() {

	}

	void Vaso::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

	}
}