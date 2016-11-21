#ifndef _CAMERA_H
#define _CAMERA_H

#include <cstdint>

class Camera
{
public:
	float camX;
	float camY;
	float camZ;

	float viewVecX;
	float viewVecY;
	float viewVecZ;

	float viewVecXinXZ;
	float viewVecZinXZ;

	float upDirectX;
	float upDirectY;
	float upDirectZ;

	uint16_t angleXZ;
	int16_t angleH;
	bool _lockH;

	Camera();

	void moveForward(float speed);
	void moveBack(float speed);
	void moveLeft(float speed);
	void moveRight(float speed);
	void moveUp(float speed);
	void moveDown(float speed);

	void addAngleXZ(short add);
	void addAngleH(short add);

	float lookAtX() const;
	float lookAtY() const;
	float lookAtZ() const;

	float getAngleXZ() const;
	float getAngleH() const;

	void camDirectUpdate();
	void lockH();
	void unlockH();
};

#endif /* _CAMERA_H */
