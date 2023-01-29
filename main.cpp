#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include "func.h"
#include "bat.h"
#include "ball.h"
#include "brick.h"
#include "brickRow.h"
#include "textObj.h"
using namespace sf;


int main()
{

	Bat bat;
	bat_init(bat);

	Ball ball;
	ball_init(ball);

	Brick brick;

	BrickField brick_field;
	brick_field_init(brick_field);

	TextObj text;
	text_init(text, ball.score);

	RenderWindow window(VideoMode(window_size, window_size), "SFML Works!");

	window.setFramerateLimit(fps);


	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed) {

				window.close();
			}
		}

		Vector2f mid_left{ ball.shape.getPosition().x, ball.shape.getPosition().y + ball_r };
		Vector2f mid_right{ ball.shape.getPosition().x + 2 * ball_r, ball.shape.getPosition().y + ball_r };
		Vector2f mid_bottom{ ball.shape.getPosition().x + ball_r, ball.shape.getPosition().y + 2 * ball_r };

		if (point_in_rect(bat.shape, mid_bottom)) {
			ball.speedy *= -1;
		}
		if (point_in_rect(bat.shape, mid_left)) {
			ball.speedx *= -1;
		}
		if (point_in_rect(bat.shape, mid_right)) {
			ball.speedx *= -1;
		}



		bat_update(bat, ball);
		ball_update(ball);
		textUpdate(text, ball.score);
		brick_field_update(brick_field, ball);
		if(ball.score == 160)window.close();

		window.clear();
		bat_draw(bat, window);
		ball_draw(ball, window);
		textDraw(window, text);
		brick_field_draw(window, brick_field);
		window.display();
	}
	return 0;
}