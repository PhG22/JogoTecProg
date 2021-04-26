#pragma once

#include "Desenhavel.h"

class Colidivel : public Desenhavel
{
private:
	
public:
	Colidivel(Vetor2F pos = {0,0}, Vetor2F vel = { 0,0 }, IDsDesenhaveis id = padrao, const char* caminhoTextura = nullptr);
	virtual ~Colidivel();
	virtual void colidir(const IDsDesenhaveis id, Vetor2F pos, Vetor2U tam) = 0;
};

