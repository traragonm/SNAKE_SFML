#pragma once
#include "State.h"
#include"Resource.h"
#include"SFML/Graphics.hpp"
class Menu :
	public State
{
public:
	Menu(GResource res);
	~Menu();
	void Init();
	void Update();
	void Handle(sf::Event event);
	void Draw();
private:
	GResource _SRES;
	sf::Sprite _Background;
	sf::Sprite _Play;
	sf::Sprite _Credit;
	sf::Sprite _Exit;
};

