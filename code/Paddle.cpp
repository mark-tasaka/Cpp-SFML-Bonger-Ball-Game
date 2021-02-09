#include "Paddle.h"
#include "stdafx.h"
#include "TextureHolder.h"


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. Joh Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

// This the constructor and it is called when we create an object
Paddle::Paddle(float startX, float startY)
{

	//m_Shape = Sprite(TextureHolder::GetTexture("graphic/paddle.png"));

	m_Position.x = startX;
	m_Position.y = startY;

	//set the origin of sprite in centre
	//for smooth rotation
	//m_Shape.setOrigin(100, 10);

	m_Shape.setSize(sf::Vector2f(200, 20));
	m_Shape.setPosition(m_Position);
	
}

FloatRect Paddle::getPosition()
{
	return m_Shape.getGlobalBounds();
}


RectangleShape Paddle::getShape()
{
	return m_Shape;
}

/*
Sprite Paddle::getPaddle()
{
	return m_Shape;

}*/

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

void Paddle::update(Time dt)
{
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}
