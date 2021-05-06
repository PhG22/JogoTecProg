#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;
#include "stdafx.h"

namespace gerenciadorEventos {
	class GerenciadorEventos
	{
	 private:
		 static unsigned int proxID;

		 RenderWindow* Janela;

		 Event event;

		 map<unsigned int, function<void (const Event&) >> listenerMouse;
		 map<unsigned int, function<void(const Event&) >> listenerTeclado;
		 map<unsigned int, function<void(const Event&) >> listenerMisc;

		 set<unsigned int> removerListenersTeclado;

	 public:
		 GerenciadorEventos() {}
		 ~GerenciadorEventos() {}

		 void tratarEventos();
		 void setJanela(RenderWindow* janela);

		 unsigned int addListenerMouse(function<void(const Event&)> chamada);
		 void rmListenerMouse(int id);

		 unsigned int addListenerTeclado(function<void(const Event&)> chamada);
		 void rmListenerTeclado(int id);

		 unsigned int addListenerMisc(function<void(const Event&)> chamada);
		 void rmListenerMisc(int id);
	};
}

