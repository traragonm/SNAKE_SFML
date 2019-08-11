#include "Credit.h"
Credit::Credit(GResource res) {
	_SRES = res;
	Init();
	Codename = 4;
	signal = 0;
	std::cout << "Credit init" << std::endl;
}
Credit::~Credit() {
	std::cout << "Credit remove" << std::endl;
}
void Credit::Init() {
	_Background.setTexture(_SRES->_Image.GetTexture("C"));
}
void Credit::Draw() {
	_SRES->_window.clear(sf::Color::White);
	_SRES->_window.draw(_Background);
	_SRES->_window.display();
}

void Credit::Handle(sf::Event event) {
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

void Credit::Update() {

}
