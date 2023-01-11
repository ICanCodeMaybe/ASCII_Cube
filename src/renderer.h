#ifndef RENDERER_H
#define RENDERER_H

#include "cubeMath.h"
#include "cubeObjects.h"

#include <string>
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
	
	virtual void DrawLine(math::Vec2 begining, math::Vec2 end, const char* filling = "X", int foreground_color = NORMAL, int background_color = NORMAL);
	
//	void DrawLine(math::Vec2 &begining, int *lenght, int &angle, char filling = 'X', int foreground_color = NORMAL, int background_color = NORMAL);

	virtual void WriteDirectly(const char* text, math::Vec2 pos = {0.0f, 0.0f}, int foreground_color = NORMAL, int background_color = NORMAL, int formating = 10);
	virtual void WriteReratively(const char* text, math::Vec2 pos = {0.0f, 0.0f}, int foreground_color = NORMAL, int background_color = NORMAL, int formating = 10);

	virtual void DrawTriangle(math::Vec2 A, math::Vec2 B, math::Vec2 C);

	void SetCursorPos(std::string& text, math::Vec2 pos);

private:

	void SelectForeground(std::string& text, int value);
	void SelectBackground(std::string& text, int value);
	void SelectFormating(std::string& text, int value);

	math::Vec2 ConvertToScreen(math::Vec2 coords);

	virtual bool LineMoveOnX(double a, double b, int step);
	virtual bool LineMoveOnY(double a, double b, int step);
};



class Renderer3D {
private:
	Renderer3D(){}
	static Renderer3D* s_instance;
public:
	static Renderer3D* GetRenderer3D();

	void Clear();
	
	void DrawLine(math::Vec3 begining, math::Vec3 end, const char* filling = "X", int foreground_color = NORMAL, int background_color = NORMAL);
	
// DrawLine(math::Vec2 &begining, int *lenght, int &angle, char filling = 'X', int foreground_color = NORMAL, int background_color = NORMAL);

	void WriteDirectly(const char* text, math::Vec3 pos = {0.0f, 0.0f, 0.0f}, int foreground_color = NORMAL, int background_color = NORMAL, int formating = 10);
	void WriteReratively(const char* text, math::Vec3 pos = {0.0f, 0.0f, 0.0f}, int foreground_color = NORMAL, int background_color = NORMAL, int formating = 10);
	void DrawTriangle(Triangle& triangle, math::Mat4* mat = nullptr);

	void SetCursorPos(std::string& text, math::Vec2 pos);

private:

	void SelectForeground(std::string& text, int value);
	void SelectBackground(std::string& text, int value);
	void SelectFormating(std::string& text, int value);

	math::Vec3 ConvertToScreen(math::Vec3 coords);

	virtual bool LineMoveOnX(double a, double b, int step);
	virtual bool LineMoveOnY(double a, double b, int step);

};

#endif
