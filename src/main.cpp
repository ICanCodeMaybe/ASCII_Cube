#include <iostream>
#include <csignal>

#include "core.h"
#include "textFormating.h"


int main(int argc, char* argv[]){
	//on SIGIL (interupt signal) gets called on Ctrl + C
	std::signal(SIGINT, Core::GetCore()->SignalHandler);
	if(argv[2])
		Core::GetCore()->SetWidthHeight(std::stoi(argv[1]), std::stoi(argv[2]));
	else
		Core::GetCore()->SetWidthHeight(-1,-1);
	Core::GetCore()->MainLoop();
	return 0;
}
