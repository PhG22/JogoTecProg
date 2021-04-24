#pragma once
#include "Estado.h"
#include "stdafx.h"
namespace gerenciadorEstados {
	class GerenciadorEstados
	{
	private:
		stack<Estado*> pilhaEstados;

	public:
		GerenciadorEstados();
		virtual ~GerenciadorEstados();
		bool executar();
		virtual void inicializar() = 0;

	protected:
		void pushEstado(Estado* p);
		void popEstado();
		void esvaziarPilha();
		virtual bool processar(int Retorno) = 0;
	};
}

