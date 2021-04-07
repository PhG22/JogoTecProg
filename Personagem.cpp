#include "Personagem.h"

Personagem::Personagem(Vector2f pos, Vector2f vel, const char* caminhoTextura) {
	position = pos;
	v = vel;

	body.setSize(Vector2f(200.f, 200.f));

	text = new Texture;
	text->loadFromFile(caminhoTextura);
	body.setTexture(text);
}

Personagem::~Personagem() { delete text; }

void Personagem::atualizar(float t) {
	
	position += v * t;

	body.setPosition(position);
}

void Personagem::desenhar(RenderWindow* janela) {

	janela->draw(body);

}