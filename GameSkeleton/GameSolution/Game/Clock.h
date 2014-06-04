#ifndef _TIMER_H_
#define _TIMER_H_

#include<Windows.h>

class Clock
{
	LARGE_INTEGER timeFrequency;
	LARGE_INTEGER lastStartTime;
	LARGE_INTEGER deltaLastLap;
	float deltaTime;
public:
	bool initialize();
	bool shutdown();
	void start();
	void stop();
	void lap();
	float lastLapTime() const;
}; 
#endif