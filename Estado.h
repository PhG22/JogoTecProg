#pragma once

namespace gerenciadorEstados {
	class Estado
	{
	private:
	public:
		Estado();
		virtual ~Estado();

		virtual int executar() = 0;
	};
}

