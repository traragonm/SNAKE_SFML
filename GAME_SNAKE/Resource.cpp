#include"Resource.h"
Resource::Resource(unsigned int x, unsigned int y) {
	_window.create(sf::VideoMode(x, y), "SNAKE C++",sf::Style::Close | sf::Style::Titlebar);
	_window.setFramerateLimit(10);
	std::cout << "Resource init" << std::endl;
}
Resource::~Resource() {
	std::cout << "Resource remove" << std::endl;
}