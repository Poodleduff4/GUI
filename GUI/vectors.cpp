#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <vector>
#include "ball.h"

int no()
{
	int x = 50, y = 50;
	float radius = 20;
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "GUI");
	sf::Event event;
	std::vector <sf::CircleShape> circles;
	std::cout << circles.size() << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		sf::CircleShape circle(20);
		circle.setFillColor(sf::Color::Blue);
		circle.setPosition(i*100, i*100);
		circles.push_back(circle);
	}
	

	int numCircles = 0;
	const int fps = 120;



	
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
		}

		for (int i = 0; i < circles.size(); i++)
		{
			//std::cout << circles[i].getPosition().x << " | " << circles[i].getPosition().y << std::endl;
			circles[i].move(2, 2);
			window.draw(circles[i]);
		}
		


		window.display();
	}
	return 0;
}