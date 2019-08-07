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
	_Background.setTexture(_SRES->_Image.GetTexture("Gameover"));
	_Background.setPosition(2 * 32, 4 * 32);
	_YES.setTexture(_SRES->_Image.GetTexture("YES"));
	_YES.setPosition(2 * 32, 11 * 32);
	_NO.setTexture(_SRES->_Image.GetTexture("NO"));
	_NO.setPosition(10 * 32, 11 * 32);
}
void Gameover::Draw() {
	_SRES->_window.clear(sf::Color::White);
	_SRES->_window.draw(_Background);
	_SRES->_window.draw(_YES);
	_SRES->_window.draw(_NO);
	_SRES->_window.display();
}

void Gameover::Handle(sf::Event event) {
	switch (event.key.code)
	{
	case sf::Mouse::Left:
		if (_SRES->_InputM.IsSpriteClicked(_YES, event.mouseButton.button, _SRES->_window)) {
			signal = 33;
		}
		else if (_SRES->_InputM.IsSpriteClicked(_NO, event.mouseButton.button, _SRES->_window)) {
			signal = 22;
		}
		break;
	default:
		break;
	}
}

void Gameover::Update() {

}

