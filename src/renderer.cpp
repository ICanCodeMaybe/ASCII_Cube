#include "renderer.h"
#include "core.h"

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>

#include "textFormating.h"

Renderer* Renderer::s_instance = nullptr;

Renderer* Renderer::GetRenderer(){
	if(s_instance == nullptr)
		s_instance = new Renderer();

	return s_instance;
}


void Renderer::SelectForeground(std::string& text, int value){
	text.append(NORMAL_TEXT);
	switch(value){
		case BLACK: text.insert(0, BLACK_TEXT); break;
		case RED: text.insert(0, RED_TEXT); break;
		case BLUE: text.insert(0, BLUE_TEXT); break;
		case GREEN: text.insert(0, GREEN_TEXT); break;
		case YELLOW: text.insert(0, YELLOW_TEXT); break;
		case MAGENTA: text.insert(0, MAGENTA_TEXT); break;	
		case CYAN: text.insert(0, CYAN_TEXT);break;
		case NORMAL: text.insert(0, NORMAL_TEXT); break;
	}
}

void Renderer::SelectBackground(std::string& text, int value){
	text.append(BACKGROUND_NORMAL);
	switch(value){
		case BLACK: text.insert(0, BACKGROUND_BLACK); break;
		case RED: text.insert(0, BACKGROUND_RED); break;
		case BLUE: text.insert(0, BACKGROUND_BLUE); break;
		case GREEN: text.insert(0, BACKGROUND_GREEN); break;
		case YELLOW: text.insert(0, BACKGROUND_YELLOW); break;
		case MAGENTA: text.insert(0, BACKGROUND_MAGENTA); break;	
		case CYAN: text.insert(0, BACKGROUND_CYAN); break;
		case NORMAL: text.insert(0, BACKGROUND_NORMAL); break;
	}
}

void Renderer::SelectFormating(std::string& text, int value){
	//TODO: Finish this section
}

void Renderer::SetCursorPos(std::string& text, math::Vec2 pos){

	std::stringstream ansi_code("");
	ansi_code <<"\033["<< (int)pos.y << ";" << (int)pos.x << "H";
	//inserting infrot of the text ansi code(\033[y;xH)
	text.insert(0, ansi_code.str());
}

void Renderer::Write(const char* text, math::Vec2 pos, int foreground_color, int background_color, int formating){
	
	std::stringstream ss;
	ss << text;
	std::string final_string = ss.str();

	Renderer::SetCursorPos(final_string, pos);

	Renderer::SelectForeground(final_string, foreground_color);
	Renderer::SelectBackground(final_string, background_color);
	Renderer::SelectFormating(final_string, formating);

	std::cout << final_string << NORMAL_TEXT << BACKGROUND_NORMAL;
}

void Renderer::Clear(){
	Renderer::Write(CLEAR_SCREEN);
}

void Renderer::DrawLine( math::Vec2 begining, math::Vec2 end, const char* filling, int foreground_color, int background_color){
	
	//sides in right angled triangle 
	float a =std::abs(begining.y - end.y);
	float b =std::abs(begining.x - end.x);
		
	bool positive_x = (begining.x < end.x)? true : false;
	bool positive_y = (begining.y < end.y)? true : false;

	int x = 0;
	int y = 0;

	//nuber of repeats in my algorithm
	int repeats =(a > b)? a : b;
	int relative_step_x = 0;
	int relative_step_y = 0;

	for(int step = 1; step <= repeats; step++){
		if(LineMoveOnX(a, b, relative_step_x)){
			(positive_x)? x++ : x--;
			relative_step_x = 0;
		}

		if(LineMoveOnY(a, b, relative_step_y)){
			(positive_y)? y++ : y --;
			relative_step_y = 0;
		}
		
		relative_step_x++;
		relative_step_y++;
	
		Renderer::Write(filling, {begining.x + x , begining.y + y}, foreground_color, background_color);
	
	//	std::stringstream ss;
	//	ss << "Time: " << Core::GetCore()->GetTime() << "\nDelta time : " << Core::GetCore()->delta_time;
	//	Renderer::Write(ss.str().c_str(), {0, 18});
	}

}

bool Renderer::LineMoveOnX(float a, float b, int step){
	//ratio of sides in triangle
	float ratio = b/a;
	//that ratio multiplied by the stepth number
	float step_ratio = ratio*step;
	//if its round up, or is same, then it should move on X
	if(step_ratio>= 1) 
		return true;
	else
		return false;
}

bool Renderer::LineMoveOnY(float a, float b, int step){
	//ratio of sides in triangle
	float ratio = a/b;
	//that ratio multiplied by the stepth number
	float step_ratio = ratio*step;
	//if its round up, or is same, then it should move on X
	if(step_ratio >= 1) 
		return true;
	else
		return false;
}

//-------TRIANGLES---------------


