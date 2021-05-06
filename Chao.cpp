#include "Chao.h"

namespace gerenciadorTiles {
	Chao::Chao(Vetor2F tamanho) : Tile(IdsDesenhaveis::chao, "Resources/Textures/tileGround.png", tamanho) {
	}

	Chao::~Chao() {

	}

	void Chao::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

	}
}