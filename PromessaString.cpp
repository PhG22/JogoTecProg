#include "PromessaString.h"

PromessaString::PromessaString(GerenciadorEventos& GE, unsigned short compMax) : 
	ge{ GE }, capturaIniciada{ false }, textoPronto{ false }, comprimentoMax{ compMax }, idOuvinteTeclado{0}
{
	/*capturaIniciada = false;
	textoPronto = false;

	comprimentoMax = compMax;
	idOuvinteTeclado = 0;*/
}

PromessaString::~PromessaString()
{
	ge.rmListenerTeclado(idOuvinteTeclado);
}

void PromessaString::começar()
{
	if (capturaIniciada) 
		throw "Erro! Captura ja iniciada.";
	capturaIniciada = true;

	Texto.clear(); //Limpa a string, removendo os conteúdos antigos;
	
	idOuvinteTeclado = ge.addListenerTeclado([this](const sf::Event& e) {adquirir(e); });
}

bool PromessaString::getTextoPronto()const
{
	return textoPronto;
}

const std::string& PromessaString::getTexto()const
{
	return Texto;
}

void PromessaString::adquirir(const sf::Event& e)
{
	if (e.type == sf::Event::EventType::TextEntered) //cCondicional para saber que o usuário digitou um texto
	{
		cout << e.text.unicode << endl;
		if (Texto.size() <= comprimentoMax)
		{
			char c;

			if (e.text.unicode < 128)
				c = static_cast<char>(e.text.unicode); //Convertendo o valor numérico do unicode em char.

			else
				c = '\0';
		}
	}
	else if (e.type == sf::Event::EventType::KeyReleased) //Condicional para saber se a string terminou ou se está apagando texto
	{
		if (e.key.code == sf::Keyboard::Key::Backspace)
		{
			if (Texto.size() > 0)
				Texto.pop_back();
		}

		else if (e.key.code == sf::Keyboard::Key::Enter)
		{
			textoPronto = true;
			capturaIniciada = false;
			ge.rmListenerTeclado(idOuvinteTeclado);
		}
	}
}
