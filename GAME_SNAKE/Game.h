#pragma once
#include"Resource.h"
#include"State.h"
#include<stack>
#include<iostream>
class Game{
public :
	Game();
	~Game();
private:
	GResource _Res;
	void Init();
	void Run();
	sf::Clock _Clock;
	float timer = 0, delay = 0.1;
};

