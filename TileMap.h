#pragma once
#include "stdafx.h"

#include "Vetor2D.h"
using namespace gerenciadorGrafico;

namespace gerenciadorTiles {
	class TileMap
	{

	public:
		class LinhaTileMap {

		private:
			const unsigned short* linha;
			unsigned int comprimento;

		public:
			LinhaTileMap(unsigned short* p = nullptr, unsigned int c = 0);
			~LinhaTileMap();
			unsigned short operator[] (unsigned int i) const;
		};


	private:
		Vetor2U dimensoesmapa;
		unsigned short** mapa;
		const char* caminho;

		void CarregarMapa();


	public:
		TileMap(const char* caminhoarquivo = "");
		~TileMap();
		const Vetor2U getDimensoesMapa()const;
		void imprimirMapa()const;
		void setTile(Vetor2U pos, unsigned short novoIndice);
		const LinhaTileMap operator[] (unsigned int i)const;



	};
}