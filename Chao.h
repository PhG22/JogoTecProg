#pragma once
#include "Tile.h"
namespace gerenciadorTiles {
    class Chao :
        public Tile
    {
    public:
        Chao(Vetor2F tamanho = { 0,0 });
        ~Chao();
        void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);
    };
}

