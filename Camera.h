#ifndef _CAMERA_H
#define _CAMERA_H

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

	unsigned short angleXZ;
	short angleH;

	bool focus;

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

	void setFocus(bool _focus);
	bool getFocus() const;
	inline float focusmod(float x) const;

	void camDirectUpdate();
};

#endif /* _CAMERA_H */
