#include "Brick.h"
#include "stdafx.h"


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

// This the constructor and it is called when we create an object

Brick::Brick(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Texture.loadFromFile("graphic/brick.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(50, 10);

}

/*
void Brick::spawn(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Texture.loadFromFile("graphic/brick.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(50, 10);

}*/



FloatRect Brick::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Brick::getSprite()
{
	return m_Sprite;
}


Vector2f Brick::getCenter()
{
	return m_Position;
}

bool Brick::hit()
{
	return true;
}

bool Brick::isBroken()
{
	return m_IsBroken;
}

void Brick::update()
{
	m_Sprite.setPosition(m_Position);
}