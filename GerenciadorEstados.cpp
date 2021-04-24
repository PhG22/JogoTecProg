#include "GerenciadorEstados.h"

namespace gerenciadorEstados {
	GerenciadorEstados::GerenciadorEstados() {

	}

	GerenciadorEstados::~GerenciadorEstados() {
		esvaziarPilha();

	}

	bool GerenciadorEstados::executar() {

		return processar((pilhaEstados.top())->executar());
	}

	void GerenciadorEstados::pushEstado(Estado* p) {
		if (p)
			pilhaEstados.push(p);
	}

	void GerenciadorEstados::popEstado() {
		delete pilhaEstados.top();
		pilhaEstados.pop();
	}

	void GerenciadorEstados::esvaziarPilha() {
		
		while (pilhaEstados.size() != 0) {
			popEstado();
		}
	}

}