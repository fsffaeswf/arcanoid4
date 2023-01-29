#pragma once
#include "settings.h"
#include "brick.h"
#include "SFML/Graphics.hpp"


struct BrickField {
	Brick arr[rows][columns];

};

void brick_field_init(BrickField& brickfield) {
	sf::Color color;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {

			if (i == 0 || i == 1) color = sf::Color::Red;
			else if (i == 2 || i == 3) color = sf::Color{ 255,102,0 };
			else if (i == 4 || i == 5) color = sf::Color::Green;
			else if (i == 6 || i == 7) color = sf::Color::Yellow;
			sf::Vector2f brick_pos{
				j * brick_width,brick_ofset + i * brick_height };
			brick_init(brickfield.arr[i][j], color, brick_pos);


		}
	}
}
void brick_field_update(BrickField& brickfield, Ball& ball) {
	sf::Vector2f mid_left{ ball.shape.getPosition().x, ball.shape.getPosition().y + ball_r };
	sf::Vector2f mid_right{ ball.shape.getPosition().x + 2 * ball_r, ball.shape.getPosition().y + ball_r };
	sf::Vector2f mid_bottom{ ball.shape.getPosition().x + ball_r, ball.shape.getPosition().y + 2 * ball_r };
	sf::Vector2f mid_up{ ball.shape.getPosition().x + 2 * ball_r, ball.shape.getPosition().y };
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			brick_update(brickfield.arr[i][j], ball);
			if (point_in_rect(brickfield.arr[i][j].shape, mid_bottom)) {
				ball.speedy *= -1;
				brickfield.arr[i][j].shape.setPosition(-20, -20);
				ball.score++;
				break;
				
			}
			if (point_in_rect(brickfield.arr[i][j].shape, mid_up)) {
				ball.speedy *= -1;
				brickfield.arr[i][j].shape.setPosition(-20, -20);
				ball.score++;
				
				break;
				
			}
			if (point_in_rect(brickfield.arr[i][j].shape, mid_left)) {
				ball.speedx *= -1;
				brickfield.arr[i][j].shape.setPosition(-20, -20);
				ball.score++;
				break;
				
			}
			if (point_in_rect(brickfield.arr[i][j].shape, mid_right)) {
				ball.speedx *= -1;
				brickfield.arr[i][j].shape.setPosition(-20, -20);
				ball.score++;
				break;
				
			}

		}
	}
}
void brick_field_draw(sf::RenderWindow& window, const BrickField& brickfield) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			brick_draw(brickfield.arr[i][j], window);
		}
	}
}