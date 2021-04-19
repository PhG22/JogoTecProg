#pragma once
#include "stdafx.h"

#include "GerenciadorGrafico.h"
#include "IDsDesenhaveis.h"
#include "Vetor2D.h"
using namespace gerenciadorGrafico;
using namespace gerenciadorColisoes;
using namespace IdsDesenhaveis;

class Tile
{
private:
	const IdsDesenhaveis::IDsDesenhaveis Id;
	const char* caminho;
	Vetor2F tamanho;
	GerenciadorGrafico* gg;

public:
	Tile(const IdsDesenhaveis::IDsDesenhaveis ID, const char* caminhoArquivo = "", Vetor2F tamanho = -1.0);
	~Tile();
	virtual void inicializar(GerenciadorGrafico& GG);
	void desenhar()const;
	const IdsDesenhaveis::IDsDesenhaveis getId()const;
	virtual void colidir(IdsDesenhaveis::IDsDesenhaveis idOutro, Vetor2F posicaoOutro, Vetor2U posicao);

};

