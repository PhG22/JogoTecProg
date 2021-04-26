#include "GerenciadorTiles.h"

namespace gerenciadorTiles {
	GerenciadorTiles::GerenciadorTiles(vector<Tile*> tiles, Vetor2U dimensoes, const char* caminhoArquivo) :
		tilemap(caminhoArquivo),
		DimensoesTiles{dimensoes},
		caminho{caminhoArquivo},
		Tiles{tiles}
	{

	}
	GerenciadorTiles::~GerenciadorTiles()
	{
		for (Tile* t : Tiles)
			delete t;
	}

	void GerenciadorTiles::inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge)
	{
		for (Tile* t : Tiles)
			t->inicializar(gg, ge);
	}
	void GerenciadorTiles::desenhar(GerenciadorGrafico& GG)const
	{
		for (unsigned int i = 0; i < tilemap.getDimensoesMapa().y; i++) {
			for (unsigned int j = 0; j < tilemap.getDimensoesMapa().x; j++) {
				short indice = tilemap[i][j] - 1;
				if (indice >= 0 && indice < Tiles.size())
					Tiles[indice]->desenhar(GG, converterCoordenadasMapaTela(Vetor2U{ j, i }));
			}
		}
	}
	vector<GerenciadorTiles::Info> GerenciadorTiles::checarColisoes(const IdsDesenhaveis::IDsDesenhaveis id, Vetor2F posicao, Vetor2U tamanho)
	{
		unsigned int up = (int)floor(((unsigned int)posicao.y - tamanho.y / 2) / (unsigned int)DimensoesTiles.y);
		unsigned int down = (int)ceil(((unsigned int)posicao.y + tamanho.y / 2) / (unsigned int)DimensoesTiles.y);
		unsigned int left = (int)floor(((unsigned int)posicao.x - tamanho.x / 2) / (unsigned int)DimensoesTiles.x);
		unsigned int right = (int)ceil(((unsigned int)posicao.x + tamanho.x / 2) / (unsigned int)DimensoesTiles.x);

		vector<Info> colisoes;

		if (up < 0 || left < 0 || down > (int)tilemap.getDimensoesMapa().y || left >= (int)tilemap.getDimensoesMapa().x)
			return colisoes;

		for (int i = up; i < down; i++) {
			for (int j = left; j < right; j++) {
				short indice = tilemap[i][j] - 1;
				if (indice >= 0 && indice < (long)Tiles.size()) {
					Tile* t = Tiles[indice];

					t->colidir(id, posicao, { (unsigned int)i,(unsigned int)j });

					colisoes.push_back(Info{ t->getId(), converterCoordenadasMapaTela(Vetor2U(j, i)), DimensoesTiles});
				}
			}

		}
		return colisoes;
	}

	const Vetor2F GerenciadorTiles::converterCoordenadasMapaTela(const Vetor2U pos) const {
		return (Vetor2F(DimensoesTiles.x, DimensoesTiles.y) * 0.5f + Vetor2F(DimensoesTiles.x * pos.x, DimensoesTiles.y * pos.y));
	}
}