#include"Fruit.h"
#include<iostream>
Fruit::Fruit() {
	std::cout << "Fruit init" << std::endl;
}
Fruit::~Fruit() {
	std::cout << "Fruit remove" << std::endl;
}