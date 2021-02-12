#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "stdafx.h"
#include "GameSound.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>

using namespace sf;
using namespace std;

/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/


int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game

	RenderWindow window(vm, "Bonger Ball", Style::Fullscreen);

	int level = 1;
	int score = 0;
	int lives = 5;

	// Create a paddle
	Paddle paddle(1920 / 2, 1080 - 20);

	// We will add a ball in the next chapter
	Ball ball(1920 / 2, 0);


	//TESTING FOR BRICK

	//int numBricks = 20;
	vector<Brick> brickVector;

	int xCoordinates = 100;
	int yCoordinates = 100;

	for (int i = 0; i < 30; i++)
	{
		Brick brick(xCoordinates, yCoordinates);
		brickVector.push_back(brick);

		xCoordinates += 100;

		if (i == 9 || i == 19)
		{
			yCoordinates += 20;
			xCoordinates = 100;
		}

		brickVector[i].update();
	}


	//Brick brick(600.0, 600.0);
	//brick.spawn(600, 600);
	//brick.getPosition();

	// Create a Text object called HUD
	Text hud;

	//game sounds
	GameSound gameSound;

	// A cool retro-style font
	Font font;
	font.loadFromFile("font/LLPIXEL3.ttf");

	// Set the font to our retro-style
	hud.setFont(font);

	// Make it nice and big
	hud.setCharacterSize(50);

	// Choose a color
	hud.setFillColor(Color::Blue);

	hud.setPosition(20, 20);

	// Here is our clock for timing everything
	Clock clock;


	// Prepare the hit0 sound
	SoundBuffer hitBuffer0;
	hitBuffer0.loadFromFile("sound/hit0.wav");
	Sound hit0;
	hit0.setBuffer(hitBuffer0);

	// Prepare the hit1 sound
	SoundBuffer hitBuffer1;
	hitBuffer1.loadFromFile("sound/hit1.wav");
	Sound hit1;
	hit1.setBuffer(hitBuffer1);

	// Prepare the hit2 sound
	SoundBuffer hitBuffer2;
	hitBuffer2.loadFromFile("sound/hit2.wav");
	Sound hit2;
	hit2.setBuffer(hitBuffer2);

	// Prepare the hit3 sound
	SoundBuffer hitBuffer3;
	hitBuffer3.loadFromFile("sound/hit3.wav");
	Sound hit3;
	hit3.setBuffer(hitBuffer3);

	// Prepare the hit4 sound
	SoundBuffer hitBuffer4;
	hitBuffer4.loadFromFile("sound/hit4.wav");
	Sound hit4;
	hit4.setBuffer(hitBuffer4);



	while (window.isOpen())
	{
		/*
		Handle the player input
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Quit the game when the window is closed
				window.close();

		}

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle the pressing and releasing of the arrow keys
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			paddle.moveLeft();
		}
		else
		{
			paddle.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			paddle.moveRight();
		}
		else
		{
			paddle.stopRight();
		}

		/*
		Update the paddle, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		// Update the delta time
		Time dt = clock.restart();
		paddle.update(dt);
		ball.update(dt);

		//brick.update();
		// Update the HUD text
		std::stringstream ss;
		ss << "Level: " << level << "     Points: " << score << "    Balls: " << lives;
		hud.setString(ss.str());


		// Paddle Hits the sides
		if (paddle.getPosition().left < 0)
		{
			paddle.hitSideStopLeft();
		}
		
		
		if(paddle.getPosition().left + 10 > window.getSize().x)
		{
			paddle.hitSideStopRight();
		}



		// Handle ball hitting the bottom
		if (ball.getPosition().top > window.getSize().y)
		{
			// reverse the ball direction
			ball.reboundBottom();

			// Remove a life
			lives--;

			// Check for zero lives
			if (lives < 1) 
			{
				//reset level
				level = 1;
				// reset the score
				score = 0;
				// reset the lives
				lives = 5;
			}

		}


		// Handle ball hitting top
		if (ball.getPosition().top < 0)
		{
			ball.reboundPaddleOrTop();

			// Add a point to the players score
			//score++;

			//gameSound.getRandomHitSound();
			hit0.play();


		}

		// Handle ball hitting sides
		if (ball.getPosition().left < 0 ||
			ball.getPosition().left + 10 > window.getSize().x)
		{
			ball.reboundSides();

			//gameSound.getRandomHitSound();
			hit0.play();
		}

		// Has the ball hit the paddle?
		if (ball.getPosition().intersects(paddle.getPosition()))
		{
			// Hit detected so reverse the ball and score a point
			ball.reboundPaddleOrTop();

			//gameSound.getRandomHitSound();
			hit0.play();

		}
		/*
		Draw the paddle, the ball and the HUD
		*********************************************************************
		*********************************************************************
		*********************************************************************
		*/
		window.clear();
		window.draw(hud);
		//window.draw(paddle.getShape());
		window.draw(paddle.getSprite());		
		//window.draw(ball.getShape());

		//TESTING BRICK
		//window.draw(brick.getSprite());
		for (int i = 0; i < brickVector.size(); i++)
		{
			window.draw(brickVector[i].getSprite());
		}

		window.draw(ball.getSprite());
		window.display();
	}

	return 0;
}

