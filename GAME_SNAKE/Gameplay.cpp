#include "Gameplay.h"
#include<iostream>
Gameplay::Gameplay(GResource res) {
	_SRES = res;
	Init();
	Codename = 3;
	signal = 0;
	std::cout << "Gameplay_init" << std::endl;
}
Gameplay::~Gameplay() {
	delete[]_Snake;
	delete _Apple;
	std::cout << "Gameplay_remove" << std::endl;
}
void Gameplay::Init() {
	_Snake = new SnakeT[85];
	_Apple = new Fruit();
	length = 3;
	//_Snake[0]._X = 5;
	//_Snake[0]._Y = 5;
	//_Snake[0]._Dir = 1;
	Dir = 1;
	DirX = 5;
	DirY = 12;
	for (int i = 0; i < length;i++) {
		_Snake[i]._Dir = 1;
	}
	_Apple->_X = rand() % 17;
	_Apple->_Y = rand() % 21;
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
	_Bite.setBuffer(_SRES->_Image.GetSoundBuffer("applebite"));
	_Bite.setVolume(40);
}
void Gameplay::restart() {
	_Snake = new SnakeT[85];
	_Apple = new Fruit();
	length = 3;
	//_Snake[0]._X = 5;
	//_Snake[0]._Y = 5;
	//_Snake[0]._Dir = 1;
	Dir = 1;
	DirX = 5;
	DirY = 12;
	for (int i = 0; i < length; i++) {
		_Snake[i]._Dir = 1;
	}
	_Apple->_X = rand() % 17;
	_Apple->_Y = rand() % 21;
}
void Gameplay::Draw() {
	_SRES->_window.clear(sf::Color::White);
	switch (Dir) {
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
	for (int i = length - 2; i > 0; i-- ) {
		
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
			case 3:
				_SnakeTrunkH.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkH);
				break;
			case 4:
				_SnakeTrunkLD.setPosition(_Snake[i]._X * 32, _Snake[i]._Y * 32);
				_SRES->_window.draw(_SnakeTrunkLD);
				break;
			}
			break;
		case 4:
			switch (_Snake[i - 1]._Dir)
			{
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
			}
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
	}

	_AppleD.setPosition(_Apple->_X*32, _Apple->_Y*32);
	_SRES->_window.draw(_AppleD);
	_SRES->_window.display();
}

void Gameplay::Handle(sf::Event event) {
	switch (event.key.code)
	{
	case sf::Keyboard::Left:
		if (Dir == 3) {

		}
		else Dir = 2;
		break;
	case sf::Keyboard::Right:
		if (Dir == 2) {

		}else Dir = 3;
		break;
	case sf::Keyboard::Up:
		if (Dir == 4) {

		}else Dir = 1;
		break;
	case sf::Keyboard::Down:
		if (Dir == 1) {

		}else Dir = 4;
		break;
	default:
		break;
	}
}

void Gameplay::Update() {
	
	switch (Dir)
	{
	case 1:
		DirY -= 1;
		break;
	case 2:
		DirX -= 1;
		break;
	case 3:
		DirX += 1;
		break;
	case 4:
		DirY += 1;
		break;
	default:
		break;
	}
	for (int i = length - 1; i >= 0; i--) {
		
		if (i == 0) {
			_Snake[i]._X =DirX;
			_Snake[i]._Y = DirY;
			_Snake[i]._Dir = Dir;
		}
		else {
			_Snake[i]._X = _Snake[i - 1]._X;
			_Snake[i]._Y = _Snake[i - 1]._Y;
			_Snake[i]._Dir = _Snake[i - 1]._Dir;
		}
	}
	
	if ((_Snake[0]._X==_Apple->_X) && (_Snake[0]._Y== _Apple->_Y))
	{
		_Bite.play();
		length++;
		_Apple->_X = rand() % 17;
		_Apple->_Y = rand() % 21;
	}
	if (DirX >= 17) signal=5;//DirX= 0; 
	if (DirX< 0) signal = 5;//DirX= 16;
	if (DirY>= 21) signal = 5;//DirY= 0;  
	if (DirY< 0) signal = 5;//DirY= 20;
	for (int i = 2; i < length; i++) {
		if (_Snake[0]._X == _Snake[i]._X && _Snake[0]._Y == _Snake[i]._Y) {
			signal = 5;

		}
	}
		
}

