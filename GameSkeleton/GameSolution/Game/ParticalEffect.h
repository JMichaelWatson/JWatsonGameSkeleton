#ifndef _PARTICALEFFECT_H_
#define _PARTICALEFFECT_H_

#include "Partical.h"
#include "Random.h"
#include <vector>

using std::vector;

class ParticalEffect
{
public:
	ParticalEffect();
	Partical *partsA;
	float timeTOLive;
	Random ran;
	int count;
	void draw(Graphics& graphics);
	void update(float dt);
	void updateFire(float dt, const int count, int type, Vector2D origin, float timeToLive);
	void clearMem();
};

#endif