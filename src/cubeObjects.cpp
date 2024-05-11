#include "cubeObjects.h"
#include "cubeMath.h"
#include "renderer.h"
#include <vector>

Object::Object(ObjectParameters color, ObjectParameters filling)
	:color(color), filling(filling){}

Triangle::Triangle(math::Vec3 A, math::Vec3 B, math::Vec3 C, ObjectParameters color, ObjectParameters filling): A(A),B(B),C(C), Object(color, filling){

}


//------POLYOBJECTS------
PolyObject::PolyObject(float* vertecies, int* indecies, int num_of_indecies,ObjectParameters color, ObjectParameters filling)
:m_vertecies(vertecies), m_indecies(indecies), m_num_of_triangles(num_of_indecies/3),Object(color, filling){
	m_triangles = new Triangle*[m_num_of_triangles];
  
  for(int i = 0; i < m_num_of_triangles; i++){
    int posX = indecies[i*3];
    int posY = indecies[i*3+1];
    int posZ = indecies[i*3+2];

    math::Vec3 vec_X(vertecies[3*posX], vertecies[3*posX + 1], vertecies[3*posX + 2]);
    math::Vec3 vec_Y(vertecies[3*posY], vertecies[3*posY + 1], vertecies[3*posY + 2]);
    math::Vec3 vec_Z(vertecies[3*posZ], vertecies[3*posZ + 1], vertecies[3*posZ + 2]);
    m_triangles[i] = new Triangle(vec_X, vec_Y, vec_Z, color, filling);
  }
}

PolyObject::~PolyObject(){
  delete[] *m_triangles;
}

Triangle* PolyObject::GetTriangleAt(int trianglePos){
  return m_triangles[trianglePos];
}
