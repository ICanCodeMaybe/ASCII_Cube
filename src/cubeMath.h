#ifndef CUBE_MATH
#define CUBE_MATH

namespace math{

	class Vec2{
	public:
		float x;
		float y;

		Vec2(float x, float y);
		
		float GetX(){return x;}
		float GetY(){return y;}

		void SetX(float X){ x = X;}
		void SetY(float Y){ y = Y;}

		Vec2 operator+(Vec2 add);
		Vec2 operator+(float num);
		Vec2 operator-(Vec2 sub);
		Vec2 operator-(float num);
		
		Vec2 operator*(Vec2 add);
		Vec2 operator*(float num);

		Vec2 operator/(Vec2 add);
		Vec2 operator/(float num);
		
	};

	class Vec3{
	public:
		float x;
		float y;
		float z;

		Vec3(float x, float y, float z);
		
		float GetX(){return x;}
		float GetY(){return y;}
		float GetZ(){return z;}
	
		void SetX(float X){ x = X;}
		void SetY(float Y){ y = Y;}
		void SetZ(float Z){ z = Z;}
	};

}

#endif