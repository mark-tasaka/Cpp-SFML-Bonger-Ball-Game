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
	//const string HIT_SOUND[5] = {"hit0", "hit1",  "hit2",  "hit3",  "hit4"};

	const int HIT_SOUND[5] = {0, 1, 2, 3, 4};

public:
	void getRandomHitSound();

};