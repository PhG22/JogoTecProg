#include "TileMap.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using std::cout;
using std::endl;

#include "json.h"
namespace gerenciadorTiles {
	TileMap::LinhaTileMap::LinhaTileMap(unsigned short* p, unsigned int c) : linha{ p }, comprimento{ c }
	{

	}

	TileMap::LinhaTileMap::~LinhaTileMap()
	{

	}

	unsigned short TileMap::LinhaTileMap::operator[] (unsigned int i) const
	{
		if (i >= comprimento)
		{
			cout << "Erro: Acesso indevido a memoria do mapa de tiles" << endl;
			exit(526);
		}

		return linha[i];
	}

	TileMap::TileMap(const char* caminhoarquivo) : mapa{ nullptr }, caminho{ caminhoarquivo }
	{
		CarregarMapa();
	}

	TileMap::~TileMap()
	{
		if (mapa)
		{
			for (int i = 0; i < dimensoesmapa.y; ++i)
				delete mapa[i];
			delete mapa;
		}
	}

	const Vetor2U TileMap::getDimensoesMapa()const
	{
		return dimensoesmapa;
	}

	void TileMap::imprimirMapa()const
	{
		for (int i = 0; i < dimensoesmapa.y; ++i) {
			for (int j = 0; j < dimensoesmapa.x; ++j)
			{
				cout << setw(2) << mapa[i][j] << ' ';
			}
			cout << '\n';

			cout.flush();
		}
	}

	void TileMap::setTile(Vetor2U pos, unsigned short novoIndice)
	{
		if (pos.x >= dimensoesmapa.x || pos.y >= dimensoesmapa.y)
		{
			cout << "Erro: Acesso indevido a memoria do mapa de tiles" << endl;
			exit(526);
		}

		mapa[pos.y][pos.x] = novoIndice;
	}

	const TileMap::LinhaTileMap TileMap::operator[] (unsigned int i)const
	{
		if (i > dimensoesmapa.y)
		{
			cout << "Erro: Acesso indevido a memoria do mapa de tiles" << endl;
			exit(526);
		}

		return LinhaTileMap(mapa[i], dimensoesmapa.x);
	}

	void TileMap::CarregarMapa()
	{
		std::ifstream arquivo(caminho);

		if (!arquivo.is_open())
		{
			cout << "Arquivo no caminho \"" << caminho << "\ Nao pode ser aberto" << endl;
			exit(527);
		}

		nlohmann::json json; //variável para ler um arquivo json, e utilizar operadores de fluxo

		arquivo >> json;

		json = json["layers"][0];

		dimensoesmapa = { json["width"], json["height"] };

		json = json["data"];

		cout << json << "\n" << dimensoesmapa << endl;

		mapa = new unsigned short* [dimensoesmapa.y];

		for (int i = 0; i < dimensoesmapa.y; i++)
			mapa[i] = new unsigned short[dimensoesmapa.x];

		unsigned int i = 0;
		unsigned int j = 0;

		for (unsigned short s : json) {
			if (j >= dimensoesmapa.x) {
				j = 0;
				i++;
			}

			if (i >= dimensoesmapa.y)
				break;
			mapa[i][j++] = s;

		}

		//imprimirMapa();
	}
}