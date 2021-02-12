#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

class Ball
{
private:
	Vector2f m_Position;

	//NEW
	Sprite m_Sprite;

	//NEW
	Texture m_Texture;

	//NEW
	Vector2f m_Resolution;

	//RectangleShape m_Shape;

	float m_Speed = 1500.0f;
	float m_DirectionX = 0.2f;
	float m_DirectionY = 0.2f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	//RectangleShape getShape();


	//NEW
	Vector2f getCenter();

	//NEW
	Sprite getSprite();


	float getXVelocity();

	void reboundSides();

	void reboundPaddleOrTop();

	void reboundBottom();

	void update(Time dt);

};
