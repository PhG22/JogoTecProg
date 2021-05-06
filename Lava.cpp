#include "Lava.h"

namespace gerenciadorTiles {
	Lava::Lava(Vetor2F tamanho) : Tile(IdsDesenhaveis::lava, "Resources/Textures/tileLava.png", tamanho) {
	}

	Lava::~Lava() {

	}

	void Lava::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

	}
}