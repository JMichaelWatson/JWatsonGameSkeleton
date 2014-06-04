#ifndef _PROFILE_H_
#define _PROFILE_H_

#include "Clock.h"
#include "Profiler.h"

class Profile {
	Clock clock;
	const char* category;
public:
	Profile(const char* category);
	~Profile();
};

#define PROFILE(title) Profile a(title)
#endif