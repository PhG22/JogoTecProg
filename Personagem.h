#pragma once
#include "stdafx.h"

class Personagem
{
protected:
	RectangleShape body;
	Texture* text;
	Vector2f position;
	Vector2f v;

public:
	Personagem(Vector2f pos = Vector2f(0.f, 0.f), Vector2f vel = Vector2f(0.f, 0.f), const char* caminhoTextura = nullptr);
	~Personagem();
	void atualizar(float t);
	void desenhar(RenderWindow* janela);
	
};

