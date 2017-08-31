#pragma once
#include <math.h>

class Vector3
{
public:
#pragma region Constructors & Destructor
	Vector3();                                 //Default Constructor.
	Vector3(float X, float Y, float Z);		   //Constructor with float parameters.
	~Vector3();												        
#pragma endregion											        
															        
															        
#pragma region Vector3										        
	const static int Vec3 = 3;		//Vector length.     
	union													        
	{														        
		struct												        
		{													        
			float x;										        
			float y;										        
			float z;										        
		};													        
		struct												        
		{													        
			float Float[Vec3];								        
		};													        
	};														        
#pragma endregion											        
															        
															        
#pragma region Operators								       
	Vector3 operator + (Vector3 RHS);						//Vec + Vec = Vec
	Vector3 operator - (Vector3 RHS);						//Vec - Vec = Vec
	Vector3 operator * (float RHS);							//Vec * Float = Vec
	Vector3 operator / (float RHS);							//Vec / Float = Vec
	Vector3 operator = (Vector3 RHS);						//Vec = Vec
	Vector3 operator += (Vector3 RHS);						//Vec += Vec
	Vector3 operator -= (Vector3 RHS);						//Vec -= Vec
	Vector3 operator *= (float RHS);						//Vec *= Float
	Vector3 operator /= (float RHS);						//Vec /= Float
	bool operator == (Vector3 RHS);							//Does Vec == Vec?
	bool operator != (Vector3 RHS);							//Does Vec != Vec?
	friend Vector3 operator * (float LHS, Vector3 RHS);		//Float * Vec = Vec
	friend Vector3 operator / (float LHS, Vector3 RHS);		//Float / Vec = Vec

	float& operator[] (int Index) { return Float[Index]; }	//Subscript Operator.
	explicit operator float*() { return &x;	};				//Cast Operator.
#pragma endregion											   
															   
															   
#pragma region Functions									   
	float dot(Vector3 & V2);			//Dot Product.
	float magnitude();					//Magnitude.
	Vector3 cross(Vector3 & V2);		//Cross Product.
	void normaliseDirect();			    //Normalise the vector.
	Vector3 normalise();		     	//Normalise a copy of the vector.

	void SetVector(float X, float Y, float Z);
#pragma endregion
};