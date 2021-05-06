#pragma once
#include "Tile.h"
namespace gerenciadorTiles {
    class Lava :
        public Tile
    {
    public:
        Lava(Vetor2F tamanho = { 0,0 });
        ~Lava();
        void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);
    };
}

