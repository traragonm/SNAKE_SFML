#include "Intro.h"
Intro::Intro(GResource res) {
	_SRES = res;
	Init();
	std::cout << "Intro init" << std::endl;
}
Intro::~Intro() {
	std::cout << "Intro remove" << std::endl;
}
void Intro::Init() {
	
	this->_Backgound.setTexture(_SRES->_Image.GetTexture("splash"));
}
void Intro::Draw() {
	_SRES->_window.clear(sf::Color::White);
	_SRES->_window.draw(this->_Backgound);
	_SRES->_window.display();
}

void Intro::Handle(sf::Event event) {
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

void Intro::Update() {

}
