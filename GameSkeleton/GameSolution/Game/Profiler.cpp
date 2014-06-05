#include "Profiler.h"

Profiler Profiler::theInstance;

Profiler& Profiler::getInstance(){
	return theInstance;
}


#ifdef PROFILING_ON
#include <cassert>
#include <fstream>
using std::ofstream;
using std::ios;
static ofstream outStream;
#endif


void Profiler::initialize(const char* fileName){
	this->fileName = fileName;
	frameIndex = -1;
	categoryIndex = 0;
	numUsedCategories = 0;
	status = true;
}

void Profiler::shutdown(){
	outStream.open(fileName, ios::trunc);

	for(unsigned int i = 0; i < numUsedCategories; i ++){
		outStream << categories[i].name;
		if(i+1 < numUsedCategories){
			outStream << ",";
		} else{
			outStream << '\n';
		}
	}

	unsigned int num_actual_frames = frameIndex;
	if(categoryIndex == numUsedCategories){
		num_actual_frames++;
	}

	for(unsigned int frame = 0; frame < num_actual_frames; frame++){
		for(unsigned int cat =0; cat < numUsedCategories; cat++){
			outStream << categories[cat].sample[frame];
			if(cat+1 < numUsedCategories){
				outStream << ",";
			} else{
				outStream << '\n';
			}
		}
	}
	outStream.close();
}

void Profiler::newFrame(){
	assert(status);
	if(frameIndex > 0){
		assert(categoryIndex == numUsedCategories);
	}
	frameIndex++;
	categoryIndex = 0;
}

void Profiler::addEntry(const char* category, float time){
	if(frameIndex >= MAXFRAMES){
		profiler.shutdown();
		profiler.initialize("Profiler.csv");
	}else {
		assert(categoryIndex < MAXCATEGORIES);
		ProfileCategory& pc = categories[categoryIndex];

		if(frameIndex == 0){
			pc.name = category;
			numUsedCategories++;
			checkForDups(category);	
		} else{
			assert(pc.name == category && category != NULL);
			assert(categoryIndex < numUsedCategories);
		}
		categoryIndex++;
		pc.sample[frameIndex] = time;
	}
}

void Profiler::checkForDups(const char* category){
	for(unsigned int i = 0; i < categoryIndex; i++){
		status &= (categories[i].name != category);
	}
}

void Profiler::checkIsGood(bool* status){
	*status = this->status;
}

