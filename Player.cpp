#include "Player.h"

Player::Player(Vetor2F pos): Desenhavel(pos, Vetor2F(), "player.png")
{}

Player::~Player()
{}

void Player::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent)
{
	janela.carregarTextura(caminho);

	chaveListener = gEvent.addListenerTeclado([this](const Event ev) {tratarEvento(ev); });
}

void Player::atualizar(float t)
{
	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);

}

void Player::desenhar(GerenciadorGrafico& janela)
{
	janela.centralizar(position);

	janela.desenhar(caminho, position);
}

void Player::tratarEvento(const sf::Event& ev)
{
	if (ev.type == Event::KeyPressed) {
		switch (ev.key.code)
		{
			case Keyboard::Key::D:
				v.x = 300;
				break;
			case Keyboard::Key::A:
				v.x = -300;
				break;
			case Keyboard::Key::W:
				v.y = -300;
				break;
			case Keyboard::Key::S:
				v.y = 300;
				break;
			default:
				break;
		}
	}

	if (ev.type == Event::KeyReleased) {
		switch (ev.key.code)
		{
			case Keyboard::Key::D:
				v.x = 0;
				break;
			case Keyboard::Key::A:
				v.x = 0;
				break;
			case Keyboard::Key::W:
				v.y = 0;
				break;
			case Keyboard::Key::S:
				v.y = 0;
				break;
			default:
				break;
		}
	}
}