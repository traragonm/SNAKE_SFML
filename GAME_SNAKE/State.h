#pragma once
#include<memory>
#include"SFML/Graphics.hpp"
class State {
public:
	State();
	virtual ~State() = 0;
	virtual void Init() = 0;
	virtual void Handle(sf::Event event) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void restart();
	int getCode();
	int signal=0;
protected:
	int Codename;
};
typedef std::unique_ptr<State> GState;
