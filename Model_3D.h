#ifndef _MODEL_3D_H
#define _MODEL_3D_H

#include "Polygon_3D.h"

class Model_3D :
	public Scene_Object
{
public:
	Model_3D();
	~Model_3D();
	void Render() override;
	void Change_Color(const RGBA &_color) override;
	void Change_Coordinates(const Coordinates &_coord) override;

	std::vector<Polygon_3D> polygons;
	std::string name;
private:
	
};
#endif