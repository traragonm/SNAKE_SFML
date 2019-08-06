#pragma once
#include<memory>
#include"PNG.h"
#include"StateManager.h"
#include<iostream>
struct Resource {
	Resource(unsigned int x, unsigned int y);
	~Resource();
	PNG _Image;
	StateManager _StateM;
	sf::RenderWindow _window;
};
typedef std::shared_ptr<Resource> GResource;