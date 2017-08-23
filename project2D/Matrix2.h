#pragma once
#include "Vector2.h"

class Matrix2
{
public:

#pragma region Constructors & Destructor
	Matrix2();                                  //Default Constructor.
	Matrix2(float x1, float x2,					
	     	float y1, float y2);				//Constructor with float parameters.				
	~Matrix2();													
#pragma endregion												
																
																
#pragma region Matrix2											
	const static int Mat2 = 2;									
	union														
	{															
		struct													
		{														
			float X1, X2;										
			float Y1, Y2;										
		};														
		struct													
		{														
			float F[Mat2*Mat2];									
		};														
		struct													
		{														
			float X[Mat2];										
			float Y[Mat2];										
		};														
		struct													
		{														
			Vector2 Vec[Mat2];									
		};														
		struct													
		{														
			float M[Mat2][Mat2];								
		};														
	};															
#pragma endregion												
																
																
#pragma region Operators										
	Matrix2 operator = (Matrix2 RHS);							//Mat = Mat
	Vector2 operator * (Vector2 RHS);							//Vec * Vec
	Matrix2 operator * (Matrix2 RHS);							//Mat * Mat
	Vector2 &operator[] (int Index);                            //Subscript Operator.
	explicit operator float *() { return F; };                  //Cast Operator.
#pragma endregion												
																
																
#pragma region Functions										
	void SetFloats(float X1, float X2, float Y1, float Y2);		//Set floats on an existing Matrix.
	void SetIdentity();											//Set floats on an existing Matrix to a Identity Matrix.
	void SetTranslation(float Y1, float Y2);					//Set floats on an existing Matrix to a Translation Matrix.
	void SetRotation(float Angle);								//Set floats on an existing Matrix to a Rotation Matrix.
	void SetScale(float X1, float Y2);							//Set floats on an existing Matrix to a Scale Matrix.
	void SwitchFloats(int IndexA, int IndexB);					//Switch floats in given index (eg, M[1][2] switches with M[2][1]).
	void Transpose();											//Uses SwitchFloats to Transpose Matrix.
	void setRotate(float Angle);								//Set the rotation of the Matrix.
#pragma endregion												
};

