#pragma once
#include"Resource.h"
#include"SFML/Audio.hpp"
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
	float delay = 0.1;
	sf::Sound _Themesong;
};

