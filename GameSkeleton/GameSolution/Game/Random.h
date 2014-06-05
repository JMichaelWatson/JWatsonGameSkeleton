#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "Engine.h"
#include "Vector2D.h"
#include "Vector3D.h"

using Engine::Vector2D;
using Engine::Vector3D;

 const float TWO_PI =  2*3.1415926f;
class Random
{

public:
	float randomFloat();
	float randomInRange(float min, float max);
	Vector2D RandomUnitVector();
	Vector2D RandomUnitVectorHalf();
};

#endif

