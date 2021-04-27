#pragma once

using namespace std;
#include "stdafx.h"
#include "Botao.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorEventos;
using namespace gerenciadorGrafico;
using namespace sf;

#include <vector>

namespace gerenciadorBotoes {
	class GerenciadorBotoes
	{

	private:
		std::vector<Botao*> Botoes;
		GerenciadorEventos& gEv;
		GerenciadorGrafico& gGraf;
		unsigned int idMouseListener;

	public:

		//Construtor sem parâmetros não é necessário pois ele não existe em classes com atributos que são referências
		GerenciadorBotoes(GerenciadorEventos& GEv, GerenciadorGrafico& GGraf, std::vector<Botao*> botoes = {});
		~GerenciadorBotoes();
		void desenhar()const;
		void MouseListener(const sf::Event& ev);
		void adicionaBotao(Botao* bo);
	};
}

