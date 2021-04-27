#include "Botao.h"

Botao::Botao(Vetor2F pos, Vetor2F tam, std::string texto, std::function<void(void)> Apertado, unsigned int TamTexto, Cor Cor)
{
	Posicao = pos;
	Tamanho = tam;
	Texto = texto;
	tamTexto = TamTexto;
}

Botao::~Botao()
{

}

void Botao::desenhar(GerenciadorGrafico& gGraf)
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