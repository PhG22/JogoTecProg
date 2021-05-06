#pragma once
#include "stdafx.h"

#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "IDsDesenhaveis.h"
#include "Vetor2D.h"
using namespace gerenciadorGrafico;
using namespace gerenciadorEventos;
using namespace gerenciadorColisoes;
using namespace IdsDesenhaveis;


namespace gerenciadorTiles {
	class Tile
	{
	private:
		const IdsDesenhaveis::IDsDesenhaveis Id;
		const char* caminho;
		Vetor2F Tamanho;

	public:
		Tile(const IdsDesenhaveis::IDsDesenhaveis ID = padrao, const char* caminhoArquivo = nullptr, Vetor2F tamanho = -1.0);
		~Tile();
		void inicializar(GerenciadorGrafico& gGraf, GerenciadorEventos& gEvent);
		void desenhar(GerenciadorGrafico& gGraf, const Vetor2F posicao)const;
		const IdsDesenhaveis::IDsDesenhaveis getId()const;
		virtual void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);

	};
}
