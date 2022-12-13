#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include "cubeMath.h"
#include "math.h"

#define NORMAL -1
#define BLACK 0
#define RED 1
#define BLUE 2
#define GREEN 3
#define YELLOW 4
#define MAGENTA 5
#define CYAN 7

//https://en.wikipedia.org/wiki/ANSI_escape_code

//TODO: math types 

class Renderer{
private:
	Renderer(){}
	static Renderer* s_instance;

public:
	static Renderer* GetRenderer();
	
	void Clear();
	
	void DrawLine(math::Vec2 begining, math::Vec2 end, const char* filling = "X", int foreground_color = NORMAL, int background_color = NORMAL);
	
//	void DrawLine(math::Vec2 &begining, int *lenght, int &angle, char filling = 'X', int foreground_color = NORMAL, int background_color = NORMAL);

	void Write(const char* text, math::Vec2 pos = {0.0f, 0.0f}, int foreground_color = NORMAL, int background_color = NORMAL, int formating = 10);


private:

	void SetCursorPos(std::string& text, math::Vec2 pos);

	void SelectForeground(std::string& text, int value);
	void SelectBackground(std::string& text, int value);
	void SelectFormating(std::string& text, int value);

	bool LineMoveOnX(float a, float b, int step);
	bool LineMoveOnY(float a, float b, int step);
};


class RendererObject{
private:
	int p_pos_x = 0;
	int p_pos_y = 0;

	int p_foreground_color = 0;
	int p_background_color = 0;
public:

};

class Test : RendererObject{

};

#endif
