#pragma once
#include "State.h"
#include"Resource.h"
class Gameover :
	public State
{
	Gameover(GResource res);
	~Gameover();
	void Init();
	void Handle(sf::Event event);
	void Update();
	void Draw();
private:
	GResource _SRES;
};

