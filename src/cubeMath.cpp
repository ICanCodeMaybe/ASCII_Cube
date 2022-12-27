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

	float Vec3::Get(int& pos) const {
		switch(pos){
			case 0: return this->GetX(); break;
			case 1: return this->GetY(); break;
			case 2: return this->GetZ(); break;
			default: return 0; break;
		}
	}

	void Vec3::Set(float& value, int& pos){
		switch(pos){
			case 0: this->SetX(value); break;
			case 1: this->SetY(value); break;
			case 2: this->SetZ(value); break;
			default: break;
		}
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

//#########################################################
//######----MATRIXES----###################################
//#########################################################

//	values[x + y*4], x - xPosition in Mat, y - yPosition in Mat

//-------Mat4----------------------------------------------

	Mat4::Mat4(){
		this->SetIdentity();
	}
	
	Mat4::~Mat4(){
		delete this;
	}


	//SET section

	void Mat4::SetIdentity(){

		this->SetNull();

		this->Set(1, (0 + 0*4));
		this->Set(1, (1 + 1*4));
		this->Set(1, (2 + 2*4));
		this->Set(1, (3 + 3*4));
	}

	void Mat4::SetNull(){
		for(int i = 0; i < (sizeof(values)/sizeof(float)); i++){
			this->values[i] = 0;
		}
	}

	void Mat4::SetTranslateMat(const Vec3& translate){

		this->SetIdentity();
		
		this->Set(translate.GetX(),(3 + 0*4));
		this->Set(translate.GetY(),(3 + 1*4));
		this->Set(translate.GetZ(),(3 + 2*4));
	}

	void Mat4::SetScaleMat(const Vec3& scale){
		this->SetIdentity();
		
		this->Set(scale.GetX(),	(0 + 0*4));	
		this->Set(scale.GetY(), (1 + 1*4));
		this->Set(scale.GetZ(), (2 + 2*4));
	}

	void Mat4::SetRotateMat(const Vec3& axes, const float& angle_in_rad){
		this->SetIdentity();

		float cosine = cos(angle_in_rad);
		float sine = sin(angle_in_rad);

		//one minus cosine
		float omcos = 1 - cosine;
	
		float x = axes.GetX();
		float y = axes.GetY();
		float z = axes.GetZ();

		this->Set(cosine + x*x+omcos, (0 + 0*4));
		this->Set(x*y*omcos - z*sine, (1 + 0*4));		
		this->Set(x*z*omcos + y*sine, (2 + 0*4));

		this->Set(y*x*omcos + z*sine, (0 + 1*4));
		this->Set(cosine + y+y+omcos, (1 + 1*4));
		this->Set(y*z*omcos - x*sine, (2 + 1*4));

		this->Set(z*x*omcos + y*sine, (0 + 2*4));
		this->Set(z*y*omcos + x*sine, (1 + 2*4));
		this->Set(cosine + z*z*omcos, (2 + 2*4));		

	}

//-------OPERATOR OVERLOADING----------------------

	Mat4 Mat4::operator+(const Mat4& add){
		Mat4 mat;
		mat.values = this->values;

		for(int i = 0; i < 4*4; i++){
			mat.Set(mat.Get(i) + add.Get(i), i);
		}

		return mat;
	}

	Mat4 Mat4::operator+(const float& num){
		Mat4 mat;
		mat.values = this->values;

		for(int i = 0; i < 4*4; i++){
			mat.Set(mat.Get(i) + num, i);
		}

		return mat;
	}

	Mat4 Mat4::operator-(const Mat4& add){
		Mat4 mat;
		mat.values = this->values;

		for(int i = 0; i < 4*4; i++){
			mat.Set(mat.Get(i) - add.Get(i), i);
		}
		return mat;
	}

	Mat4 Mat4::operator-(const float& num){
		Mat4 mat;
		mat.values = this->values;

		for(int i = 0; i < 4*4; i++){
			mat.Set(mat.Get(i) - num, i);
		}

		return mat;
	}


	Mat4 Mat4::operator*(const Mat4& add){
		Mat4 mat;
		mat.values = this->values;
		
		//this for-loop changes the collumn in mat Mat4
		for(int i = 0; i < 4; i++){
			//this for-loop changes the row in add Mat4
			for(int k = 0; k < 4; k++){
				//this for-loop, just calculates the dot product of row and column
				float dot = 0;
				for(int m = 0; m < 4; m++){
					dot += mat.Get(m + i*4) * add.Get(k + m*4);
				}

				mat.Set(dot, (k + i*4));
			}
		}

		return mat;
	}


	//TODO: Create Vec4, and make this compatible with Vec4
	Vec3 Mat4::operator*(const Vec3& add){
		Vec3 vec(0.0f, 0.0f, 0.0f);
		//this for-loop changes the row in add Mat4
		for(int i = 0; i <4 ; i++){
				//this for-loop, just calculates the dot product of row and column
			float dot = 0;
			for(int m = 0; m <4; m++){
				//so Vec3 doesnt overflow
				int x = (m == 3 ) ? 2 : m;
				dot += this->Get(m + i*3) * add.Get(x);
			}

			if(i<3)
				vec.Set(dot, i);
		}

		return vec;
	}
}