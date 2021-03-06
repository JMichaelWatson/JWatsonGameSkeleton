#ifndef _PARTICAL_H_
#define _PARTICAL_H_

#include "Engine.h"
#include "Core.h"
#include "DrawValue.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "Orbitz.h"
#include "ColorGen.h"

using Core::Input;
using Engine::Vector2D;

class Partical
{
public:
	Partical();
	Core::RGB color;
	bool active;
	float timeToLive;
	Vector2D position;
	Vector2D velocity;
	void update(float dt);
	void draw(Graphics& graphic);
	void updateFire(float dt, Vector2D tstart, Vector2D mouse, float timeToLive, Core::RGB color);
};

#endif