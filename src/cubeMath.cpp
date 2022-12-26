#include "cubeMath.h"
#include "math.h"

//temorary
#include "renderer.h"

#include <sstream>


namespace math {

//--------------Vec2------------------------------------
	Vec2::Vec2(float x, float y)
		:x(x), y(y){

	}

	//some operator overloading :)
	Vec2 Vec2::operator+(Vec2& add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x += add.x;
		vec.y += add.y;
		return vec;
	}


	Vec2 Vec2::operator+(float& num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x += num;
		vec.y += num;
		return vec;
	}

	Vec2 Vec2::operator-(Vec2& add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x -= add.x;
		vec.y -= add.y;
		return vec;
	}

	Vec2 Vec2::operator-(float& num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x -= num;
		vec.y -= num;
		return vec;
	}

	Vec2 Vec2::operator*(Vec2& add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x *= add.x;
		vec.y *= add.y;
		return vec;
	}

	Vec2 Vec2::operator*(float& num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x *= num;
		vec.y *= num;
		return vec;
	}

	Vec2 Vec2::operator/(Vec2& add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x /= add.x;
		vec.y /= add.y;
		return vec;
	}

	Vec2 Vec2::operator/(float& num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x /= num;
		vec.y /= num;
		return vec;
	}


	const char* Vec2::GetWritten(){
		std::stringstream ss;
		ss << "X: " << Vec2::x << ", Y:" << Vec2::y;
		const char* message = ss.str().c_str();
		Renderer::GetRenderer()->WriteDirectly(message, {0,0});
		return ss.str().c_str();
	}
//-----------------------------------------------------
//----------------VEC3---------------------------------
//-----------------------------------------------------
		
		
	Vec3::Vec3(float x, float y, float z)
		:x(x), y(y), z(z){

	}

	//some operator overloading :)
	Vec3 Vec3::operator+(Vec3& add){
		Vec3 vec(this->x, this->y, this->z);
		vec.x += add.x;
		vec.y += add.y;
		vec.z += add.z;
		return vec;
	}


	Vec3 Vec3::operator+(float& num){
		Vec3 vec(this->x, this->y, this->z);
		vec.x += num;
		vec.y += num;
		vec.z += num;
		return vec;
	}

	Vec3 Vec3::operator-(Vec3& add){
		Vec3 vec(this->x, this->y, this->z);
		vec.x -= add.x;
		vec.y -= add.y;
		vec.z -= add.z;
		return vec;
	}

	Vec3 Vec3::operator-(float& num){
		Vec3 vec(this->x, this->y, this->z);
		vec.x -= num;
		vec.y -= num;
		vec.z -= num;
		return vec;
	}

	Vec3 Vec3::operator*(Vec3& add){
		Vec3 vec(this->x, this->y, this->z);
		vec.x *= add.x;
		vec.y *= add.y;
		vec.z *= add.z;
		return vec;
	}

	Vec3 Vec3::operator*(float& num){
		Vec3 vec(this->x, this->y, this->z);
		vec.x *= num;
		vec.y *= num;
		vec.z *= num;
		return vec;
	}

	Vec3 Vec3::operator/(Vec3& add){
		Vec3 vec(this->x, this->y, this->z);
		vec.x /= add.x;
		vec.y /= add.y;
		vec.z /= add.z;
		return vec;
	}

	Vec3 Vec3::operator/(float& num){
		Vec3 vec(this->x, this->y, this->z);
		vec.x /= num;
		vec.y /= num;
		vec.z /= num;
		return vec;
	}
}