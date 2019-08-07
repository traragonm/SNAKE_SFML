#include "Game.h"
#include"Gameplay.h"
#include"Intro.h"
#include"Menu.h"
#include"define.h"
#include"Gameover.h"
#include"Credit.h"
Game::Game() {
	int HEIGHT = 32 * HEIGHT_SIZE_BY_PIXELS;
	int WIDTH = 32 * WIDTH_SIZE_BY_PIXELS;
	_Res = std::make_shared<Resource>(WIDTH,HEIGHT);
	std::cout << "Game init" << std::endl;
	Init();
}
Game::~Game() {
	_Res->_StateM.ClearStack();
	_Res->_Image.ClearFonts();
	_Res->_Image.ClearTextures();
	std::cout << "Game remove" << std::endl;
}
void Game::Init() {
	_Res->_Image.LoadTexture("res/image/splash.png", "splash");
	_Res->_Image.LoadTexture("res/image/Headup.png", "Headup");
	_Res->_Image.LoadTexture("res/image/Headdown.png", "Headdown");
	_Res->_Image.LoadTexture("res/image/Headleft.png", "Headleft");
	_Res->_Image.LoadTexture("res/image/Headright.png", "Headright");
	_Res->_Image.LoadTexture("res/image/Tailup.png", "Tailup");
	_Res->_Image.LoadTexture("res/image/Taildown.png", "Taildown");
	_Res->_Image.LoadTexture("res/image/Tailleft.png", "Tailleft");
	_Res->_Image.LoadTexture("res/image/Tailright.png", "Tailright");
	_Res->_Image.LoadTexture("res/image/Leftup.png", "Leftup");
	_Res->_Image.LoadTexture("res/image/Leftdown.png", "Leftdown");
	_Res->_Image.LoadTexture("res/image/Rightup.png", "Rightup");
	_Res->_Image.LoadTexture("res/image/Rightdown.png", "Rightdown");
	_Res->_Image.LoadTexture("res/image/apple.png", "apple");
	_Res->_Image.LoadTexture("res/image/H.png", "Horizontal");
	_Res->_Image.LoadTexture("res/image/V.png", "Vertical");
	_Res->_Image.LoadTexture("res/image/Credit.png", "Credit");
	_Res->_Image.LoadTexture("res/image/Play.png", "Play");
	_Res->_Image.LoadTexture("res/image/Exit.png", "Exit");
	_Res->_Image.LoadTexture("res/image/YES.png", "YES");
	_Res->_Image.LoadTexture("res/image/NO.png", "NO");
	_Res->_Image.LoadTexture("res/image/Creditback.png", "Creditback");
	_Res->_Image.LoadTexture("res/image/Gameover.png", "Gameover");
	_Res->_Image.LoadTexture("res/image/Mainmenu.jpg", "Menuback");
	
	_Res->_StateM.AddState(std::make_unique<Menu>(_Res));
	_Res->_StateM.AddState(std::make_unique<Intro>(_Res));
	
	Run();
}
void Game::Run() {
	while (_Res->_window.isOpen()) {
		sf::Event event;
		if (_Res->_StateM.GetCurrState()->signal == 0) {
			while (_Res->_window.pollEvent(event)) {
				switch (event.type)
				{
				case sf::Event::Closed:
					_Res->_window.close();
					break;
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Escape) _Res->_StateM.RemoveState();
					else _Res->_StateM.GetCurrState()->Handle(event);
					break;
				case sf::Event::MouseButtonPressed:
					_Res->_StateM.GetCurrState()->Handle(event);
					break;
				default:
					break;
				}
			}

			_Res->_StateM.GetCurrState()->Update();
			_Res->_StateM.GetCurrState()->Draw();
		}
		else {
			switch (_Res->_StateM.GetCurrState()->signal)
			{
			case -1:
				_Res->_window.close();
			case 2:
				break;
			case 3:
				_Res->_StateM.GetCurrState()->signal = 0;
				_Res->_StateM.AddState(std::make_unique<Gameplay>(_Res));
				break;
			case 4:
				break;
			case 5:
				_Res->_StateM.GetCurrState()->signal = 0;
				_Res->_StateM.AddState(std::make_unique<Gameover>(_Res));
				break;
			case 33:
				_Res->_StateM.RemoveState();
				_Res->_StateM.GetCurrState()->restart();
				break;
			case 22:
				_Res->_StateM.RemoveState();
				_Res->_StateM.RemoveState();
				break;
			default:
				break;
			}
		}
		
		
	}
	

}
