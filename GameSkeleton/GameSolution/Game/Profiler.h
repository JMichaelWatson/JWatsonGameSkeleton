#ifndef _PROFILER_H_
#define _PROFILER_H_


#include <vector>

using std::vector;


class  Profiler
{
private:
	Profiler() {}
	Profiler(const Profiler&);
	Profiler& operator-(const Profiler&);
	static Profiler theInstance;
#if PROFILING_ON
	const char* fileName;
	unsigned int frameIndex;
	unsigned int categoryIndex;
	unsigned int numUsedCategories;
	struct ProfileCategory
	{
		const char* name;
		vector<float> sample;
	}; 
	vector<ProfileCategory> categories;
#endif
public:
	static Profiler& getInstance();
#if PROFILING_ON
	void addEntry(const char* category, float time);
	void newFrame();
	void shutdown();
	void initialize(const char* fileName);
#else
	void addEntry(const char* category, float time){}
	void newFrame(){}
	void shutdown(){}
	void initialize(const char* fileName){}
#endif
};

#define profiler Profiler::getInstance()

#endif