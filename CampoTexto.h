#pragma once

#include "stdafx.h"
#include "Botao.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "Vetor2D.h"
#include "PromessaString.h"
#include "Cor.h"
#include <string>

using namespace gerenciadorEventos;
using namespace gerenciadorBotoes;
using namespace gerenciadorGrafico;
using namespace std;

class CampoTexto : public Botao
{
private:
	PromessaString Escrita;

public:

	CampoTexto(GerenciadorEventos& GE, unsigned short int compMax = 15, Vetor2F pos = { 0.0f, 0.0f }, Vetor2F tam = { 0.0f, 0.0f }, std::string texto = "", unsigned int TamTexto = 15U, Cor Cor = { 128, 128, 128 });
	~CampoTexto();

	const std::string& getTexto()const;
	bool getTextoPronto()const;
	void desenhar(GerenciadorGrafico& gGraf) const override;
	void iniciarCaptura();


};
