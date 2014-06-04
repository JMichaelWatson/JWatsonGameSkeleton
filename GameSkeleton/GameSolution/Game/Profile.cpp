#include "Profile.h"


Profile::Profile(const char* category) : category(category){
	clock.initialize();
	clock.start();
}

Profile::~Profile(){
	clock.stop();
	profiler.addEntry(category, clock.lastLapTime());
}