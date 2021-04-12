#pragma once
template<typename TL>
class Lista
{
 private:
	 template<typename T>
	class ElementoLista {
	 private:
		ElementoLista* Ante;
		ElementoLista* Prox;
		T Info;

	 public:
		ElementoLista(T inf = nullptr, ElementoLista* ant = nullptr, ElementoLista* pro = nullptr);
		~ElementoLista() {}
		ElementoLista* getAnterior() const;
		void setAnterior(ElementoLista* ant);
		ElementoLista* getProximo() const;
		void setProximo(ElementoLista* pro);
		T getInfo() const;
		void setInfo(T info);
	};

	ElementoLista<TL>* Inicio;
	ElementoLista<TL>* Fim;
	ElementoLista<TL>* Atual;

 public:
	Lista() : Inicio{ nullptr }, Fim{ nullptr }, Atual{ nullptr } {}
	~Lista() { esvaziar(); }
	void esvaziar();
	void inserir(TL info);
	TL voltarInicio();
	TL irProximo();

};

//implementação Elemento Lista
template<typename TL>
template<typename T>
Lista<TL>::ElementoLista<T>::ElementoLista(T inf, ElementoLista<T>* ant, ElementoLista<T>* pro) : 
	Info{ inf }, 
	Ante{ ant }, 
	Prox{ pro }
{

}

template<typename TL>
template<typename T>
Lista<TL>::ElementoLista<T>* Lista<TL>::ElementoLista<T>::getAnterior()const {
	return Ante;
}

template<typename TL>
template<typename T>
void Lista<TL>::ElementoLista<T>::setAnterior(ElementoLista<T>* ant) {
	Ante = ant;
}

template<typename TL>
template<typename T>
Lista<TL>::ElementoLista<T>* Lista<TL>::ElementoLista<T>::getProximo()const {
	return Prox;
}

template<typename TL>
template<typename T>
void Lista<TL>::ElementoLista<T>::setProximo(ElementoLista<T>* pro) {
	Prox = pro;
}

template<typename TL>
template<typename T>
T Lista<TL>::ElementoLista<T>::getInfo()const {
	return Info;
}

template<typename TL>
template<typename T>
void Lista<TL>::ElementoLista<T>::setInfo(T info) {
	Info = info;
}

//implementação Lista
template<typename TL>
void Lista<TL>::inserir(TL info) {
	if (info) {
		ElementoLista<TL>* novo = new ElementoLista<TL>(info);

		if (!Inicio) {
			Inicio = novo;
			Fim = novo;
			Atual = novo;
		}
		else {
			Fim->setProximo(novo);
			novo->setAnterior(Fim);
			Fim = novo;
		}
	}
}

template<typename TL>
void Lista<TL>::esvaziar() {
	ElementoLista<TL>* paux = Inicio;
	Atual = Inicio;
	while (Atual != nullptr) {
		paux = Atual->getProximo();
		delete Atual;
		Atual = paux;
	}
	Inicio = nullptr;
	Fim = nullptr;
	Atual = nullptr;

}

template<typename TL>
TL Lista<TL>::voltarInicio() {
	Atual = Inicio;

	return (Atual) ? Atual->getInfo() : nullptr;
}

template<typename TL>
TL Lista<TL>::irProximo() {
	Atual = Atual->getProximo();

	return (Atual) ? Atual->getInfo() : nullptr;
}
