#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;
#include "GerenciadorEventos.h"
using namespace gerenciadorEventos;

class Desenhavel
{
protected:
	Vetor2F position;
	Vetor2F v;
	const char* caminho;

public:
	Desenhavel(Vetor2F pos, Vetor2F vel, const char* caminhoTextura = nullptr);
	virtual ~Desenhavel();
	virtual void atualizar(float t);
	virtual void desenhar(GerenciadorGrafico& janela);
	virtual void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent);
	
};

