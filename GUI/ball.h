#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

const float ballRadius = 20;
const int SCREENSIZE = 1000;
struct Ball
{
	sf::CircleShape ball;
	sf::Vector2f velocity;
    int numUpdates = 0;
    bool changeable = true;
    Ball(float x, float y, float vx, float vy, sf::Color color)
    {
        velocity.x = vx;
        velocity.y = vy;
        ball.setRadius(20);
        ball.setFillColor(color);
        ball.setOrigin(ballRadius, ballRadius);
        ball.setPosition(x, y);
    }

    void update() {
        ball.move(velocity);

        if (ball.getPosition().x - ballRadius <= 0)
            velocity.x = -velocity.x;
        else if(ball.getPosition().x + ballRadius >= SCREENSIZE)
            velocity.x = -velocity.x;

        if (ball.getPosition().y - ballRadius <= 0)
            velocity.y = -velocity.y;
        else if (ball.getPosition().y + ballRadius >= SCREENSIZE)
            velocity.y = -velocity.y;
    }

    void check_near(Ball &check_ball, std::vector<Ball>& balls) {
        sf::Vector2f pos;
        sf::Vector2f ballPos = check_ball.ball.getPosition();
        //std::cout << balls.size() << '\n';
        for (int i = 0; i < balls.size(); i++) //check for balls near the check_ball which will be green
        {
            pos = balls[i].ball.getPosition();
            //std::cout << balls[i].ball.getPosition().x << " | " << balls[i].ball.getPosition().y << '\n';
            if (balls[i].ball.getFillColor() != sf::Color::Green) {
                if ((std::abs(ballPos.x - pos.x) - ballRadius * 2 <= 50 && std::abs(ballPos.y - pos.y) - ballRadius * 2 <= 50) && (&check_ball != &balls[i]))
                {
                    balls[i].ball.setFillColor(sf::Color::Green);
                }
            }
            else
            {
                continue;
            }


            //if ((std::abs(ballPos.x - pos.x) - ballRadius * 2 <= 50 && std::abs(ballPos.y - pos.y) - ballRadius * 2 <= 50) && (&check_ball != &balls[i]) && (check_ball.ball.getFillColor() == sf::Color::Green || balls[i].ball.getFillColor() == sf::Color::Green))
            //{
            //    check_ball.ball.setFillColor(sf::Color::Green);
            //    balls[i].ball.setFillColor(sf::Color::Green);
            //}
            //else if (check_ball.changeable)
            //{
            //    check_ball.ball.setFillColor(sf::Color::Blue);
            //    //balls[i].ball.setFillColor(sf::Color::Blue);
            //}
        }
    }
};