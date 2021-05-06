#include "GerenciadorEventos.h"
namespace gerenciadorEventos {

	unsigned int GerenciadorEventos::proxID{ 0 };

	void GerenciadorEventos::tratarEventos() {

		for (auto i : removerListenersTeclado) {
			listenerTeclado.erase(i);
		}

		removerListenersTeclado.clear();

		while (Janela->pollEvent(event)) {
			if (event.type == Event::MouseWheelScrolled
				|| event.type == Event::MouseButtonPressed
				|| event.type == Event::MouseButtonReleased
				|| event.type == Event::MouseMoved) {
				for (auto i : listenerMouse) {
					i.second(event);
				}

			}
			else if (event.type == Event::KeyPressed
				  || event.type == Event::KeyReleased
				  || event.type == Event::TextEntered) {
				 
				for (auto i : listenerTeclado) {
					i.second(event);
				}
			}
			else {

				for (auto i : listenerMisc) {
					i.second(event);
				}
			}

		}
	}

	void GerenciadorEventos::setJanela(RenderWindow* janela){
		Janela = janela;
	}

	unsigned int GerenciadorEventos::addListenerMouse(function<void(const Event&)> chamada) {
		listenerMouse.emplace(proxID, chamada);
		return proxID++;
	}

	void GerenciadorEventos::rmListenerMouse(int id) {
		listenerMouse.erase(id);
	}


	unsigned int GerenciadorEventos::addListenerTeclado(function<void(const Event&)> chamada) {
		listenerTeclado.emplace(proxID, chamada);
		return proxID++;
	}

	void GerenciadorEventos::rmListenerTeclado(int id) {
		removerListenersTeclado.insert(id);
	}

	unsigned int GerenciadorEventos::addListenerMisc(function<void(const Event&)> chamada) {
		listenerMisc.emplace(proxID, chamada);
		return proxID++;
	}

	void GerenciadorEventos::rmListenerMisc(int id) {
		listenerMisc.erase(id);
	}

}