#include "StateManager.h"
#include<iostream>
StateManager::StateManager() {
	std::cout << "StateManager init" << std::endl;
}
StateManager::~StateManager() {
	std::cout << "StateManager remove" << std::endl;
}
void StateManager::AddState(GState s) {
	_States.push(std::move(s));
}
void StateManager::ClearStack() {
	while (!_States.empty()) {
		_States.pop();
	}
	std::cout << "Stack is empty" << std::endl;
}
GState& StateManager::GetCurrState() {
	return this->_States.top();
}
void StateManager::RemoveState() {
	if (_States.size()==1) {
		std::cout << "Stack can not delete" << std::endl;
	}
	else if (!_States.empty()) {
		_States.pop();
	}
	else std::cout << "Stack is empty" << std::endl;
}