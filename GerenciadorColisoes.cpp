#include "GerenciadorColisoes.h"
#include "Colidivel.h"
#include <math.h>

namespace gerenciadorColisoes {

	void GerenciadorColisoes::addColidivel(Colidivel* pc) {
		listaColidiveis.insert(pc);
	}

	void GerenciadorColisoes::rmColidivel(Colidivel* pc) {
		listaColidiveis.erase(pc);
	}

	void GerenciadorColisoes::rmTodos() {
		listaColidiveis.clear();
	}

	bool GerenciadorColisoes::verificaColisao(Colidivel* pc1, Colidivel* pc2) {
		Vetor2F pos1 = pc1->getPos();
		Vetor2U dim1 = pc1->getDimensoes();
		
		Vetor2F pos2 = pc2->getPos();
		Vetor2U dim2 = pc2->getDimensoes();

		Vetor2F dist = pos1 - pos2;

		return (fabs(dist.x) < (dim1.x + dim2.x) / 2.0) && (fabs(dist.y) < (dim1.y + dim2.y) / 2.0);
	}

	void GerenciadorColisoes::tratarColisoes() {
		for (auto i = listaColidiveis.begin(); i != listaColidiveis.end(); i++) {
			Colidivel* p1 = *i;
			
			auto tilesColidindo = gt->checarColisoes(p1->getID(), p1->getPos(), p1->getDimensoes());

			for (auto colisao : tilesColidindo) {

				p1->colidir(colisao.id, colisao.posicao, colisao.tamanho);

			}
			
			auto j = i;
			j++;
			for (; j != listaColidiveis.end(); j++) {
				Colidivel* p2 = *j;

				if (verificaColisao(p1, p2)) {
					p1->colidir(p2->getID(), p2->getPos(), p2->getDimensoes());
					p2->colidir(p1->getID(), p1->getPos(), p1->getDimensoes());
				}

			}
		}
	}

	void GerenciadorColisoes::setGerenciadorTiles(GerenciadorTiles* Gt)
	{
		gt = Gt;
	}

}