#pragma once
#include <math.h>

class Vector2
{
public:
#pragma region Constructors & Destructor
	Vector2();                              //Default Constructor.
	Vector2(float X, float Y);              //Constructor with float parameters.
	~Vector2();												   
#pragma endregion											   
															   
															   
#pragma region Vector2										   
	const static int Vec2 = 2;				//Vector length.
	union													   
	{														   
		struct												   
		{													   
			float x;										   
			float y;										   
		};													   
		struct												   
		{													   
			float Float[Vec2];								   
		};													   
	};														   
#pragma endregion											   
															   
															   
#pragma region Operators									   
	Vector2 operator + (Vector2 RHS);									//Vec + Vec = Vec
	Vector2 operator - (Vector2 RHS);									//Vec - Vec = Vec
	Vector2 operator * (float RHS);										//Vec * Float = Vec
	Vector2 operator / (float RHS);										//Vec / Float = Vec
	Vector2 operator = (Vector2 RHS);									//Vec = Vec
	Vector2 operator += (Vector2 RHS);									//Vec += Vec
	Vector2 operator -= (Vector2 RHS);									//Vec -= Vec
	Vector2 operator *= (float RHS);									//Vec *= Float
	Vector2 operator /= (float RHS);									//Vec /= Float
	bool operator == (Vector2 RHS);										//Does Vec == Vec?
	bool operator != (Vector2 RHS);										//Does Vec != Vec?
	friend Vector2 operator * (const float LHS, const Vector2 RHS);		//Float * Vec = Vec
	friend Vector2 operator / (const float LHS, const Vector2 RHS);		//Float / Vec = Vec

	float& operator[] (int Index) {	return Float[Index]; }	//Subscript Operator.
	explicit operator float*() { return &x; };				//Cast Operator.
#pragma endregion


#pragma region Functions
	float dot(Vector2 & V2);  //Dot Product.
	float magnitude();        //Magnitude.
	void normaliseDirect();   //Normalise the vector.
	Vector2 normalise();      //Normalise a copy of the vector.

	void SetVector(float X, float Y);
#pragma endregion
};