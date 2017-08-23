#pragma once
#include "Vector4.h"

class Matrix4
{
public:

#pragma region Constructors & Destructor
	Matrix4();                                             //Default Constructor.
	Matrix4(float x1, float x2, float x3, float x4,
		    float y1, float y2, float y3, float y4,
		    float z1, float z2, float z3, float z4, 				   
		    float w1, float w2, float w3, float w4 );      //Constructor with float parameters.
	~Matrix4();
#pragma endregion


#pragma region Matrix4
	const static int Mat4 = 4;
	union
	{
		struct
		{
			float X1, X2, X3, X4;
			float Y1, Y2, Y3, Y4;
			float Z1, Z2, Z3, Z4;
			float W1, W2, W3, W4;
		};
		struct
		{
			float F[Mat4*Mat4];
		};
		struct
		{
			float X[Mat4];
			float Y[Mat4];
			float Z[Mat4];
			float W[Mat4];
		};
		struct 
		{
			Vector4 Vec[Mat4];
		};
		struct
		{
			float M[Mat4][Mat4];
		};
	};
#pragma endregion


#pragma region Operators
	Matrix4 operator = (Matrix4 RHS);					  //Mat = Mat		 
	Vector4 operator * (Vector4 RHS);					  //Vec * Vec		 
	Matrix4 operator * (Matrix4 RHS);					  //Mat * Mat		 
	Vector4 &operator[] (int Index);                      //Subscript Operator.
	explicit operator float *() { return F; };            //Cast Operator.
#pragma endregion


#pragma region Functions
	void SetFloats(float X1, float X2, float X3, float X4,                 
		           float Y1, float Y2, float Y3, float Y4,				   
		           float Z1, float Z2, float Z3, float Z4,				   
		           float W1, float W2, float W3, float W4);			//Set floats on an existing Matrix.		             
	void SetIdentity();												//Set floats on an existing Matrix to a Identity Matrix.		 	
	void SetTranslation(float W1, float W2, float W3, float W4);	//Set floats on an existing Matrix to a Translation Matrix.
	void SetRotation(float Angle);									//Set floats on an existing Matrix to a Rotation Matrix.
	void SetScale(float X1, float Y2, float Z3);					//Set floats on an existing Matrix to a Scale Matrix.
	void SwitchFloats(int IndexA, int IndexB);						//Switch floats in given index (eg, M[1][2] switches with M[2][1]).
	void Transpose();												//Uses SwitchFloats to Transpose Matrix.
	void setRotateX(float Angle);									//Set the X rotation of the Matrix.
	void setRotateY(float Angle);									//Set the Y rotation of the Matrix.
	void setRotateZ(float Angle);									//Set the Z rotation of the Matrix.
#pragma endregion														   
};													   