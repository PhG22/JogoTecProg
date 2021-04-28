#pragma once

#include "Estado.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;
#include "Player.h"
using namespace gerenciadorEventos;
#include "GerenciadorColisoes.h"
using namespace gerenciadorColisoes;
#include "GerenciadorTiles.h"
using namespace gerenciadorTiles;
#include "ListaDesenhaveis.h"
#include <queue>

class Projetil;

namespace gerenciadorEstados {

	class Fase : public Estado
	{
	private:
		GerenciadorGrafico& gGraf;
		GerenciadorEventos gEvent;
		GerenciadorColisoes gColisor;
		GerenciadorTiles gTiles;
		ListaDesenhaveis listaDesenhaveis;
		Clock timer;
		unsigned int IDJanelaFechada;
		bool rodando;
		Player* pJog;
		//queue<Projetil*> filaProjeteis;


		Texture BackgroundTexture;
		Sprite background;

		void encerrar(Event ev);

	public:
		Fase(GerenciadorGrafico& gg, Player* pjog = nullptr);
		~Fase();
		int executar();
		void inserirProjetil(Projetil* pProj);
		//void deletarProjetil();
		//void esvaziarProjeteis();




	};

}

