#pragma once
#include "State.h"
#include"Resource.h"
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
};

