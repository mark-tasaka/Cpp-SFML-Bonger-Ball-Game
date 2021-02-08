#include "GameSound.h"
#include <SFML/Audio.hpp>
#include <random>

using namespace sf;
using namespace std;


/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/



int GameSound::getRandomHitSound()
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, 4);

	int element = distribution(generator);

	return element;
}


