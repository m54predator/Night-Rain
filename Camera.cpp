#include "Camera.h"
#define _USE_MATH_DEFINES TRUE
#include <cmath>
#include <climits>
#include <limits>


Camera::Camera()
{
	angleXZ = SHRT_MAX / 2;
	angleH = 0;

	camX = 0;
	camY = 0;
	camZ = 0;

	camDirectUpdate();
}

void Camera::moveForward(float speed)
{
	camX += viewVecX * speed;
	camY += viewVecY * speed;
	camZ += viewVecZ * speed;
}

void Camera::moveBack(float speed)
{
	camX -= viewVecX * speed;
	camY -= viewVecY * speed;
	camZ -= viewVecZ * speed;
}

void Camera::moveUp(float speed)
{
	camY += speed;
}

void Camera::moveDown(float speed)
{
	camY -= speed;
}

void Camera::moveLeft(float speed)
{
	camX += viewVecZinXZ * speed;
	camZ -= viewVecXinXZ * speed;
}

void Camera::moveRight(float speed)
{
	camX -= viewVecZinXZ * speed;
	camZ += viewVecXinXZ * speed;
}

void Camera::addAngleXZ(short add)
{
	angleXZ += add;
	camDirectUpdate();
}

void Camera::addAngleH(short add)
{
	auto min = std::numeric_limits<short>::min();
	auto max = std::numeric_limits<short>::max();

	add *= 2;

	if (((int) angleH + (int) add) < min) {
		angleH = min;
	}
	else if (((int) angleH + (int) add) > max) {
		angleH = max;
	}
	else {
		angleH += add;
	}

	camDirectUpdate();
}

float Camera::lookAtX() const
{
	return camX + viewVecX;
}

float Camera::lookAtY() const
{
	return camY + viewVecY;
}

float Camera::lookAtZ() const
{
	return camZ + viewVecZ;
}

float Camera::getAngleXZ() const
{
	auto max = std::numeric_limits<unsigned short>::max();
	return (float) (-2 * M_PI * angleXZ / max);
}

float Camera::getAngleH() const
{
	auto max = std::numeric_limits<unsigned short>::max();
	return (float) (M_PI * angleH / max);
}

void Camera::camDirectUpdate()
{
	viewVecX = std::cos(getAngleXZ()) * std::cos(getAngleH());
	viewVecZ = std::sin(getAngleXZ()) * std::cos(getAngleH());
	viewVecY = std::sin(getAngleH());

	viewVecXinXZ = std::cos(getAngleXZ());
	viewVecZinXZ = std::sin(getAngleXZ());

	float a[3];
	float b[3];

	a[0] = -viewVecZinXZ;
	a[1] = 0;
	a[2] = viewVecXinXZ;

	b[0] = viewVecX;
	b[1] = viewVecY;
	b[2] = viewVecZ;

	upDirectX = a[1] * b[2] - a[2] * b[1];
	upDirectY = a[2] * b[0] - a[0] * b[2];
	upDirectZ = a[0] * b[1] - a[1] * b[0];
}
