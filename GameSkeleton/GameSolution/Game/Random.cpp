#include "Random.h"
#include<random>

float Random::randomFloat() { return (float) rand() / RAND_MAX; }

float Random::randomInRange(float min, float max){
	return randomFloat() * (max - min + 1) + min;
}

Vector2D Random::RandomUnitVector() { 
	float angle = TWO_PI * randomFloat(); 
	return Vector2D( cos(angle), sin(angle) ); 
}

Vector2D Random::RandomUnitVectorHalf() { 
	float angle = (TWO_PI/6.0f) * randomFloat(); 
	return Vector2D( cos(angle), sin(angle) ); 
}
