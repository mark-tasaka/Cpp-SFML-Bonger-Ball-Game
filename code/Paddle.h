#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. Joh Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

class Paddle
{
private:
	Vector2f m_Position;

	// A RectangleShape object
	RectangleShape m_Shape;


	//Paddle Sprite
	//Sprite m_Shape;

	float m_Speed = 1000.0f;

	bool m_MovingRight = false;
	bool m_MovingLeft = false;


public:
	Paddle(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	//Sprite getPaddle();

	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();

	void update(Time dt);

};
