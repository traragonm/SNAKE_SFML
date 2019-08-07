#pragma once
#include "State.h"
#include"Resource.h"
class Credit :
	public State
{
public:
	Credit(GResource res);
	~Credit();
	void Init();
	void Update();
	void Handle(sf::Event event);
	void Draw();
private:
	GResource _SRES;
	sf::Sprite _Background;
};

