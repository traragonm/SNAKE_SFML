#include "PNG.h"
#include<iostream>
PNG::PNG() {
	std::cout << "PNG init" << std::endl;
}
PNG::~PNG() {
	std::cout << "PNG remove" << std::endl;
}
void PNG::LoadTexture(std::string path, std::string name) {
	sf::Texture t;
	if (t.loadFromFile(path)) {
		this->_Textures[name]=t;
	}
	else std::cout << "Textures loading error" << std::endl;
}
void PNG::LoadFont(std::string path, std::string name) {
	sf::Font f;
	if (f.loadFromFile(path)) {
		this->_Fonts[name]=f;
	}
	else std::cout << "Fonts loading error" << std::endl;
}
void PNG::ClearFonts() {
	if (!_Fonts.empty()) {
		_Fonts.clear();
	}
	std::cout << "Fonts is empty" << std::endl;
}
void PNG::ClearTextures() {
	if (!_Textures.empty()) {
		_Textures.clear();
	}
	std::cout << "Texeture is empty" << std::endl;
}
sf::Texture& PNG::GetTexture(std::string name) {
	return this->_Textures.at(name);
}
sf::Font& PNG::GetFont(std::string name) {
	return this->_Fonts.at(name);
}
void PNG::LoadSoundBuffer(std::string path, std::string name) {
	sf::SoundBuffer s;
	if (s.loadFromFile(path)) {
		this->_Sounds[name] = s;
	}
	else std::cout << "Sound buffer loading error" << std::endl;
}
void PNG::ClearSoundBuffer() {
	if (!_Sounds.empty()) {
		_Sounds.clear();
	}
	std::cout << "Sounds is empty" << std::endl;
}
sf::SoundBuffer& PNG::GetSoundBuffer(std::string name) {
	return this->_Sounds.at(name);
}