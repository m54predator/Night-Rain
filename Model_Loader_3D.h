#ifndef _MODEL_LOADER_3D_H
#define _MODEL_LOADER_3D_H

#include <sstream>
#include <fstream>

#include "Model_3D.h"

class Model_Loader_3D
{
public:
	Model_Loader_3D();
	~Model_Loader_3D();
	void Load_Model(std::string &path, Model_3D &new_model);

private:

};


#endif