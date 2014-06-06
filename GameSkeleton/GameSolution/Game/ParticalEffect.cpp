#include "ParticalEffect.h"


ParticalEffect::ParticalEffect(){
	partsA = new Partical[1000]();
	timeTOLive = 2.0f;
}
void ParticalEffect::draw(Graphics& graphics){
	for (int x = 0; x < count; x ++){
		if(partsA[x].active){
			partsA[x].draw(graphics);
		}
	}

}

void ParticalEffect::updateFire(float dt, const int scount, int type, Vector2D origin, float timeToLive){
	count = scount;
	int r = (int)ran.randomInRange(0,255);
	int g = (int)ran.randomInRange(0,255);
	int b = (int)ran.randomInRange(0,255);
	Core::RGB color;
	for (int x = 0; x < count; x ++){
		if(!partsA[x].active)
		{
			partsA[x] = Partical();
			float randInt = ran.randomInRange(1,10);
			Vector2D rand;
			if(type == 1){
				rand = ran.RandomUnitVector() * randInt;
				 color = RGB(r,g,b);
			} else{
				rand = ran.RandomUnitVectorHalf() * randInt;
				color = RGB(200,10,40);
			}
			Vector2D newPath = origin + rand;
			partsA[x].updateFire(dt, origin, newPath,timeToLive, color);
		}
	}
}

void ParticalEffect::update(float dt){
	for (int x = 0; x < count; x ++){
		partsA[x].update(dt);
	}
		timeTOLive -= dt;
}

void ParticalEffect::clearMem(){
	delete [] partsA;
}