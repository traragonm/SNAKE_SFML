#pragma once
#include "State.h"
#include"Resource.h"
#include"SFML/Graphics.hpp"
class Gameover :
	public State
{
public:
	Gameover(GResource res,int score);
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
	sf::Text _Gameover;
	sf::Text _Score;
	sf::Text _Replay;
	int _ScoreV;
};

