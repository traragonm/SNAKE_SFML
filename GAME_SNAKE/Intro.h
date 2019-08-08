#pragma once
#include "State.h"
#include"Resource.h"
class Intro :
	public State
{
public:
	Intro(GResource res);
	~Intro();
	void Init();
	void Update();
	void Handle(sf::Event event);
	void Draw();
private:
	GResource _SRES;
	sf::Sprite _Backgound;
	sf::Clock _Clock;
	float _Delay = 1;
};

