#ifndef _PROFILER_H_
#define _PROFILER_H_


class  Profiler
{
private:
	Profiler() {};
	Profiler(const Profiler&);
	Profiler& operator=(const Profiler&);
	static Profiler theInstance;
#if PROFILING_ON
	const char* fileName;
	static const unsigned int MAXFRAMES = 1000;
	static const unsigned int MAXCATEGORIES = 20;
	int frameIndex;
	unsigned int categoryIndex;
	unsigned int numUsedCategories;
	bool status;
	struct ProfileCategory
	{
		const char* name;
		float sample[MAXFRAMES];
	} categories[MAXCATEGORIES];

#endif
public:
	static Profiler& getInstance();
#if PROFILING_ON
	void addEntry(const char* category, float time);
	void newFrame();
	void shutdown();
	void initialize(const char* fileName);
	void checkForDups(const char* category);
	void checkIsGood(bool* status);
#else
	void addEntry(const char* category, float time){}
	void newFrame(){}
	void shutdown(){}
	void initialize(const char* fileName){}
	void checkForDups(const char* category){}
	void checkIsGood(bool* status){}
#endif
};

#define profiler Profiler::getInstance()

#endif