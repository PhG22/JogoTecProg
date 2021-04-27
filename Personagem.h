#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;

class Personagem
{
protected:
	Vetor2F position;
	Vetor2F v;
	const char* caminho;

public:
	Personagem(Vetor2F pos, Vetor2F vel, const char* caminhoTextura = nullptr);
	~Personagem();
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& janela);
	void inicializar(GerenciadorGrafico& janela);
	
};

