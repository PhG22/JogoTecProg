#include "GerenciadorCenas.h"

#include "Fase01.h"
#include "Fase02.h"
#include "MenuPrincipal.h"
#include "MenuPausa.h"

namespace gerenciadorEstados {

	GerenciadorCenas::GerenciadorCenas(GerenciadorGrafico& gg, Player* pjog) : gGraf{ gg }, pJog{ pjog } {
		pushEstado(new MenuPrincipal(gGraf));
	}

	GerenciadorCenas::~GerenciadorCenas() {
		esvaziarPilha();
	}

	bool GerenciadorCenas::processar(int Retorno) {
		switch (Retorno) {

		case terminar: 
			return false;

		case IrPrimeiraFase:
			pushEstado(new Fase01(gGraf, pJog));
			return true;
			break;
		
		case IrSegundaFase:
			pushEstado(new Fase02(gGraf, pJog));
			return true;
			break;

		case voltar:
			popEstado();
			return true;
			break;

		case IrMenu:
			pushEstado(new MenuPrincipal(gGraf));
			return true;
			break;

		case IrMenuPausa:
			pushEstado(new MenuPausa(gGraf));
			return true;
			break;


		default: 
			return true;

		}
	}

}