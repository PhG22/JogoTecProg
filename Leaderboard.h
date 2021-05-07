#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
using namespace gerenciadorGrafico;
#include "GerenciadorEventos.h"
using namespace gerenciadorEventos;

class Leaderboard
{
private:
	multimap<unsigned int, string> scores;

	GerenciadorGrafico* gGraf;
	GerenciadorEventos* gEvent;

	unsigned int mouse_event_id;
	const char* caminho;
	Vetor2F pos;
	Vetor2F tam;
	unsigned int tamFonte;
	int offset;

public:
	Leaderboard(Vetor2F p = { 0,0 }, Vetor2F s = { 0,0 }, unsigned int tf = 16);
	~Leaderboard();

	void inicializar(GerenciadorGrafico* gg, GerenciadorEventos* ge);
	void inscrever();
	void setPos(const Vetor2F p);
	void setTam(const Vetor2F s);
	void setTamFonte(const unsigned int s);
	void carregarPontuacoes();
	void desenhar();
	void addPontuacao(const long int score, const string nome);
	void rmListeners();
};

