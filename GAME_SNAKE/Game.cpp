#include "Game.h"
#include"Gameplay.h"
#include"Intro.h"
#include"Menu.h"
#include"define.h"
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
	_Res->_Image.LoadTexture("res/image/trunk.png", "Trunk");
	_Res->_Image.LoadTexture("res/image/apple.png", "apple");
	_Res->_StateM.AddState(std::make_unique<Intro>(_Res));
	_Res->_StateM.AddState(std::make_unique<Gameplay>(_Res));
	
	Run();
}
void Game::Run() {
	while (_Res->_window.isOpen()) {
		sf::Event event;
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
			default:
				break;
			}
		}
		_Res->_StateM.GetCurrState()->Update();
		_Res->_StateM.GetCurrState()->Draw();
		
	}
	

}
