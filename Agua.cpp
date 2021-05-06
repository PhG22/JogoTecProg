#include "Agua.h"

namespace gerenciadorTiles {
	Agua::Agua(Vetor2F tamanho) : Tile(IdsDesenhaveis::agua, "Resources/Textures/tileAgua.png", tamanho) {
	}

	Agua::~Agua() {

	}

	void Agua::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

	}
}