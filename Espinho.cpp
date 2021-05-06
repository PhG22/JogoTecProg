#include "Espinho.h"

namespace gerenciadorTiles {
	Espinho::Espinho(Vetor2F tamanho) : Tile(IdsDesenhaveis::espinho, "Resources/Textures/spike.png", tamanho) {
	}

	Espinho::~Espinho() {

	}

	void Espinho::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

	}
}