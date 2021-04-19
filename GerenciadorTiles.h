#pragma once
#include "stdafx.h"

#include "Tile.h"
#include "TileMap.h"
#include "Vetor2D.h"
#include "IDsDesenhaveis.h"
#include "Desenhavel.h"
using namespace gerenciadorGrafico;
using namespace gerenciadorColisoes;
using namespace IdsDesenhaveis;

#include <vector>


namespace gerenciadorTiles {
	class GerenciadorTiles : public Desenhavel
	{

	public:
		typedef struct info
		{
			const IdsDesenhaveis::IDsDesenhaveis id;
			const Vetor2F posicao;
			const Vetor2F tamanho;
		}Info;
		
	private:
		TileMap tilemap;
		Vetor2F DimensoesTiles;
		const char* caminho;
		std::vector <Tile> tiles;

	public:
		GerenciadorTiles(std::vector<Tile> tiles, Vetor2F dimensoes, const char* caminhoArquivo);
		~GerenciadorTiles();
		void atualizar(float t);
		void inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge, GerenciadorColisoes& gc);
		void desenhar(GerenciadorGrafico& GG)const;
		void checarColisoes(const IdsDesenhaveis::IDsDesenhaveis id, Vetor2F posicao, Vetor2F tamanho); //Depois de mexer no gerenciador de colisões alterar void para std::vector<Info> 

	};
}
