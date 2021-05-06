#pragma once
#include "Tile.h"
namespace gerenciadorTiles {
    class TileCenario :
        public Tile
    {
    public:
        TileCenario(const char* caminhoArquivo = nullptr,Vetor2F tamanho = { 0,0 });
        ~TileCenario();
        void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);
    };
}
