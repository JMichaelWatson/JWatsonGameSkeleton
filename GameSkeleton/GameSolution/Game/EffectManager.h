#ifndef _EFFECTMANAGER_H_
#define _EFFECTMANAGER_H_

#include "ParticalEffect.h"

class EffectManager
{
private:
	EffectManager() {}
	EffectManager(const EffectManager&);
	EffectManager& operator=(const EffectManager&);
	static EffectManager theInstance;
public:
	static EffectManager& getInstance();
	vector<ParticalEffect> effects;
	void draw(Graphics& graphics);
	void update(float dt);
	void create(int numOfEffect, Vector2D origin);
	void clearMem();
};

#define effectManager EffectManager::getInstance()

#endif