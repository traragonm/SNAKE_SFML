#include "Gameover.h"
Gameover::Gameover(GResource res,int score) {
	_SRES = res;
	Init();
	Codename = 5;
	value = score;
	std::cout << "Gameover init" << std::endl;
}
Gameover::~Gameover() {
	std::cout << "Gameover remove" << std::endl;
}
void Gameover::Init() {
	_YES.setTexture(_SRES->_Image.GetTexture("YES"));
	_YES.setPosition(1 * 32, 17 * 32);
	_NO.setTexture(_SRES->_Image.GetTexture("NO"));
	_NO.setPosition(10 * 32, 17 * 32);
	_Gameover.setFont(_SRES->_Image.GetFont("arial"));
	_Gameover.setFillColor(sf::Color::Red);
	_Gameover.setCharacterSize(60);
	_Gameover.setPosition(3*32,0);
	_Gameover.setString("GAME OVER");
	_Score.setFont(_SRES->_Image.GetFont("arial"));
	_Score.setFillColor(sf::Color::Blue);
	_Score.setCharacterSize(45);
	_Score.setPosition(5*32,4*32);
	_Score.setString("Your score: "+std::to_string(value));
	_Replay.setFont(_SRES->_Image.GetFont("arial"));
	_Replay.setFillColor(sf::Color::Green);
	_Replay.setCharacterSize(40);
	_Replay.setPosition(6 * 32, 12 * 32);
	_Replay.setString("RE-play ??");
}
void Gameover::Draw() {
	_SRES->_window.clear(sf::Color::White);
	_SRES->_window.draw(_Gameover);
	_SRES->_window.draw(_Score);
	_SRES->_window.draw(_Replay);
	_SRES->_window.draw(_YES);
	_SRES->_window.draw(_NO);
	_SRES->_window.display();
}

void Gameover::Handle(sf::Event event) {
	switch (event.key.code)
	{
	case sf::Mouse::Left:
		if (_SRES->_InputM.IsSpriteClicked(_YES, event.mouseButton.button, _SRES->_window)) {
			signal = 33;
		}
		else if (_SRES->_InputM.IsSpriteClicked(_NO, event.mouseButton.button, _SRES->_window)) {
			signal = 22;
		}
		break;
	default:
		break;
	}
}

void Gameover::Update() {

}

