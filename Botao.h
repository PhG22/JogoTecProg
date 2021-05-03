#pragma once

#include "GerenciadorGrafico.h"
#include "stdafx.h"
using namespace gerenciadorGrafico;
using namespace std;
#include <string>
#include <functional>

namespace gerenciadorBotoes {
	class Botao
	{
	private:

		Vetor2F Posicao;
		Vetor2F Tamanho;
		Cor cor;
		std::string Texto;
		unsigned int tamTexto;
		std::function<void(void)> Apertado;

	public:

		Botao(Vetor2F pos = { 0.0f, 0.0f }, Vetor2F tam = { 0.0f, 0.0f }, std::string texto = "", std::function<void(void)> apertado = std::function<void(void)>(), unsigned int TamTexto = 15U, Cor Cor = { 128, 128, 128 });
		~Botao();

		void desenhar(GerenciadorGrafico& gGraf);
		Vetor2F getPos()const;
		Vetor2F getTam()const;
		void apertar()const;

	};
}
