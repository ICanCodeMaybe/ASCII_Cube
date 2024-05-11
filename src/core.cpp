#include "core.h"

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <istream>
#include <sstream>

#include "cubeMath.h"
#include "cubeObjects.h"
#include "renderer.h"
#include "textFormating.h"
#include "loger.h"

Core* Core::s_instance = nullptr;
bool Core::app_should_close = false;

float Core::start_time = clock();
float Core::delta_time = 0;
float Core::current_time = 0;
float Core::end_time = 0;

int Core::fps = 30;
int Core::s_width = 0;
int Core::s_height = 0;

Core* Core::GetCore(){
	if(s_instance == nullptr){
		s_instance = new Core();
	}
	return s_instance;
}

math::Vec2 Core::GetSize(){
	return {(float)Core::s_width, (float)Core::s_height};
}
void Core::MainLoop(){
  Renderer::GetRenderer()->WriteDirectly("Whuaa");
	math::Mat4 rotation;
	rotation.SetIdentity();

	rotation.SetRotateMat({0.0f, 1.0f, 0.0f}, 45.0f);
	math::Vec3 start(-0.25f, 0.0f, 0.0f);
	math::Vec3 end(0.25f, 0.0f, 0.0f);

	math::Vec3 A(-0.5f, -0.5f, 0.0f);
	math::Vec3 B(0.5f, -0.5f, 0.0f);
	math::Vec3 C(0.0f, 0.5f, 0.0f);

	Triangle triangle(A, B, C);

	float points [3*4] = { 
    -0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f};

	int indecies[3*2] = { 	
        0, 1, 2,
				1, 2, 3};
  Renderer::GetRenderer()->WriteDirectly("Whuaa");
  PolyObject poly(points, indecies, 6);
  
  Renderer::GetRenderer()->WriteDirectly("Whuaa");
	while(!app_should_close){
		current_time = GetTime();
		delta_time = current_time - end_time;

		if(delta_time > 1.0f/fps){

			Renderer3D::GetRenderer3D()->Clear();
		
			//calculating
			rotation.SetRotateMat({0.0f, 1.0f, 0.0f}, Core::GetTime() * 6);

			//Drawing
			Renderer3D::GetRenderer3D()->DrawTriangle(triangle, &rotation);
			rotation.SetRotateMat({1.0f, 1.0f, 0.0f}, Core::GetTime() * 18);
      Renderer3D::GetRenderer3D()->DrawPoly(poly, &rotation);

			//Logging
			std::stringstream ss;
			ss << "Time: " << Core::GetCore()->GetTime()<<"\n";
			Renderer3D::GetRenderer3D()->WriteDirectly(ss.str().c_str(), {0, 30, 0});
			end_time = GetTime();		
		}
	
	}

}

void Core::SignalHandler(int signal_num){
	Core::app_should_close = true;
	
	Renderer::GetRenderer()->Clear();
	Renderer::GetRenderer()->WriteDirectly("Have a nice day!", {0,0}, NORMAL, NORMAL);
	
	Renderer::GetRenderer()->WriteDirectly("The program has sucessfully terminated ;]\n", {0, 0});
	
	std::exit(signal_num);
}

float Core::GetTime(){
	return (float)(clock() - Core::start_time)/CLOCKS_PER_SEC;
}

void Core::Close(){
	app_should_close = true;
	SignalHandler(1);
}

