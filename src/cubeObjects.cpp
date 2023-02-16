#include "cubeObjects.h"
#include "cubeMath.h"
#include "renderer.h"
#include <vector>

Object::Object(ObjectParameters color, ObjectParameters filling)
	:color(color), filling(filling){}

Triangle::Triangle(math::Vec3& A, math::Vec3& B, math::Vec3& C, ObjectParameters color, ObjectParameters filling): A(A),B(B),C(C), Object(color, filling){

}


//------POLYOBJECTS------
PolyObject::PolyObject(float* vertecies, int* indecies, int num_of_indecies,ObjectParameters color, ObjectParameters filling)
:m_vertecies(vertecies), m_indecies(indecies), m_num_of_triangles(num_of_indecies/3),Object(color, filling){
	

}

Triangle GetTriangleAt(int trianglePos){
	//jsem moc unavenej :(
}
