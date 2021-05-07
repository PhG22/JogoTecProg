#include "Leaderboard.h"

#include "stdafx.h"

/*unsigned int mouse_event_id;
const char caminho;
Vetor2F pos;
Vetor2F tam;
unsigned int tamFonte;
int offset;*/

Leaderboard::Leaderboard(Vetor2F p, Vetor2F s, unsigned int tf) :
	mouse_event_id{0},
	caminho{"highScores.dat"},
	pos{p},
	tam{s},
	tamFonte{tf},
	offset{0}
{
	carregarPontuacoes();
}

Leaderboard::~Leaderboard(){
}

void Leaderboard::inicializar(GerenciadorGrafico* gg, GerenciadorEventos* ge) {
	gGraf = gg;
	gEvent = ge;
	//carregarPontuacoes();
}

void Leaderboard::inscrever() {
	mouse_event_id = gEvent->addListenerMouse([this](Event e) {
		if (e.type == Event::MouseWheelScrolled && e.mouseWheelScroll.delta > 0) offset++;
		else if (e.type == Event::MouseWheelScrolled && e.mouseWheelScroll.delta < 0) offset--;
		if (offset < 0) offset = 0;
		else if (offset > static_cast<int>(scores.size()) - 1) offset = static_cast<int>(scores.size()) - 1;
	});
}

void Leaderboard::setPos(const Vetor2F p) {
	pos = p;
}

void Leaderboard::setTam(const Vetor2F s) {
	tam = s;
}

void Leaderboard::setTamFonte(const unsigned int s) {
	tamFonte = s;
}

void Leaderboard::carregarPontuacoes() {
	ifstream file(caminho, ios::in);

	scores.clear();

	if(file) {
		unsigned int score;
		string nome;
		while (!file.eof()) {
			file >> score >> nome;
			scores.emplace(score, nome);
		}
	}
	else
		cerr << " Arquivo nao pode ser aberto " << endl;

	file.close();
}

void Leaderboard::desenhar() {
	Vetor2F posTexto = pos + Vetor2F(tam.x / 2, 0);
	unsigned int skip = offset;

	for (auto p : scores) {
		if (skip > 0) {
			skip--;
			continue;
		}
		stringstream str;
		str << p.first << " - " << p.second << endl;
		gGraf->desenharTexto(str.str(), posTexto, tamFonte);
		posTexto.y += tamFonte;

		if (posTexto.y >= tam.y) 
			break;
	}
}

void Leaderboard::addPontuacao(const long int score, const string nome) {
	
	scores.emplace(score, nome);
	/*ofstream file(caminho, ios::out);
	if (file)
		for (auto p : scores)
			file << p.first << " " << p.second << endl;
	else
		cerr << " Arquivo nao pode ser aberto " << endl;

	file.close();*/
}

void Leaderboard::rmListeners() {
	if (mouse_event_id != 0) {
		gEvent->rmListenerMouse(mouse_event_id);
		mouse_event_id = 0;
	}
}

void Leaderboard::salvarRanking() {
	ofstream file(caminho, ios::out);
	if (file)
		for (auto p : scores)
			file << p.first << " " << p.second << endl;
	else
		cerr << " Arquivo nao pode ser aberto " << endl;

	file.close();
}