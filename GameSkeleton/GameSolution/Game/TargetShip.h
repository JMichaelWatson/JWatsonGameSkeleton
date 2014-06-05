#ifndef _TARGETSHIP_H_
#define _TARGETSHIP_H_
#include"Core.h"
#include"Engine.h"
#include"Vector2D.h"
#include "Bullet.h"

using Engine::Vector2D;
using Core::Graphics;


class TargetShip
{
private:
	Vector2D velocity;
public:
	bool isAlive;
	Vector2D position;
	void drawShip(Graphics& graphics, Bullet* bullet);
	void update(float dt, Vector2D shipPosition);
	void checkIfAlive(Bullet* bullet);
};

#endif