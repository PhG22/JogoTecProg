#pragma once
#include "Tile.h"
namespace gerenciadorTiles {
    class Agua :
        public Tile
    {
    public:
        Agua(Vetor2F tamanho = { 0,0 });
        ~Agua();
        void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);
    };
}

