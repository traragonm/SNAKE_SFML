#include"State.h"
#include<iostream>
State::State() {
	std::cout << "State init" << std::endl;
}
State::~State() {
	std::cout << "State remove" << std::endl;
}
int State::getCode() {
	return Codename;
}
void State::restart() {

}