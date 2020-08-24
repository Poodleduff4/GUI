#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>
#include "ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENSIZE, SCREENSIZE), "GUI");
    sf::Event event;
	int x = 50, y = 50;
	float radius = 20;
	std::vector <Ball> circles;
	std::cout << circles.size() << std::endl;
	int numCircles = 0;
	const int fps = 60;
	srand(time(NULL));
	HWND hwnd = FindWindowW(NULL, L"GUI");
	sf::Clock clock;
	sf::Time elapsed = clock.restart();
	const sf::Time update_ms = sf::seconds(1.f / 30.f);

	while (window.isOpen())
	{
		Sleep(1000 / fps);
		window.clear();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
			else if (event.type == sf::Event::KeyPressed) { 
				if (event.key.code == sf::Keyboard::Space) {
					POINT cursor;
					GetCursorPos(&cursor);
					ScreenToClient(hwnd, &cursor);
					std::cout << cursor.x << " | " << cursor.y << '\n';
					Ball ball(cursor.x, cursor.y, 0, 1, sf::Color::Blue);
					circles.push_back(ball);
					std::cout << circles.size() << std::endl;
				}
				if (event.key.code == sf::Keyboard::G)
				{
					POINT cursor;
					GetCursorPos(&cursor);
					ScreenToClient(hwnd, &cursor);
					Ball ball(cursor.x, cursor.y, 0, 1, sf::Color::Green);
					ball.changeable = false;
					circles.push_back(ball);
					std::cout << circles.size() << std::endl;
				}
			}
		}

		for (int i = 0; i < circles.size(); i++)
		{
			circles[i].update();
			if (circles[i].ball.getFillColor() == sf::Color::Green)
			{
			circles[i].check_near(circles[i], circles);
			}
			window.draw(circles[i].ball);
		}


		window.display();
	}
	return 0;
}