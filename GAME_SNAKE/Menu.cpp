#include "Menu.h"
#include<iostream>
Menu::Menu(GResource res) {
	_SRES = res;
	Init();
	signal = 0;
	Codename = 2;
	std::cout << "Menu init" << std::endl;
}
Menu::~Menu() {
	std::cout << "Menu remove" << std::endl;
}
void Menu::Init() {
	_Background.setTexture(_SRES->_Image.GetTexture("Menuback"));
	_Play.setTexture(_SRES->_Image.GetTexture("Play"));
	_Play.setPosition(1 * 32,7 * 32);
	_Credit.setTexture(_SRES->_Image.GetTexture("Credit"));
	_Credit.setPosition(3 * 32, 10 * 32);
	_Exit.setTexture(_SRES->_Image.GetTexture("Exit"));
	_Exit.setPosition(5 * 32, 13 * 32);
}
void Menu::Draw() {
	_SRES->_window.clear(sf::Color::White);
	_SRES->_window.draw(_Background);
	_SRES->_window.draw(_Play);
	_SRES->_window.draw(_Credit);
	_SRES->_window.draw(_Exit);
	_SRES->_window.display();
}

void Menu::Handle(sf::Event event) {
	switch (event.key.code)
	{
	case sf::Mouse::Left:
		if (_SRES->_InputM.IsSpriteClicked(_Play, event.mouseButton.button, _SRES->_window)) {
			signal = 3;
		}
		else if (_SRES->_InputM.IsSpriteClicked(_Credit, event.mouseButton.button, _SRES->_window)) {
			signal = 4;
		}
		else if (_SRES->_InputM.IsSpriteClicked(_Exit, event.mouseButton.button, _SRES->_window)) {
			signal = -1;
		}
		break;
	default:
		break;
	}
}

void Menu::Update() {

}
