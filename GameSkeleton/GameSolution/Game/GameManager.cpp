#include "GameManager.h"


void GameManager::Draw(Core::Graphics& graphics){
	profiler.newFrame();
	clock.lap();
	fpsClock.lap();

	myShip.update(dt);
	eShip.update(dt);
	orb.update(dt);
	eManager.update(dt);


	//For explosion effect
	if(Core::Input::IsPressed(Core::Input::BUTTON_RIGHT)){
		int mouseX, mouseY;
		Core::Input::GetMousePos( mouseX, mouseY );
		Vector2D mouse((float)mouseX, (float)mouseY);
		eManager.create(1,mouse);
	}

	//memory cleanup
	eManager.clearMem();

	graphics.SetColor(RGB(100,100,100));
	graphics.DrawString(300,10,"SPF:");
	dV.drawValue(graphics,330,10,(fpsClock.lastLapTime()));

	graphics.DrawString(400,10,"FPS:");
	dV.drawValue(graphics,430,10,1/fpsClock.lastLapTime());

	clock.start();
	myShip.drawShip(graphics);
	clock.stop();
	profiler.addEntry("Ship Draw", clock.lastLapTime());

	eShip.drawShip(graphics);

	Matrix3D startTemp = Engine::Translation3D(800,500);
	orb.draw(graphics, startTemp,Vector2D(20,20), 5);

	graphics.SetColor(RGB(10,100,100));
	graphics.DrawString(50,10,"Move ship with WASD or Arrow keys");
	graphics.DrawString(50,23,"For one type of partical effect use right mouse button");

	graphics.SetColor(RGB(100,125,0));
	graphics.DrawLine(790,500, 810, 500);
	graphics.DrawLine(800,490, 800, 510);
	graphics.DrawLine(790,500,800,490);
	graphics.DrawLine(810,500,800,490);
	graphics.DrawLine(790,500,800,510);
	graphics.DrawLine(810,500,800,510);
	graphics.SetColor(RGB(100,25,0));

	eManager.draw(graphics);
}

void GameManager::Update(float dt){
	this ->dt = dt;
	
}

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

GameManager::GameManager(){
	myShip.position = Vector2D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}

void GameManager::init(){
	fpsClock.initialize();
	clock.initialize();
	profiler.initialize("Profiler.csv");
}

void GameManager::shutdown(){
	fpsClock.shutdown();
	clock.shutdown();
	profiler.shutdown();
}