#include "Gameplay.h"
#include<iostream>
Gameplay::Gameplay(GResource res) {
	_SRES = res;
	Init();
	std::cout << "Gameplay_init" << std::endl;
}
Gameplay::~Gameplay() {
	delete[]_Snake;
	delete _Apple;
	std::cout << "Gameplay_remove" << std::endl;
}
void Gameplay::Init() {
	_Snake = new SnakeT[60];
	_Apple = new Fruit();
	dir = 1;
	length = 4;
	_Snake[0]._X = 5;
	_Snake[0]._Y = 5;
	_Apple->_X = rand() % 16;
	_Apple->_Y = rand() % 20;
	_SnakeHead.setTexture(_SRES->_Image.GetTexture("Headup"));
	_SnakeHead.setScale(0.5, 0.5);
	_SnakeHeadD.setTexture(_SRES->_Image.GetTexture("Headdown"));
	_SnakeHeadD.setScale(0.5, 0.5);
	_SnakeHeadL.setTexture(_SRES->_Image.GetTexture("Headleft"));
	_SnakeHeadL.setScale(0.5, 0.5);
	_SnakeHeadR.setTexture(_SRES->_Image.GetTexture("Headright"));
	_SnakeHeadR.setScale(0.5, 0.5);
	_SnakeTrunk.setTexture(_SRES->_Image.GetTexture("Trunk"));
	_SnakeTrunk.setScale(0.5, 0.5);
	_AppleD.setTexture(_SRES->_Image.GetTexture("apple"));
	_AppleD.setScale(0.5, 0.5);

}
void Gameplay::Draw() {
	_SRES->_window.clear(sf::Color::Black);
	switch (dir) {
	case 1:
		_SnakeHead.setPosition(_Snake[0]._X*32,_Snake[0]._Y*32);
		_SRES->_window.draw(_SnakeHead);
		break;
	case 2:
		_SnakeHeadL.setPosition(_Snake[0]._X*32, _Snake[0]._Y*32);
		_SRES->_window.draw(_SnakeHeadL);
		break;
	case 3:
		_SnakeHeadR.setPosition(_Snake[0]._X*32, _Snake[0]._Y*32);
		_SRES->_window.draw(_SnakeHeadR);
		break;
	case 4:
		_SnakeHeadD.setPosition(_Snake[0]._X*32, _Snake[0]._Y*32);
		_SRES->_window.draw(_SnakeHeadD);
		break;
	}
	for (int i = length; i > 0; i--) {
		_SnakeTrunk.setPosition(_Snake[i]._X*32, _Snake[i]._Y*32);
		_SRES->_window.draw(_SnakeTrunk);
	}
	_AppleD.setPosition(_Apple->_X*32, _Apple->_Y*32);
	_SRES->_window.draw(_AppleD);
	_SRES->_window.display();
}

void Gameplay::Handle(sf::Event event) {
	switch (event.key.code)
	{
	case sf::Keyboard::Left:
		dir = 2;
		break;
	case sf::Keyboard::Right:
		dir = 3;
		break;
	case sf::Keyboard::Up:
		dir = 1;
		break;
	case sf::Keyboard::Down:
		dir = 4;
		break;
	default:
		break;
	}
}

void Gameplay::Update() {
	for (int i = length; i > 0; --i)
	{
		_Snake[i]._X= _Snake[i - 1]._X;
		_Snake[i]._Y= _Snake[i - 1]._Y;
	}

	if (dir == 4) _Snake[0]._Y+= 1;
	if (dir == 2) _Snake[0]._X-= 1;
	if (dir == 3) _Snake[0]._X+= 1;
	if (dir == 1) _Snake[0]._Y-= 1;
	if ((_Snake[0]._X==_Apple->_X) && (_Snake[0]._Y== _Apple->_Y))
	{
		length++;
		_Apple->_X = rand() % 16;
		_Apple->_Y = rand() % 20;
	}

	if (_Snake[0]._X> 15) _Snake[0]._X= 0;  if (_Snake[0]._X< 0) _Snake[0]._X= 16;
	if (_Snake[0]._Y> 19) _Snake[0]._Y= 0;  if (_Snake[0]._Y< 0) _Snake[0]._Y= 20;

	//for (int i = 1; i < length; i++)
		//if (_Snake[0]._X == _Snake[i]._X && _Snake[0]._Y == _Snake[i]._Y);
}

