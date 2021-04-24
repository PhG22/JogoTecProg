#include "GerenciadorCenas.h"

#include "Fase.h"

namespace gerenciadorEstados {

	GerenciadorCenas::GerenciadorCenas(GerenciadorGrafico& gg, Player* pjog) : gGraf{ gg }, pJog{ pjog } {
		pushEstado(new Fase(gg, pjog));
	}

	GerenciadorCenas::~GerenciadorCenas() {
		esvaziarPilha();
	}

	bool GerenciadorCenas::processar(int Retorno) {
		switch (Retorno) {

		case terminar: 
			return false;

		default: 
			return true;

		}
	}

}