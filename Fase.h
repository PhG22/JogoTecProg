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

class Projetil;

namespace gerenciadorEstados {

	class Fase : public Estado
	{
	protected:
		GerenciadorGrafico& gGraf;
		GerenciadorEventos gEvent;
		GerenciadorColisoes gColisor;
		GerenciadorTiles gTiles;
		ListaDesenhaveis listaDesenhaveis;
		Clock timer;
		unsigned int IDJanelaFechada;
		bool rodando;
		bool pausado;
		Player* pJog;


		Texture BackgroundTexture;
		Sprite background;

		void encerrar(Event ev);

	public:
		Fase(GerenciadorGrafico& gg, Player* pjog = nullptr, const char* caminhoTilemap = nullptr);
		~Fase();
		virtual void inicializar() = 0;
		virtual int executar() = 0;
		void inserirProjetil(Projetil* pProj);
		void pausar();
		void despausar();

	};

}

