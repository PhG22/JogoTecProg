#pragma once
#include "Menu.h"
#include "Leaderboard.h"
#include "campoTexto.h"
class MenuRanking : public Menu
{
private:
	Leaderboard ranking;
	CampoTexto campo;
	const char* caminho;
	//bool adicionandoScore;
	bool imprimiu;
	Player* pJog;

public:
	MenuRanking(GerenciadorGrafico& gg, Player* pjog = nullptr);
	~MenuRanking();

	void inicializar();

	void addNovaPontuacao();
	int executar();
};

