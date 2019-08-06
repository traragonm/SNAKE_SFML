#pragma once
#include<string>
#include<map>
#include"SFML/Graphics.hpp"
class PNG{
public:
	PNG();
	~PNG();
	void LoadTexture(std::string path, std::string name);
	void LoadFont(std::string path, std::string name);
	void ClearTextures();
	void ClearFonts();
	sf::Texture& GetTexture(std::string name);
	sf::Font& GetFont(std::string name);
private:
	std::map<std::string, sf::Texture> _Textures;
	std::map<std::string, sf::Font> _Fonts;
};
