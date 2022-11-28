#include <iostream>
#include <csignal>

#include "core.h"
#include "textFormating.h"


int main(){
	//on SIGIL (interupt signal) gets called on Ctrl + C
	std::signal(SIGINT, Core::GetCore()->SignalHandler);

	Core::GetCore()->MainLoop();
	return 0;
}
