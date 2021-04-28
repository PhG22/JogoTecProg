#include "Tile.h"

namespace gerenciadorTiles {
	Tile::Tile(const IdsDesenhaveis::IDsDesenhaveis ID, const char* caminhoArquivo, Vetor2F tamanho) : 
		Id{ ID }, 
		caminho{caminhoArquivo},
		Tamanho{tamanho}
	{

	}

	Tile::~Tile()
	{

	}

	void Tile::inicializar(GerenciadorGrafico& gGraf, GerenciadorEventos& gEvent)
	{
		gGraf.carregarTextura(caminho);
	}

	void Tile::desenhar(GerenciadorGrafico& gGraf, const Vetor2F posicao)const
	{
			gGraf.desenhar(caminho, posicao);
	}

	const IdsDesenhaveis::IDsDesenhaveis Tile::getId()const
	{
		return Id;
	}

	void Tile::colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao)
	{

	}
}