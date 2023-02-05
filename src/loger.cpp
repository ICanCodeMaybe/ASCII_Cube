#include "loger.h"

#include "textFormating.h"
#include "core.h"

#include <sstream>
#include <iostream>

namespace logger{
	void error(const char* message){
		std::cout << CLEAR_SCREEN << RED_TEXT << message << "\n";
	}
	void warninng(const char* message){
		std::cout << CLEAR_SCREEN << YELLOW_TEXT << message << "\n";
	}
	void info(const char* message){
		std::cout << NORMAL_TEXT << message << "\n";
	}
	void assert(bool statement, const char* message){
		if(statement){
			std::cout << CLEAR_SCREEN << RED_TEXT << message << "\n";
			Core::GetCore()->Close();
		}
	}
}
