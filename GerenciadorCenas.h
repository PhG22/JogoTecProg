#pragma once
#include "GerenciadorEstados.h"

class Player;

namespace gerenciadorGrafico {
	class GerenciadorGrafico;
}

using namespace gerenciadorGrafico;

enum IdRetorno {
	continuar,
	terminar
};

namespace gerenciadorEstados {
	class GerenciadorCenas : public GerenciadorEstados
	{
	private:
		GerenciadorGrafico& gGraf;
		Player* pJog;
	public:
		GerenciadorCenas(GerenciadorGrafico& gg, Player* pjog = nullptr);
		~GerenciadorCenas();
		void inicializar(){}
	protected:
		bool processar(int Retorno);
	};
}

