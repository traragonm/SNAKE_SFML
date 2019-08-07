#pragma once
#include "State.h"
#include"Resource.h"
#include"SFML/Graphics.hpp"
class Gameover :
	public State
{
public:
	Gameover(GResource res);
	~Gameover();
	void Init();
	void Handle(sf::Event event);
	void Update();
	void Draw();
private:
	GResource _SRES;
	sf::Sprite _Background;
	sf::Sprite _YES;
	sf::Sprite _NO;
};

