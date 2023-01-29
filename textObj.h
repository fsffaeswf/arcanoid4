#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct TextObj {
	sf::Font font;
	sf::Text text;
};

void text_init(TextObj& textobj, int score) {
	textobj.font.loadFromFile("DS-DIGIB.ttf");
	textobj.text.setString(std::to_string(score));
	textobj.text.setFont(textobj.font);
	textobj.text.setCharacterSize(char_size);
	textobj.text.setPosition(text_start_pos);
}
void textUpdate(TextObj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}
void textDraw(sf::RenderWindow& window, const TextObj& textobj) {
	window.draw(textobj.text);
}