#include "EffectManager.h"

EffectManager EffectManager::theInstance;

EffectManager& EffectManager::getInstance(){
	return theInstance;
}

void EffectManager::draw(Graphics& graphics){
	for(unsigned int i = 0; i < effects.size(); i++){
		effects[i].draw(graphics);
	}
}

void EffectManager::update(float dt){
	for(unsigned int i = 0; i < effects.size(); i++){
		effects[i].update(dt);
	}
}

void EffectManager::create(int numOfEffect, Vector2D origin){
	ParticalEffect pEffect;
	int count = 0;
	float timeToLive = 0.0f;
	if(numOfEffect == 1){
		count = 200;
		timeToLive = 5.0f;
	}
	if(numOfEffect == 2)
	{
		count = 10;
		timeToLive = .3f;
	}
	pEffect.updateFire(0, count, numOfEffect, origin, timeToLive);
	effects.push_back(pEffect);

}

void EffectManager::clearMem(){
	for(unsigned int i = 0; i < effects.size(); i++){
		if(effects[i].timeTOLive <= 0){
			effects[i].clearMem();
			effects.erase(effects.begin() + i);
		}
	}
}