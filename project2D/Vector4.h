#pragma once
#include <math.h>

class Vector4
{
public:
#pragma region Constructors & Destructor
	Vector4();                                      //Default Constructor.
	Vector4(float X, float Y, float Z, float W);	//Constructor with float parameters.
	~Vector4();
#pragma endregion


#pragma region Vector4
	const static int Vec4 = 4;       //Vector length.
	union 
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		struct 
		{
			float Float[Vec4];
		};
	};
#pragma endregion


#pragma region Operators                                                
	Vector4 operator + (Vector4 RHS);						//Vec + Vec = Vec 
	Vector4 operator - (Vector4 RHS);						//Vec - Vec = Vec
	Vector4 operator * (float RHS);							//Vec * Float = Vec
	Vector4 operator / (float RHS);							//Vec / Float = Vec
	Vector4 operator = (Vector4 RHS);						//Vec = Vec
	Vector4 operator += (Vector4 RHS);						//Vec += Vec
	Vector4 operator -= (Vector4 RHS);						//Vec -= Vec
	Vector4 operator *= (float RHS);						//Vec *= Float
	Vector4 operator /= (float RHS);						//Vec /= Float
	bool operator == (Vector4 RHS);							//Does Vec == Vec?
	bool operator != (Vector4 RHS);							//Does Vec != Vec?
	friend Vector4 operator * (float LHS, Vector4 RHS);		//Float * Vec = Vec
	friend Vector4 operator / (float LHS, Vector4 RHS);		//Float / Vec = Vec
															   
	float& operator[] (int Index) { return Float[Index]; }	//Subscript Operator.
	explicit operator float*() { return &x; };				//Cast Operator.
#pragma endregion											   
															   
															   
#pragma region Functions									   
	float dot(Vector4 & V2);			//Dot Product.
	float magnitude();					//Magnitude.
	Vector4 cross(Vector4 & V2);		//Cross Product.
	void normaliseDirect();			    //Normalise the vector.
	Vector4 normalise();			    //Normalise a copy of the vector.

	void SetVector(float X, float Y, float Z, float W);
#pragma endregion
};