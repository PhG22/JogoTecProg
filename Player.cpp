#include "Player.h"

Player::Player(Vetor2F pos): Colidivel(pos, Vetor2F(), IdsDesenhaveis::player , "Resources/Textures/player.png")
{}

Player::~Player()
{}

void Player::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor)
{
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);

	chaveListener = gEvent.addListenerTeclado([this](const Event ev) {tratarEvento(ev); });
}

void Player::atualizar(float t)
{
	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);

	//cout << position << endl;

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

void Player::colidir(IDsDesenhaveis idOutro, Vetor2F posOutro, Vetor2U dimOutro) {

	if (idOutro == IdsDesenhaveis::inimigo) {
		cout << "ataquei" << endl;
		Vetor2F dist = position - posOutro;

		v = v * -1;
		position.x = position.x + dist.x * 0.1;
	}

	else if (idOutro == IdsDesenhaveis::chao || idOutro == IdsDesenhaveis::caixa || idOutro == IdsDesenhaveis::vaso)
		v.y = 0;
	/*
	else if (idOutro == IdsDesenhaveis::moeda)
		cout << "quem quer dinheiro?" << endl;
	  //score += 10;
	else if (idOutro == IdsDesenhaveis::agua)
		cout << "splash" << endl;
	else if (idOutro == IdsDesenhaveis::final)
		cout << "to livre porra!" << endl;
	else if (idOutro == IdsDesenhaveis::espinho)
		cout << "morri!" << endl;
	else if (idOutro == IdsDesenhaveis::vida)
		cout << "1up" << endl;
	else if (idOutro == IdsDesenhaveis::projetil)
		cout << "tiro!" << endl;
	else
		cout << "colisao generica" << endl;*/

}