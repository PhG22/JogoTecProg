#pragma once
#include "stdafx.h"

#include "Tile.h"
#include "TileMap.h"
#include "Vetor2D.h"
#include "IDsDesenhaveis.h"
#include "GerenciadorEventos.h"
//#include "Desenhavel.h"
using namespace gerenciadorGrafico;
using namespace gerenciadorColisoes;
using namespace gerenciadorEventos;
using namespace IdsDesenhaveis;

#include <vector>

namespace gerenciadorColisoes{
	class GerenciadorColisoes;
}


namespace gerenciadorTiles {
	class GerenciadorTiles
	{

	public:
		typedef class info
		{
		 public:
			const IdsDesenhaveis::IDsDesenhaveis id;
			const Vetor2F posicao;
			const Vetor2U tamanho;
		}Info;

	private:
		TileMap tilemap;
		Vetor2U DimensoesTiles;
		const char* caminho;
		vector <Tile*> Tiles;

	public:
		GerenciadorTiles(vector<Tile*> tiles, Vetor2U dimensoes = {0,0}, const char* caminhoArquivo = nullptr);
		GerenciadorTiles() {}
		~GerenciadorTiles();
		void inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge);
		void desenhar(GerenciadorGrafico& GG)const;
		vector<Info> checarColisoes(const IdsDesenhaveis::IDsDesenhaveis id, Vetor2F posicao, Vetor2U tamanho); 
		const Vetor2F converterCoordenadasMapaTela(const Vetor2U pos) const;

	};
}
