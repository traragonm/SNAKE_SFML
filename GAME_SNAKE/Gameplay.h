#pragma once
#include "State.h"
#include"Resource.h"
#include"SnakeT.h"
#include"Fruit.h"
#include"SFML/Audio.hpp"
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
	sf::Sprite _Replay;
	sf::Sprite _OverFrame;
	sf::Sprite _Back;
	sf::Sprite _Gameover;
	sf::Text _Score;
	sf::Sound _Bite;
	sf::Sound _Hit;
	int Dir;
	int DirX;
	int DirY;
	int length;
	bool IsPlay = true;
	void DrawGame();
	void DrawOver();
	void UpdateGame();
	void UpdateOver();
	void HandleGame(sf::Event event);
	void HandleOver(sf::Event event);
	void restart();
};

