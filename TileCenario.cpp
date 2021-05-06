#include "TileCenario.h"

namespace gerenciadorTiles {
	TileCenario::TileCenario(const char* caminhoArquivo ,Vetor2F tamanho) : Tile(IdsDesenhaveis::cenario, caminhoArquivo, tamanho) {
	}

	TileCenario::~TileCenario() {

	}

	void TileCenario::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao) {

	}
}