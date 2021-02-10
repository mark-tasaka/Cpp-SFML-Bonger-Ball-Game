#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/

class Brick
{
private:
	Vector2f m_Position;

	//Brick Sprite
	Sprite m_Sprite;

	//Brick Texture
	Texture m_Texture;

	//Brick Resolution
	Vector2f m_Resolution;

	bool m_IsBroken = false;


public:
	//Brick C'tor
	//Brick(float startX, float startY);
	Brick();
	void spawn(float startX, float startY);

	FloatRect getPosition();

	Vector2f getCenter();
	
	Sprite getSprite();

	bool hit();

	bool isBroken();

	void update();

};
