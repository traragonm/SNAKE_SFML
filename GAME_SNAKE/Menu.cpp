#include "Menu.h"
#include<iostream>
Menu::Menu(GResource res) {
	_SRES = res;
	std::cout << "Menu init" << std::endl;
}
Menu::~Menu() {
	std::cout << "Menu remove" << std::endl;
}
void Menu::Init() {

}
void Menu::Draw() {
	_SRES->_window.clear(sf::Color::Yellow);
	_SRES->_window.display();
}

void Menu::Handle(sf::Event event) {
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

void Menu::Update() {

}
