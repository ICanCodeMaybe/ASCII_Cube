#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

#include "core.h"
#include "renderer.h"
#include "textFormating.h"

Core* Core::s_instance = nullptr;
bool Core::app_should_close = false;

float Core::start_time = clock();
float Core::delta_time = 0;
float Core::current_time = 0;
float Core::end_time = 0;

int Core::fps = 30;

Core* Core::GetCore(){
	if(s_instance == nullptr){
		s_instance = new Core();
	}
	return s_instance;
}


void Core::MainLoop(){

	while(!app_should_close){
		current_time = GetTime();
		delta_time = current_time - end_time;

		if(delta_time > 1.0f/fps){

			Renderer::GetRenderer()->Clear();
			

			Renderer::GetRenderer()->DrawLine({30,20}, {std::sin(GetTime()) * 10 + 30, std::cos(GetTime()) * 10 + 20}, "X");
		
			std::stringstream ss;
			ss << "Time: " << Core::GetCore()->GetTime() << "\n";
			Renderer::GetRenderer()->Write(ss.str().c_str(), {0, 30});
			end_time = GetTime();
		}
	
	}

}

void Core::SignalHandler(int signal_num){
	Core::app_should_close = true;
	
	Renderer::GetRenderer()->Clear();
	Renderer::GetRenderer()->Write("Have a nice day!", {0,0}, NORMAL, NORMAL);
	
	Renderer::GetRenderer()->Write("The program has sucessfully terminated ;]\n", {0, 0});
	
	std::exit(signal_num);
}

float Core::GetTime(){
	return (float)(clock() - Core::start_time)/CLOCKS_PER_SEC;
}

