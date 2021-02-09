#include "GameSound.h"
#include <SFML/Audio.hpp>
#include <random>

using namespace sf;
using namespace std;


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/



void GameSound::getRandomHitSound()
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 4);

	int element = distribution(generator);

	//int sound = HIT_SOUND[element];

	//return sound;

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

	switch(element)
	{
		case 0:
			hit0.play();
			break;

		case 1:
			hit1.play();
			break;

		case 2:
			hit2.play();
			break;

		case 3:
			hit3.play();
			break;

		case 4:
			hit3.play();
			break;

	}

}


