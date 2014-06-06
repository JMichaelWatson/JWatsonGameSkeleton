#ifndef _COLORGEN_H_
#define _COLORGEN_H_
#include "Core.h"
#include "Random.h"

inline Core::RGB VeryColor(Core::RGB color, float variance){
	Random ran;	
	float r, g, b;
	r = GetRValue(color);
	r = r + int(ran.randomInRange(-(float)variance, (float)variance+1));
	r = r < 0 ? 0 : r;
	r = r > 255 ? 255 : r;

	g = GetGValue(color);
	g = g + int(ran.randomInRange(-(float)variance, (float)variance+1));
	g = g < 0 ? 0 : g;
	g = g > 255 ? 255 : g;

	b = GetBValue(color);
	b = b + int(ran.randomInRange(-(float)variance, (float)variance+1));
	b = b < 0 ? 0 : b;
	b = b > 255 ? 255 : b;

	return RGB(r,g,b);
}


#endif