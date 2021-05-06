#include "GerenciadorGrafico.h"

namespace gerenciadorGrafico {

	GerenciadorGrafico::GerenciadorGrafico() :
		janela{ new RenderWindow(VideoMode(800, 600), "Jogo" )},
		camera{Vector2f(400, 300), Vector2f(800, 600)}
	{
		janela->setView(camera);
		janela->setKeyRepeatEnabled(false);
		Fonte.loadFromFile("Resources/Fonte/Newathenaunicode-EP3l.ttf");
		janela->setFramerateLimit(60);

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

	//Ex8
	void GerenciadorGrafico::desenharRetanguloSolido(const Vetor2F posCentro, const Vetor2F tamRetangulo, const Cor cor)const
	{
		sf::RectangleShape RetanguloSolido = sf::RectangleShape({tamRetangulo.x, tamRetangulo.y});
		RetanguloSolido.setFillColor({ cor.getRed(), cor.getGreen(), cor.getBlue(), cor.getOpacity() });
		RetanguloSolido.setOrigin(tamRetangulo.x / 2, tamRetangulo.y / 2);
		RetanguloSolido.setPosition(posCentro.x, posCentro.y);
		janela->draw(RetanguloSolido);
	}

	void GerenciadorGrafico::desenharTexto(const std::string texto, const Vetor2F posTexto, const unsigned long tamTexto, const bool centralizar)const
	{
		sf::Text txt = sf::Text(texto, Fonte, tamTexto);
		txt.setFillColor(sf::Color::White);
		if (centralizar)
		{
			sf::FloatRect tam = txt.getGlobalBounds();
			txt.setOrigin(tam.width / 2, tam.height / 2);
		}
		txt.setPosition(posTexto.x, posTexto.y);
		janela->draw(txt);
	}

	Vetor2F GerenciadorGrafico::getPosicaoMouse()const
	{
		sf::Vector2i posRelacaoJanela = sf::Mouse::getPosition(*janela); //Posição do cursor, em relação a janela atual
		Vetor2F coord = { janela->mapPixelToCoords(posRelacaoJanela).x, janela->mapPixelToCoords(posRelacaoJanela).y };
		//sf::Vector2u tamanhoJanela = janela->getSize(); //Tamanho de toda a janela
		//sf::Vector2f tamanhoCamera = camera.getSize(); //Tamanho (zoom) da câmera
		//sf::Vector2f posicaoCamera = camera.getCenter() - tamanhoCamera / 2.0f; //Posição da câmera, em relação ao início da janela (posição 0,0 da janela)

		/*return {(posRelacaoJanela.x / tamanhoJanela.x) * tamanhoCamera.x + posicaoCamera.x,
				(posRelacaoJanela.y / tamanhoJanela.y)* tamanhoCamera.y + posicaoCamera.y
			   }; //No final, é feita uma divisão do tamanho da tela pela proporção da câmera*/

		return coord;
	}

	void GerenciadorGrafico::resizeCamera(Vetor2F tam, Vetor2F pos) {

		camera.setSize(tam.x, tam.y);
		camera.setCenter(pos.x, pos.y);
		janela->setView(camera);

	}
	
}