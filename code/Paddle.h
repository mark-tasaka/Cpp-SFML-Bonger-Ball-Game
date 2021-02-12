#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

class Paddle
{
private:
	Vector2f m_Position;

	//NEW
	Sprite m_Sprite;

	//NEW
	Texture m_Texture;

	//NEW
	Vector2f m_Resolution;


	float m_Speed = 1000.0f;


	bool m_MovingRight = false;
	bool m_MovingLeft = false;


public:
	Paddle(float startX, float startY);
	//Paddle();

	FloatRect getPosition();

	//NEW
	Vector2f getCenter();

	//NEW
	Sprite getSprite();


	void moveLeft();

	void moveRight();

	void stopLeft();

	void stopRight();

	void hitSideStopLeft();

	void hitSideStopRight();

	void update(Time dt);

};
