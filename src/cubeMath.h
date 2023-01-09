#ifndef CUBE_MATH
#define CUBE_MATH

#define PI 3.14
#include "loger.h"
#include <string>

namespace math{

	class Vec2{
	public:
		float x;
		float y;

		Vec2(float x, float y);
		
		float GetX()const {return x;}
		float GetY()const {return y;}

		void SetX(float& X){ x = X;}
		void SetY(float& Y){ y = Y;}

		Vec2 operator+(Vec2& add);
		Vec2 operator+(float& num);
		Vec2 operator-(Vec2& sub);
		Vec2 operator-(float& num);
		
		Vec2 operator*(Vec2& add);
		Vec2 operator*(float& num);

		Vec2 operator/(Vec2& add);
		Vec2 operator/(float& num);

		const char* GetWritten();
		
	};

	class Vec3{
	public:
		float x;
		float y;
		float z;

		Vec3(float x, float y, float z);
		
		float GetX() const {return x;}
		float GetY() const {return y;}
		float GetZ() const {return z;}

		float Get(int& pos) const;
		void Set(float& value, int& pos);
	
		void SetX(float& X){ x = X;}
		void SetY(float& Y){ y = Y;}
		void SetZ(float& Z){ z = Z;}

		Vec3 operator+(Vec3& add);
		Vec3 operator+(float& num);
		Vec3 operator-(Vec3& sub);
		Vec3 operator-(float& num);
		
		Vec3 operator*(Vec3& add);
		Vec3 operator*(float& num);

		Vec3 operator/(Vec3& add);
		Vec3 operator/(float& num);

	};


class Vec4{
	public:
		float x;
		float y;
		float z;
		float w;

		Vec4(float x, float y, float z, float w);
		
		float GetX() const {return x;}
		float GetY() const {return y;}
		float GetZ() const {return z;}
		float GetW() const {return w;}

		float Get(int& pos) const;
		void Set(float& value, int& pos);
	
		void SetX(const float& X){ x = X;}
		void SetY(const float& Y){ y = Y;}
		void SetZ(const float& Z){ z = Z;}
		void SetW(const float& W){ w = W;}

		Vec4 operator+(Vec4& add);
		Vec4 operator+(float& num);
		Vec4 operator-(Vec4& sub);
		Vec4 operator-(float& num);
		
		Vec4 operator*(Vec4& add);
		Vec4 operator*(float& num);

		Vec4 operator/(Vec4& add);
		Vec4 operator/(float& num);

	};

	class Mat4{
	public:
		float* values = new float[4*4];

	public:
		Mat4();	
		~Mat4();
		float Get(const int& pos) const{return values[pos];};
		void Set(const float& value, const int& position){ 
			if(position < 4*4)
				{values[position] = value;} 
			else{ 
				logger::error("ERROR::MATRIX SET_POSITION INDEX TO HIGH");}};

		void SetIdentity();
		void SetNull();

		std::string GetString();
//------OVERRIDES MATRIX TO ONE OF THESE---
		void SetTranslateMat(const Vec3& translate);
		void SetScaleMat(const Vec3& scale);
		void SetRotateMat(const Vec3& axes, const float& angle);

		Mat4 operator+(const Mat4& add);
		Mat4 operator+(const float& num);

		Mat4 operator-(const Mat4& sub);
		Mat4 operator-(const float& num);
		
		Mat4 operator*(const Mat4& add);
		Vec3 operator*(const Vec3& add);
		Mat4 operator*(const float& num);

	};

}

#endif
