#pragma once
#include "stdafx.h"

class Colidivel;

namespace gerenciadorColisoes {

	class GerenciadorColisoes
	{
	private:
		set<Colidivel*> listaColidiveis;
		bool verificaColisao(Colidivel* pc1, Colidivel* pc2);

	public:
		GerenciadorColisoes() {}
		~GerenciadorColisoes() {}
		void addColidivel(Colidivel* pc);
		void rmColidivel(Colidivel* pc);
		void rmTodos();
		void tratarColisoes();

	};
}

