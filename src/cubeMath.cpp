#include "cubeMath.h"
#include "math.h"


namespace math {

//--------------Vec2------------------------------------
	Vec2::Vec2(float x, float y)
		:x(x), y(y){

	}

	//some operator overloading :)
	Vec2 Vec2::operator+(Vec2 add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x += add.x;
		vec.y += add.y;
		return vec;
	}


	Vec2 Vec2::operator+(float num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x += num;
		vec.y += num;
		return vec;
	}

	Vec2 Vec2::operator-(Vec2 add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x -= add.x;
		vec.y -= add.y;
		return vec;
	}

	Vec2 Vec2::operator-(float num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x -= num;
		vec.y -= num;
		return vec;
	}

	Vec2 Vec2::operator*(Vec2 add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x *= add.x;
		vec.y *= add.y;
		return vec;
	}

	Vec2 Vec2::operator*(float num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x *= num;
		vec.y *= num;
		return vec;
	}

	Vec2 Vec2::operator/(Vec2 add){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x /= add.x;
		vec.y /= add.y;
		return vec;
	}

	Vec2 Vec2::operator/(float num){
		Vec2 vec(Vec2::x, Vec2::y);
		vec.x /= num;
		vec.y /= num;
		return vec;
	}

//----------------Vec3---------------------------------


}
