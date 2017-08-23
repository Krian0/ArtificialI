#pragma once
#include "Vector3.h"

class Matrix3
{
public:

#pragma region Constructors & Destructor                                  
	Matrix3();                                  //Default Constructor.
	Matrix3(float x1, float x2, float x3,		
		    float y1, float y2, float y3,
		    float z1, float z2, float z3);      //Constructor with float parameters.
	~Matrix3();
#pragma endregion


#pragma region Matrix3
	const static int Mat3 = 3;
	union
	{
		struct
		{
			float X1, X2, X3;
			float Y1, Y2, Y3;
			float Z1, Z2, Z3;
		};
		struct
		{
			float F[Mat3*Mat3];
		};
		struct
		{
			float X[Mat3];
			float Y[Mat3];
			float Z[Mat3];
		};
		struct
		{
			Vector3 Vec[Mat3];
		};
		struct
		{
			float M[Mat3][Mat3];
		};
	};
#pragma endregion


#pragma region Operators												 
	Matrix3 operator = (Matrix3 RHS);							//Mat = Mat		 
	Vector3 operator * (Vector3 RHS);							//Vec * Vec		 
	Matrix3 operator * (Matrix3 RHS);							//Mat * Mat		 
	Vector3 &operator[] (int Index);							//Subscript Operator.
	explicit operator float *() { return F; };					//Cast Operator.
#pragma endregion
	                                                                     
	                                                                     
#pragma region Functions												 
	void SetFloats(float X1, float X2, float X3,    					 
		           float Y1, float Y2, float Y3,    					             
		           float Z1, float Z2, float Z3);			    //Set floats on an existing Matrix.		             
	void SetIdentity();											//Set floats on an existing Matrix to a Identity Matrix.		 	 
	void SetTranslation(float Z1, float Z2, float Z3);			//Set floats on an existing Matrix to a Translation Matrix.
	void SetRotation(float Angle);								//Set floats on an existing Matrix to a Rotation Matrix.
	void SetScale(float X1, float Y2, float Z3);				//Set floats on an existing Matrix to a Scale Matrix.
	void SwitchFloats(int IndexA, int IndexB);					//Switch floats in given index (eg, M[1][2] switches with M[2][1]).
	void Transpose();											//Uses SwitchFloats to Transpose Matrix.
	void setRotateX(float Angle);								//Set the X rotation of the Matrix.
	void setRotateY(float Angle);								//Set the Y rotation of the Matrix.
	void setRotateZ(float Angle);                               //Set the Z rotation of the Matrix.
#pragma endregion
};

