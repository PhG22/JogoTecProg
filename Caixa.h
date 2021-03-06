#pragma once
#include "Tile.h"
namespace gerenciadorTiles {
    class Caixa :
        public Tile
    {
    public:
        Caixa(Vetor2F tamanho = { 0,0 });
        ~Caixa();
        void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);
    };
}

