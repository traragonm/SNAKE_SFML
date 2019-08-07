#include "Gameover.h"
Gameover::Gameover(GResource res) {
	_SRES = res;
	Init();
	Codename = 5;
	signal = 0;
	std::cout << "Gameover init" << std::endl;
}
Gameover::~Gameover() {
	std::cout << "Gameover remove" << std::endl;
}
void Gameover::Init() {

}
void Gameover::Draw() {
	_SRES->_window.clear(sf::Color::White);
	_SRES->_window.display();
}

void Gameover::Handle(sf::Event event) {
	while (_SRES->_window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::Closed:
			_SRES->_window.close();
			break;
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::Escape) _SRES->_StateM.RemoveState();
			break;
		default:
			break;
		}
	}
}

void Gameover::Update() {

}

