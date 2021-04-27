#include "GerenciadorBotoes.h"
using namespace sf;

namespace gerenciadorBotoes {

	GerenciadorBotoes::GerenciadorBotoes(GerenciadorEventos& GEv, GerenciadorGrafico& GGraf, std::vector<Botao*> botoes) : Botoes{ botoes }, gEv{ GEv }, gGraf{ GGraf }, idMouseListener{ 0 }
	{
		idMouseListener = gEv.addListenerMouse([this](const sf::Event& ev) {MouseListener(ev); });//Por algum motivo, ele n�o t� aceitando o par�metro ev como argumento da fun��o, ele diz que n�o � qualificada como constante. Isso provavelmente vai afetar o funcionamento do c�digo
	}

	GerenciadorBotoes::~GerenciadorBotoes()
	{
		gEv.rmListenerMouse(idMouseListener);
	}

	void GerenciadorBotoes::desenhar()const
	{
		for (Botao* bo : Botoes) bo->desenhar(gGraf); //Para todo bot�o presente em Botoes, desenha bo
	}

	void GerenciadorBotoes::MouseListener(const sf::Event& ev)
	{
		if (ev.type == sf::Event::MouseButtonReleased) //Se o bot�o do mouse for solto em cima do bot�o, ent�o ocorrer um evento
		{
			Vetor2F posicaoMouse = gGraf.getPosicaoMouse();

			for (Botao* bo : Botoes)
			{
				Vetor2F posicaoCentroBotao = bo->getPos();
				Vetor2F tamanhoBotao = bo->getTam();
				Vetor2F distanciaMouseCentro = posicaoMouse - posicaoCentroBotao;

				if (fabs(distanciaMouseCentro.x) < tamanhoBotao.x / 2 && fabs(distanciaMouseCentro.y) < tamanhoBotao.y / 2) //Verificando onde em que parte do bot�o est� sendo clicado
					bo->apertar();
			}
		}
	}

	void GerenciadorBotoes::adicionaBotao(Botao* bo)
	{
		if (bo)
			Botoes.push_back(bo); //Se bo for diferente de nulo, ent�o adiciona bo ao vetor
	}

}