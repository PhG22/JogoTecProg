#include "CampoTexto.h"

CampoTexto::CampoTexto(GerenciadorEventos& GE, unsigned short int compMax, Vetor2F pos, Vetor2F tam, std::string texto, unsigned int TamTexto, Cor Cor)
	:Botao{ pos, tam, texto, [this]() {iniciarCaptura(); }, TamTexto, Cor},
	Escrita{GE, compMax}
{

}

CampoTexto::~CampoTexto()
{

}

const std::string& CampoTexto::getTexto()const
{
	if (!getTextoPronto())
		throw "Erro! String sendo chamada antes de ser finalizada, verifique getTextoPronto antes de chamar esse método";
	return Escrita.getTexto();
}

bool CampoTexto::getTextoPronto()const
{
	return Escrita.getTextoPronto();
}

void CampoTexto::desenhar(GerenciadorGrafico& gGraf) const
{
	gGraf.desenharRetanguloSolido(Posicao, Tamanho, cor);
	gGraf.desenharTexto(Escrita.getTexto(), Posicao, tamTexto, false);
}

void CampoTexto::iniciarCaptura()
{
	Escrita.começar();
}