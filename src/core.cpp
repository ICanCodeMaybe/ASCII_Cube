#include <cstdlib>
#include <iostream>

#include "core.h"
#include "renderer.h"
#include "textFormating.h"

Core* Core::s_instance = nullptr;
bool Core::app_should_close = false;

Core* Core::GetCore(){
	if(s_instance == nullptr){
		s_instance = new Core();
	}
	return s_instance;
}


void Core::MainLoop(){
	while(!app_should_close){
		

		Renderer::GetRenderer()->Write("Hello There!",{10,20}, RED, RED);
		Renderer::GetRenderer()->Write("X",{15,5});
		
		
		Renderer::GetRenderer()->DrawLine({0,0}, {15, 5}, 'X', RED, RED);
		Renderer::GetRenderer()->Clear();
	}
}

void Core::SignalHandler(int signal_num){
	Core::app_should_close = true;
	
	Renderer::GetRenderer()->Clear();
	Renderer::GetRenderer()->Write("Have a nice day!", {0,0}, NORMAL, NORMAL);
	
	Renderer::GetRenderer()->Write("The program has sucessfully terminated ;]\n", {0, 0});
	
	std::exit(signal_num);
}

