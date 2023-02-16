#ifndef CUBE_OBJECTS
#define CUBE_OBJECTS

#include "cubeMath.h"


enum ObjectParameters{
	NORMAL = 0,
	BLACK,
	GREEN,
	BLUE,
	YELLOW,
	MAGENTA,
	CYAN,
	
	FILLED,
	FILLED_BLACK_LINES,
	ONLY_LINES
};

class Object{
public:
	ObjectParameters color;
	ObjectParameters filling;

	Object(ObjectParameters color, ObjectParameters filling); 
	
	ObjectParameters GetColor()	{ return color; }
	ObjectParameters GetFilling() 	{ return filling; }

	void SetColor(ObjectParameters Color)		{ color = Color; }
	void SetFilling(ObjectParameters Filling) 	{ filling = Filling; }


};


class Triangle : Object{
public:
	math::Vec3& A;
	math::Vec3& B;
	math::Vec3& C;

	Triangle(math::Vec3& A, math::Vec3& B, math::Vec3& C, ObjectParameters color = NORMAL, ObjectParameters filling = ONLY_LINES);
};


class PolyObject : Object{
public:
	PolyObject(float* vertecies, int* indecies, int num_of_indecies, ObjectParameters color = NORMAL, ObjectParameters filling = NORMAL);
	Triangle GetTriangleAt(int position);

private:
	float* m_vertecies;
	int* m_indecies;

	int m_num_of_triangles;
};

#endif
