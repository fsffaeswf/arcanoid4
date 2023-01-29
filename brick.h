#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
#include "bat.h"

struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};

void brick_init(Brick& brick, sf::Color color, sf::Vector2f position) {
	brick.color = color;
	brick.position = position;
	brick.shape.setSize(sf::Vector2f{ brick_width, brick_height });
	brick.shape.setFillColor(brick.color);
	brick.shape.setPosition(brick.position);
	brick.shape.setOutlineColor(sf::Color::Black);
	brick.shape.setOutlineThickness(1.f);
}
void brick_update(Brick& brick, Ball& ball) {}

void brick_draw(const Brick& brick, sf::RenderWindow& window) {
	window.draw(brick.shape);
}
