
#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "brick.h"


bool point_in_rect(const sf::RectangleShape bat, sf::Vector2f point) {
	float batx = bat.getPosition().x;
	float baty = bat.getPosition().y;
	return(point.x >= batx && point.x <= batx + bat.getSize().x) &&
		(point.y >= baty && point.y <= baty + bat.getSize().y);
}