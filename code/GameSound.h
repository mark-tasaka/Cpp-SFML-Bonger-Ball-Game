#pragma once
#include <string>

using namespace std;

/*Bonger Ball is a student/hobby project created by Mark Tasaka
* that builds on Mr. John Horton's 'Pong" game from his book
* Beginning C++ Game Program (second edition), published by Packt>
*/


class GameSound
{
private:
	const string HIT_SOUND[5] = {"hit0.wav", "hit1.wav",  "hit2.wav",  "hit3.wav",  "hit4.wav"};

public:
	int getRandomHitSound();

};