#pragma once
#include "Vector2D.h"
#include "Engine.h"
#include "Core.h"

using Engine::Vector2D;
using Core::Graphics;

class Bullet
{
public:
	Bullet();
	float TIMETOLIVE;
	bool active;
	Vector2D postion;
	Vector2D velocity;
	void update(float dt);
	void draw(Graphics& graphics);
	void updateFire(float dt, Vector2D start, Vector2D mouse);
};