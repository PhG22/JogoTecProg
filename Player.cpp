#include "Player.h"
#include "Fase.h"
#include "Projetil.h"

Player::Player(Vetor2F pos) : Colidivel(pos, Vetor2F(), IdsDesenhaveis::player, "Resources/Textures/player.png") {

}

Player::~Player()
{}

void Player::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor, Fase* pfase)
{
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
	pFase = pfase;

	chaveListener = gEvent.addListenerTeclado([this](const Event ev) {tratarEvento(ev); });
}

void Player::atualizar(float t)
{
	position.x = position.x + (v.x * t);
	position.y = position.y + (v.y * t);

	cout << score << endl;

}

void Player::desenhar(GerenciadorGrafico& janela)
{
	janela.centralizar({ position.x + 150, position.y - 100 });

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
			case Keyboard::Key::Space:
				atirar();
				break;
			case Keyboard::Key::Escape:
				pFase->pausar();
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
			case Keyboard::Key::Escape:
				pFase->despausar();
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
}

void Player::setPos(Vetor2F pos) {
	position = pos;
}

void Player::atirar() {
	if (timer.getElapsedTime().asSeconds() >= 1.f) {
		Projetil* p = new Projetil(position, {500,0}, IdsDesenhaveis::projetilPlayer, "Resources/Textures/projetilPlayer.png");
		pFase->inserirProjetil(p);
		timer.restart();
	}
}

void Player::addScore(long int pts){
	score += pts;
}

void Player::resetScore() {
	score = 0;
}

long int Player::getScore() {
	return score;
}