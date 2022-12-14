#ifndef LOG
#define LOG

namespace logger{
	void error(const char* message);
	void warninng(const char* message);
	void info(const char* message);
	
	void assert(bool statement, const char* error_message);
}

#endif
