#pragma once
#include "stdafx.h"

#include "GerenciadorTiles.h"
using namespace gerenciadorTiles;

class Colidivel;

namespace gerenciadorColisoes {

	class GerenciadorColisoes
	{
	private:
		set<Colidivel*> listaColidiveis;
		bool verificaColisao(Colidivel* pc1, Colidivel* pc2);
		GerenciadorTiles* gt;

	public:
		GerenciadorColisoes() : gt{nullptr} {}
		~GerenciadorColisoes() {}
		void addColidivel(Colidivel* pc);
		void rmColidivel(Colidivel* pc);
		void rmTodos();
		void tratarColisoes();
		void setGerenciadorTiles(GerenciadorTiles* Gt);

	};
}

