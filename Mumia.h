#pragma once
#include "Inimigo.h"
class Mumia : public Inimigo
{
private:
    int posIni;
    int posFim;
public:
    Mumia(Vetor2F pos = { 0,0 }, Vetor2F vel = { 0,0 }, const char* caminhoTextura = nullptr, int posF = 0, Player* pjog = nullptr);
    ~Mumia();
    void atualizar(float t);
    void inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor);

};

