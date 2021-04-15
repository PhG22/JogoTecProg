#include "GerenciadorGrafico.h"

namespace gerenciadorGrafico {

	GerenciadorGrafico::GerenciadorGrafico() :
		janela{ new RenderWindow(VideoMode(800, 600), "Jogo" )},
		camera{Vector2f(400, 300), Vector2f(800, 600)}
	{

		janela->setView(camera);
		janela->setKeyRepeatEnabled(false);

	}

	GerenciadorGrafico::~GerenciadorGrafico() {
		delete janela;

		for (auto i = texturas.begin(); i != texturas.end(); ++i) {
			delete (*i).second;
		}
	}
	void GerenciadorGrafico::mostrar() const {
		janela->display();
	}

	void GerenciadorGrafico::limpar(int r, int g, int b) {
		janela->clear(Color(r, g, b));
	}

	void GerenciadorGrafico::desenhar(const string caminho, const Vetor2F pos) {
		if (texturas.count(caminho) == 0) {
			cout << "Erro! Imagem nao carregada" << endl;
			exit(1);
		}

		Texture* text = texturas[caminho];
		
		Sprite sprite;
		sprite.setTexture(*text);
		sprite.setPosition(pos.x, pos.y);

		janela->draw(sprite);
	}

	bool GerenciadorGrafico::carregarTextura(const string caminho) {
		if (texturas.count(caminho) == 1) return true;
		else {
			Texture* text = new Texture();
			if (!text->loadFromFile(caminho)) {
				cout << "Erro! Textura Invalida" << endl;
				exit(1);
			}
			texturas.insert(pair<string, Texture*>(caminho, text));

			return true;
		}
	}

	void GerenciadorGrafico::centralizar(const Vetor2F centro) {
		camera.setCenter(Vector2f(centro.x, centro.y));
		janela->setView(camera);
	}

	const Vetor2U GerenciadorGrafico::getTamanho(const string caminho){
		if (texturas.count(caminho) == 0) {
			cout << "Erro! Imagem nao carregada" << endl;
			exit(1);
		}

		Vector2u dim = (texturas[caminho])->getSize();

		return Vetor2U(dim.x, dim.y);
	}

}