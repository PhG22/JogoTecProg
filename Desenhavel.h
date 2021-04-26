#pragma once
//#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;
#include "GerenciadorEventos.h"
using namespace gerenciadorEventos;
#include"IDsDesenhaveis.h"
#include "GerenciadorColisoes.h"
using namespace gerenciadorColisoes;
using namespace IdsDesenhaveis;

class Desenhavel
{
protected:
	Vetor2F position;
	Vetor2F v;
	Vetor2U dimensoes;
	const char* caminho;
	IDsDesenhaveis ID;

public:
	Desenhavel(Vetor2F pos = { 0,0 }, Vetor2F vel = {0,0}, IDsDesenhaveis id = padrao, const char* caminhoTextura = nullptr);
	virtual ~Desenhavel();
	virtual void atualizar(float t);
	virtual void desenhar(GerenciadorGrafico& janela);
	virtual void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);
	const Vetor2U getDimensoes() const;
	const Vetor2F getPos() const;
	const IDsDesenhaveis getID() const;
	
};

