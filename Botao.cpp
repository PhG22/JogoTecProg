#include "Botao.h"

namespace gerenciadorBotoes {
	Botao::Botao(Vetor2F pos, Vetor2F tam, std::string texto, std::function<void(void)> apertado, unsigned int TamTexto, Cor Cor) :
		Apertado{ apertado },
		Posicao{ pos },
		Tamanho{ tam },
		cor{ Cor },
		tamTexto{ TamTexto },
		Texto{ texto }
	{
		//Posicao = pos;
		//Tamanho = tam;
		//Texto = texto;
		//tamTexto = TamTexto;
	}

	Botao::~Botao()
	{

	}

	void Botao::desenhar(GerenciadorGrafico& gGraf)const
	{
		gGraf.desenharRetanguloSolido(Posicao, Tamanho, cor);
		gGraf.desenharTexto(Texto, Posicao, tamTexto);
	}

	Vetor2F Botao::getPos()const
	{
		return Posicao;
	}

	Vetor2F Botao::getTam()const
	{
		return Tamanho;
	}

	void Botao::apertar()const
	{
		Apertado();
	}
}