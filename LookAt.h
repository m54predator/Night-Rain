#pragma once
class LookAt
{
public:
	LookAt();
	~LookAt();
	void glhLookAt(float *matrix, float *eyePosition3D, float *center3D, float *upVector3D);
private:
	void MultiplyMatrices4by4OpenGL_FLOAT(float *result, float *matrix1, float *matrix2);
	void glhTranslatef2(float *matrix, float x, float y, float z);
	void ComputeNormalOfPlane(float *normal, const float *pvector1, const float *pvector2);
	void NormalizeVector(float *pvector);

};

