#include "Caixa.h"

namespace gerenciadorTiles {
	Caixa::Caixa(Vetor2F tamanho) : Tile(IdsDesenhaveis::caixa, "Resources/Textures/caixa.png", tamanho) {
	}

	Caixa::~Caixa() {

	}

	void Caixa::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

	}
}
