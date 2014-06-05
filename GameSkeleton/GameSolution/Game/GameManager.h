#pragma once

#include "Engine.h"
#include "Core.h"
#include "DrawValue.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "Orbitz.h"
#include "EffectManager.h"
#include "DrawValue.h"
#include "Profile.h"
#include "Clock.h"
#include "TargetShip.h"
#include "Random.h"
using Core::Input;
using Engine::Vector2D;

class GameManager
{
public:
	GameManager();
	Ship myShip;
	Random ran;
	Clock fpsClock;
	Clock clock;
	float dt;
	EnemyShip eShip;
	TargetShip tShip;
	Orbitz orb;
	EffectManager eManager;
	DrawValue dV;
	void Draw(Core::Graphics& graphics);
	void Update(float dt);
	void init();
	void shutdown();

};