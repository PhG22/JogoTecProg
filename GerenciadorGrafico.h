#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;
#include "stdafx.h"
#include "Vetor2D.h"

namespace gerenciadorGrafico {
	class GerenciadorGrafico
	{
	private:
		RenderWindow* janela;
		View camera;
		map<const string, Texture*> texturas;

	public:
		GerenciadorGrafico();
		~GerenciadorGrafico();
		void mostrar() const;
		void limpar(int r = 0, int g = 0, int b = 0);
		void desenhar(const string caminho, const Vetor2F pos);
		bool carregarTextura(const string caminho);
		void centralizar(const Vetor2F centro);
		RenderWindow* getJanela() const { return janela; }
		const Vetor2U getTamanho(const string caminho);

	};
}
