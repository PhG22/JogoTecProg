#pragma once

#include "Desenhavel.h"

class Colidivel : public Desenhavel
{
private:
	
public:
	Colidivel(Vetor2F pos, Vetor2F vel, IDsDesenhaveis id, const char* caminhoTextura = nullptr);
	virtual ~Colidivel();
	virtual void colidir(const IDsDesenhaveis id, Vetor2F pos, Vetor2U tam) = 0;
};

