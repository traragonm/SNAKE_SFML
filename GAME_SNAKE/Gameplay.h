#pragma once
#include "State.h"
#include"Resource.h"
#include"SnakeT.h"
#include"Fruit.h"
class Gameplay :
	public State
{
public:
	Gameplay(GResource res);
	~Gameplay();
	void Init();
	void Update();
	void Handle(sf::Event event);
	void Draw();
	void restart();
private:
	GResource _SRES;
	SnakeT* _Snake;
	Fruit* _Apple;
	sf::Sprite _SnakeHead;
	sf::Sprite _SnakeHeadD;
	sf::Sprite _SnakeHeadL;
	sf::Sprite _SnakeHeadR;
	sf::Sprite _AppleD;
	sf::Sprite _SnakeTail;
	sf::Sprite _SnakeTailD;
	sf::Sprite _SnakeTailL;
	sf::Sprite _SnakeTailR;
	sf::Sprite _SnakeTrunkH;
	sf::Sprite _SnakeTrunkV;
	sf::Sprite _SnakeTrunkLU;
	sf::Sprite _SnakeTrunkLD;
	sf::Sprite _SnakeTrunkRU;
	sf::Sprite _SnakeTrunkRD;
	sf::Sprite _Score;
	
	int Dir;
	int DirX;
	int DirY;
	int length;
};

