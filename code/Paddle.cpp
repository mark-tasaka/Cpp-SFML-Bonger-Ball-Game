#include "Paddle.h"
#include "stdafx.h"
//#include "TextureHolder.h"


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

// This the constructor and it is called when we create an object

Paddle::Paddle(float startX, float startY)
{


	m_Position.x = startX;
	m_Position.y = startY;


	m_Texture.loadFromFile("graphic/paddle.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(100, 10);
	
}



FloatRect Paddle::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Paddle::getSprite()
{
	return m_Sprite;
}


Vector2f Paddle::getCenter()
{
	return m_Position;
}



void Paddle::moveLeft()
{
	m_MovingLeft = true;
}

void Paddle::moveRight()
{
	m_MovingRight = true;
}

void Paddle::stopLeft()
{
	m_MovingLeft = false;

}

void Paddle::stopRight()
{
	m_MovingRight = false;
}


void Paddle::hitSideStopLeft()
{
	m_MovingLeft = false;
}

void Paddle::hitSideStopRight()
{
	m_MovingRight = false;
}


void Paddle::update(Time dt)
{
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Sprite.setPosition(m_Position);
}
