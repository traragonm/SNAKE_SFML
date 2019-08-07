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
	length = 6;
	_Snake[0]._X = 5;
	_Snake[0]._Y = 5;
	_Snake[0]._Dir = 1;
	for (int i = 1; i < length;i++) {
		_Snake[i]._Dir = 1;
	}
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
	_AppleD.setTexture(_SRES->_Image.GetTexture("apple"));
	_AppleD.setScale(0.5, 0.5);
	_SnakeTail.setTexture(_SRES->_Image.GetTexture("Tailup"));
	_SnakeTail.setScale(0.5,0.5);
	_SnakeTailD.setTexture(_SRES->_Image.GetTexture("Taildown"));
	_SnakeTailD.setScale(0.5, 0.5);
	_SnakeTailL.setTexture(_SRES->_Image.GetTexture("Tailleft"));
	_SnakeTailL.setScale(0.5, 0.5);
	_SnakeTailR.setTexture(_SRES->_Image.GetTexture("Tailright"));
	_SnakeTailR.setScale(0.5, 0.5);
	_SnakeTrunkH.setTexture(_SRES->_Image.GetTexture("Horizontal"));
	_SnakeTrunkH.setScale(0.5, 0.5);
	_SnakeTrunkV.setTexture(_SRES->_Image.GetTexture("Vertical"));
	_SnakeTrunkV.setScale(0.5, 0.5);
	_SnakeTrunkLD.setTexture(_SRES->_Image.GetTexture("Leftdown"));
	_SnakeTrunkLD.setScale(0.5, 0.5);
	_SnakeTrunkLU.setTexture(_SRES->_Image.GetTexture("Leftup"));
	_SnakeTrunkLU.setScale(0.5, 0.5);
	_SnakeTrunkRD.setTexture(_SRES->_Image.GetTexture("Rightdown"));
	_SnakeTrunkRD.setScale(0.5, 0.5);
	_SnakeTrunkRU.setTexture(_SRES->_Image.GetTexture("Rightup"));
	_SnakeTrunkRU.setScale(0.5, 0.5);
}
void Gameplay::restart() {
	delete[]_Snake;
	delete _Apple;
	_Snake = new SnakeT[60];
	_Apple = new Fruit();
	length = 6;
	_Snake[0]._X = 5;
	_Snake[0]._Y = 5;
	_Snake[0]._Dir = 1;
	for (int i = 1; i < length; i++) {
		_Snake[i]._Dir = 1;
	}
	_Apple->_X = rand() % 16;
	_Apple->_Y = rand() % 20;
}
void Gameplay::Draw() {
	_SRES->_window.clear(sf::Color::White);
	switch (_Snake[0]._Dir) {
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
	for (int i = length - 2; i > 1; i-- ) {
		
		switch (_Snake[i]._Dir)
		{
		case 1:
			switch (_Snake[i-1]._Dir)
			{
			case 1:
				_SnakeTrunkV.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkV);
				break;
			case 2:
				_SnakeTrunkLD.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkLD);
				break;
			case 3:
				_SnakeTrunkRD.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkRD);
				break;
			case 4:
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (_Snake[i - 1]._Dir)
			{
			case 1:
				_SnakeTrunkRU.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkRU);
				break;
			case 2:
				_SnakeTrunkH.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkH);
				break;
			case 3:
				break;
			case 4:
				_SnakeTrunkRD.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkRD);
				break;
			default:
				break;
			}
			break;
		case 3:
			switch (_Snake[i - 1]._Dir)
			{
			case 1:
				_SnakeTrunkLU.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkLU);
				break;
			case 2:
				break;
			case 3:
				_SnakeTrunkH.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkH);
				break;
			case 4:
				_SnakeTrunkLD.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkLD);
				break;
			default:
				break;
			}
			break;
		case 4:
			switch (_Snake[i - 1]._Dir)
			{
			case 1:
				
				break;
			case 2:
				_SnakeTrunkLU.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkLU);
				break;
			case 3:
				_SnakeTrunkRU.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkRU);
				break;
			case 4:
				_SnakeTrunkV.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkV);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		
		
	}
	switch (_Snake[length - 2]._Dir) {
	case 1:
		_SnakeTail.setPosition(_Snake[length - 1]._X * 32, _Snake[length - 1]._Y * 32);
		_SRES->_window.draw(_SnakeTail);
		break;
	case 2:
		_SnakeTailL.setPosition(_Snake[length - 1]._X * 32, _Snake[length - 1]._Y * 32);
		_SRES->_window.draw(_SnakeTailL);
		break;
	case 3:
		_SnakeTailR.setPosition(_Snake[length - 1]._X * 32, _Snake[length - 1]._Y * 32);
		_SRES->_window.draw(_SnakeTailR);
		break;
	case 4:
		_SnakeTailD.setPosition(_Snake[length - 1]._X * 32, _Snake[length - 1]._Y * 32);
		_SRES->_window.draw(_SnakeTailD);
		break;
	default:
		break;
	}

	_AppleD.setPosition(_Apple->_X*32, _Apple->_Y*32);
	_SRES->_window.draw(_AppleD);
	_SRES->_window.display();
}

void Gameplay::Handle(sf::Event event) {
	switch (event.key.code)
	{
	case sf::Keyboard::Left:
		_Snake[0]._Dir = 2;
		break;
	case sf::Keyboard::Right:
		_Snake[0]._Dir = 3;
		break;
	case sf::Keyboard::Up:
		_Snake[0]._Dir = 1;
		break;
	case sf::Keyboard::Down:
		_Snake[0]._Dir = 4;
		break;
	default:
		break;
	}
}

void Gameplay::Update() {
	
	switch (_Snake[0]._Dir)
	{
	case 1:
		_Snake[0]._Y -= 1;
		break;
	case 2:
		_Snake[0]._X -= 1;
		break;
	case 3:
		_Snake[0]._X += 1;
		break;
	case 4:
		_Snake[0]._Y += 1;
		break;
	default:
		break;
	}
	for (int i = length - 1; i > 0; i--) {
		_Snake[i]._X = _Snake[i - 1]._X;
		_Snake[i]._Y = _Snake[i - 1]._Y;
		_Snake[i]._Dir = _Snake[i - 1]._Dir;
	}
	
	if ((_Snake[0]._X==_Apple->_X) && (_Snake[0]._Y== _Apple->_Y))
	{
		length++;
		_Apple->_X = rand() % 16;
		_Apple->_Y = rand() % 20;
	}
	if (_Snake[0]._X> 15) _Snake[0]._X= 0;  if (_Snake[0]._X< 0) _Snake[0]._X= 16;
	if (_Snake[0]._Y> 19) _Snake[0]._Y= 0;  if (_Snake[0]._Y< 0) _Snake[0]._Y= 20;
	if (_Snake[1]._X > 15) _Snake[1]._X = 0;  if (_Snake[1]._X < 0) _Snake[1]._X = 16;
	if (_Snake[1]._Y > 19) _Snake[1]._Y = 0;  if (_Snake[1]._Y < 0) _Snake[1]._Y = 20;
	for (int i = 2; i < length; i++) {
		if (_Snake[1]._X == _Snake[i]._X && _Snake[1]._Y == _Snake[i]._Y) {
			restart();

		}
	}
		
}

