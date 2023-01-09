#include "renderer.h"
#include "core.h"
#include "loger.h"

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

void Renderer::WriteDirectly(const char* text, math::Vec2 pos, int foreground_color, int background_color, int formating){
	
	std::stringstream ss;
	ss << text;
	std::string final_string = ss.str();

	Renderer::SetCursorPos(final_string, pos);

	Renderer::SelectForeground(final_string, foreground_color);
	Renderer::SelectBackground(final_string, background_color);
	Renderer::SelectFormating(final_string, formating);

	std::cout << final_string << NORMAL_TEXT << BACKGROUND_NORMAL;
}

void Renderer::WriteReratively(const char* text, math::Vec2 pos, int foreground_color, int background_color, int formating){
	Renderer::WriteDirectly(text, Renderer::ConvertToScreen(pos), foreground_color, background_color,formating);
}

void Renderer::Clear(){
	Renderer::WriteDirectly(CLEAR_SCREEN);
}

void Renderer::DrawLine( math::Vec2 begining, math::Vec2 end, const char* filling, int foreground_color, int background_color){
	begining = ConvertToScreen(begining);
	end = ConvertToScreen(end);

	end.GetWritten();

	//return;
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

	for(int step = 0; step <= repeats; step++){
		double a =std::abs(begining.y + y - end.y);
		double b =std::abs(begining.x + x - end.x);

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
	
		Renderer::WriteDirectly(filling, {begining.x + x , begining.y + y}, foreground_color, background_color);
	
	}

}
//-------------private-------------------
bool Renderer::LineMoveOnX(double a, double b, int relative_step){
	//ratio of sides in triangle
	double ratio = b/a;
	//that ratio multiplied by the stepth number
	double step_ratio = ratio*relative_step;
	//if its round up, or is same, then it should move on X
	if(step_ratio>= 1) 
		return true;
	else
		return false;
}

bool Renderer::LineMoveOnY(double a, double b, int step){
	//ratio of sides in triangle
	double ratio = a/b;
	//that ratio multiplied by the stepth number
	double step_ratio = ratio*step;
	//if its round up, or is same, then it should move on X
	if(step_ratio >= 1) 
		return true;
	else
		return false;
}
math::Vec2 Renderer::ConvertToScreen(math::Vec2 vec){

if(Core::GetCore()->GetSize().GetX() != -1){

	// with + 1 / 2, i can get the coordinate from interval <-1, 1> to interval <0.0, 1.0>
	float x = (vec.x + 1) / 2;
	float y = (vec.y + 1) / 2; 

	/*
	 * now, the (0,0) coordinate is in left-down, corner and i need it to get to the left-up corner, so
	 * i just subtract it from one
	 */
	
	float y_final = 1.0f - y;

	return {x, y_final};
}
else
	return vec; 
}

//-------TRIANGLES---------------

void Renderer::DrawTriangle(math::Vec2 A, math::Vec2 B, math::Vec2 C){
	DrawLine(A, B);
	DrawLine(A, C);
	DrawLine(B, C);
}


//--------------------------------------------
//--------RENDERER3D--------------------------
//--------------------------------------------

Renderer3D* Renderer3D::s_instance = nullptr;

Renderer3D* Renderer3D::GetRenderer3D(){
	if(s_instance == nullptr)
		s_instance = new Renderer3D();

	return s_instance;
}


void Renderer3D::SelectForeground(std::string& text, int value){
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

void Renderer3D::SelectBackground(std::string& text, int value){
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

void Renderer3D::SelectFormating(std::string& text, int value){
	//TODO: Finish this section
}

void Renderer3D::SetCursorPos(std::string& text, math::Vec2 pos){

	std::stringstream ansi_code("");
	ansi_code <<"\033["<< (int)pos.y << ";" << (int)pos.x << "H";
	//inserting infrot of the text ansi code(\033[y;xH)
	text.insert(0, ansi_code.str());
}

void Renderer3D::WriteDirectly(const char* text, math::Vec3 pos, int foreground_color, int background_color, int formating){
	
	std::stringstream ss;
	ss << text;
	std::string final_string = ss.str();

	Renderer3D::SetCursorPos(final_string, {pos.x, pos.y});

	Renderer3D::SelectForeground(final_string, foreground_color);
	Renderer3D::SelectBackground(final_string, background_color);
	Renderer3D::SelectFormating(final_string, formating);

	std::cout << final_string << NORMAL_TEXT << BACKGROUND_NORMAL;
}

void Renderer3D::WriteReratively(const char* text, math::Vec3 pos, int foreground_color, int background_color, int formating){
	Renderer3D::WriteDirectly(text, Renderer3D::ConvertToScreen(pos), foreground_color, background_color,formating);
}

void Renderer3D::Clear(){
	Renderer3D::WriteDirectly(CLEAR_SCREEN);
}

void Renderer3D::DrawLine( math::Vec3 begining, math::Vec3 end, const char* filling, int foreground_color, int background_color){
	begining = ConvertToScreen(begining);
	end = ConvertToScreen(end);

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

	for(int step = 0; step <= repeats; step++){
		double a =std::abs(begining.y + y - end.y);
		double b =std::abs(begining.x + x - end.x);

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
	
		Renderer3D::WriteDirectly(filling, {begining.x + x , begining.y + y, begining.z}, foreground_color, background_color);
	
	}

}
//-------------private-------------------
bool Renderer3D::LineMoveOnX(double a, double b, int relative_step){
	//ratio of sides in triangle
	double ratio = b/a;
	//that ratio multiplied by the stepth number
	double step_ratio = ratio*relative_step;
	//if its round up, or is same, then it should move on X
	if(step_ratio>= 1) 
		return true;
	else
		return false;
}

bool Renderer3D::LineMoveOnY(double a, double b, int step){
	//ratio of sides in triangle
	double ratio = a/b;
	//that ratio multiplied by the stepth number
	double step_ratio = ratio*step;
	//if its round up, or is same, then it should move on X
	if(step_ratio >= 1) 
		return true;
	else
		return false;
}
math::Vec3 Renderer3D::ConvertToScreen(math::Vec3 vec){

if(Core::GetCore()->GetSize().GetX() != -1){

	// with + 1 / 2, i can get the coordinate from interval <-1, 1> to interval <0.0, 1.0>
	float x = (vec.x + 1) / 2;
	float y = (vec.y + 1) / 2; 

	/*
	 * now, the (0,0) coordinate is in left-down, corner and i need it to get to the left-up corner, so
	 * i just subtract it from one
	 */
	
	float y_final = 1.0f - y;

	return {x, y_final, vec.z};
}
else
	return vec; 
}

//-------TRIANGLES---------------

void Renderer3D::DrawTriangle(math::Vec3 A, math::Vec3 B, math::Vec3 C){
	DrawLine(A, B);
	DrawLine(A, C);
	DrawLine(B, C);
}
