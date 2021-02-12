#include "Ball.h"
#include "stdafx.h"
//#include "TextureHolder.h"

/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. Joh Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

// This the constructor function
Ball::Ball(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Texture.loadFromFile("graphic/ball.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(8, 8);
		
}


FloatRect Ball::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Ball::getSprite()
{
	return m_Sprite;
}

Vector2f Ball::getCenter()
{
	return m_Position;
}



float Ball::getXVelocity()
{
	return m_DirectionX;
}

void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundPaddleOrTop()
{
	m_DirectionY = -m_DirectionY;

}

void Ball::reboundBottom()
{
	m_Position.y = 50;
	//m_Position.x = 500;
	m_Position.x = 1920 / 2;
	m_DirectionY = -m_DirectionY;
	m_DirectionX = -m_DirectionX;
}

void Ball::update(Time dt)
{
	// Update the ball position variables
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	// Move the ball and the bat
	//m_Shape.setPosition(m_Position);
	m_Sprite.setPosition(m_Position);
}