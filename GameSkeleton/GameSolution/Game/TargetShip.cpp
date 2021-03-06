#include "TargetShip.h"


Vector2D TargetShipPoints[] = {
	Vector2D(0,15),
	Vector2D(15,-15),
	Vector2D(-15,-15)
};


void TargetShip::drawShip(Graphics& graphics, Bullet* bullet)
{
	checkIfAlive(bullet);

	if(isAlive){
		position = position + velocity;
		graphics.SetColor(RGB(0,15,230));
		const unsigned int numLines = sizeof(TargetShipPoints) / sizeof(*TargetShipPoints);
		for(unsigned int x = 0; x < numLines; x++){
			const Vector2D& first = TargetShipPoints[x] + position ;
			const Vector2D& second = TargetShipPoints[(x+1) % numLines] + position;
			graphics.DrawLine(first.x, first.y,
				second.x, second.y);
		}
	}
	graphics.SetColor(RGB(100,175,230));
}
void TargetShip::update(float dt, Vector2D shipPostion){
	dt;
	Vector2D accel = shipPostion - position;
	Vector2D norm = Engine::Normalized(accel);
	velocity = norm * 2 ; 

}

void TargetShip::checkIfAlive(Bullet* bullet){
	for(int i = 0; i < 100; i++){
		if(bullet[i].active){
			Vector2D result = position - bullet[i].postion;
			if(Engine::Length(result) <= 15.0f){
				isAlive = false;
				effectManager.create(1,position);
				position = Vector2D(ran.randomInRange(10,900), ran.randomInRange(10,700));
				bullet[i].active = false;
			}
		}
	}
}