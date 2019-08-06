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
private:
	GResource _SRES;
	SnakeT* _Snake;
	Fruit* _Apple;
	sf::Sprite _SnakeHead;
	sf::Sprite _SnakeHeadD;
	sf::Sprite _SnakeHeadL;
	sf::Sprite _SnakeHeadR;
	sf::Sprite _SnakeTrunk;
	sf::Sprite _AppleD;
	int dir;
	int length;
};

