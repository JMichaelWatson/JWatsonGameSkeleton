#include "GameManager.h"


void GameManager::Draw(Core::Graphics& graphics){
/////////////////////////////////////////////////////////////////////
//updates
//	profiler.newFrame();
//	clock.lap();
	fpsClock.lap();

//	clock.start();
	myShip.update(dt);
//	clock.stop();
//	profiler.addEntry("Ship Update", clock.lastLapTime());

//	clock.start();
//	eShip.update(dt);
//	clock.stop();
//	profiler.addEntry("Lerper Ship Update", clock.lastLapTime());

//	clock.start();
//	orb.update(dt);
//	clock.stop();
//	profiler.addEntry("Orbit update", clock.lastLapTime());
	
	tShip.update(dt, myShip.position);

	effectManager.update(dt);

////////////////////////////////////////////////////////////////////
//draws
	//For explosion effect
	if(Core::Input::IsPressed(Core::Input::BUTTON_RIGHT)){
		int mouseX, mouseY;
		Core::Input::GetMousePos( mouseX, mouseY );
		Vector2D mouse((float)mouseX, (float)mouseY);
		effectManager.create(1,mouse);
	}

	//memory cleanup
	effectManager.clearMem();

	//FPS debug
	graphics.SetColor(RGB(100,100,100));
//	graphics.DrawString(300,10,"SPF:");
//	dV.drawValue(graphics,330,10,(fpsClock.lastLapTime()));
	graphics.DrawString(950,10,"FPS:");
	dV.drawValue(graphics,950,20,1/fpsClock.lastLapTime());

	//Draw myShip
//	clock.start();
	myShip.drawShip(graphics);
//	clock.stop();
//	profiler.addEntry("Ship Draw", clock.lastLapTime());

	//Draw lerper
//	clock.start();
//	eShip.drawShip(graphics);
//	clock.stop();
//	profiler.addEntry("Lerper Ship Draw", clock.lastLapTime());

	//Orbit draw
//	Matrix3D startTemp = Engine::Translation3D(800,500);
//	clock.start();
//	orb.draw(graphics, startTemp,Vector2D(20,20), 5);
//	clock.stop();
//	profiler.addEntry("Orbit Draw", clock.lastLapTime());

	//Instructions
//	graphics.SetColor(RGB(10,100,100));
//	graphics.DrawString(50,10,"Move ship with WASD or Arrow keys");
//	graphics.DrawString(50,23,"For one type of partical effect use right mouse button");

	//Center point for orbit
//	graphics.SetColor(RGB(100,125,0));
//	graphics.DrawLine(790,500, 810, 500);
//	graphics.DrawLine(800,490, 800, 510);
//	graphics.DrawLine(790,500,800,490);
//	graphics.DrawLine(810,500,800,490);
//	graphics.DrawLine(790,500,800,510);
//	graphics.DrawLine(810,500,800,510);
//	graphics.SetColor(RGB(100,25,0));

	//Enemy Ship draw
	tShip.drawShip(graphics, myShip.turret.bullets);

	//Effect manager draw
	effectManager.draw(graphics);

////////////////////////////////////////////////////////////////////

	if(!tShip.isAlive){
		tShip.isAlive = true;
	}
}

void GameManager::Update(float dt){
	this ->dt = dt;
	
}

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

GameManager::GameManager(){
	myShip.position = Vector2D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	tShip.position = Vector2D(ran.randomInRange(10,900), ran.randomInRange(10,700));
}

void GameManager::init(){
	fpsClock.initialize();
//	clock.initialize();
	tShip.isAlive = true;
//	profiler.initialize("Profiler.csv");
}

void GameManager::shutdown(){
	fpsClock.shutdown();
//	clock.shutdown();
//	profiler.shutdown();
	effectManager.clearMem();
}