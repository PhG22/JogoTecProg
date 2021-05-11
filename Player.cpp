#include "Player.h"
#include "Fase.h"
#include "Projetil.h"

Player::Player(Vetor2F pos) : Colidivel(pos, Vetor2F(), IdsDesenhaveis::player, "Resources/Textures/player.png") ,
grounded{0},
arrasto{.95f},
jumpForce{75.f},
gravidade{1.5f},
velMaxY{10.f},
velMinY{1.f}
{

}

Player::~Player(){

}

void Player::inicializar(GerenciadorGrafico& janela, GerenciadorEventos& gEvent, GerenciadorColisoes& gColisor, Fase* pfase)
{
	janela.carregarTextura(caminho);
	dimensoes = janela.getTamanho(caminho);
	gColisor.addColidivel(this);
	pFase = pfase;

	vida = 100;
	vivo = true;
	score = 0;
	v = { 0,0 };

	chaveListener = gEvent.addListenerTeclado([this](const Event ev) {tratarEvento(ev); });
}

void Player::atualizar(float t)
{
	position.x += (v.x * t);
	position.y += v.y;

	v.y += 1.0 * gravidade;
	if (abs(v.y) > velMaxY)
		v.y = velMaxY * ((v.y < 0.f) ? -1.f : 1.f);

	v.y *= arrasto;

	if (abs(v.x) < velMinY)
		v.x = 0.f;
	if (abs(v.y) < velMinY)
		v.y = 0.f;

	if (vida <= 0)
		morrer();

	cout <<"pts: "<< score << endl;
	//cout <<"vida: "<< vida << endl;
	//cout << position << endl;

}

void Player::desenhar(GerenciadorGrafico& janela)
{
	janela.resizeCamera({ 500,450 }, { position.x + 150, position.y - 100 });

	janela.desenhar(caminho, position);
	stringstream str;

	str << "Vida: " << vida << "\n\n" << "Score: " << score << endl;

	janela.desenharRetanguloSolido({ position.x - 50, position.y - 300 }, {180, 50}, Cor(70,0,255));
	janela.desenharTexto(str.str(), { position.x - 50, position.y - 300 }, 20);
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
				if (grounded < 2) {
					v.y -= jumpForce;
					grounded++;
				}
				break;
			case Keyboard::Key::S:
				v.y = v.y;
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
				v.y = v.y;
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

	if (idOutro == IdsDesenhaveis::inimigo || idOutro == IdsDesenhaveis::projetil) {
		vida -= 10;
		Vetor2F dist = position - posOutro;

		v = v * -1;
		position.x = position.x + dist.x;
	}

	if (idOutro == IdsDesenhaveis::chao || idOutro == IdsDesenhaveis::caixa || idOutro == IdsDesenhaveis::vaso) {
		
		float dist = posOutro.y - position.y;
		v.y = 0;
		position.y = (position.y + dist) - 32;

		grounded = 0;
	}

	if (idOutro == IdsDesenhaveis::reliquia)
		score += 100;

	if (idOutro == IdsDesenhaveis::vida)
		vida += 10;

	if (idOutro == IdsDesenhaveis::agua || idOutro == IdsDesenhaveis::lava || idOutro == IdsDesenhaveis::espinho)
		vida = 0;
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

void Player::morrer() {
	resetScore();
	vivo = false;
}

bool Player::getVivo() {
	return vivo;
}