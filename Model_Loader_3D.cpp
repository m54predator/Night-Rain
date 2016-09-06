#include "Model_Loader_3D.h"

Model_Loader_3D::Model_Loader_3D()
{
}

Model_Loader_3D::~Model_Loader_3D()
{
}

void Model_Loader_3D::Load_Model(std::string &path, Model_3D &new_model)
{
	std::fstream in;
	std::string line;
	std::stringstream ss;
	char sl;
	char sp[256];
	int i, a, b;
	double x, y, z;
	std::vector<double> vx, vy, vz, vnx, vny, vnz;
	in.open(path, std::ios::in);

	while (!in.eof())
	{
		in >> line;
		if (!line.compare("o")) {
			in >> new_model.name;
			break;
		}
	}
	while (!in.eof())
	{
		in >> line;
		in >> x >> y >> z;
		if (!line.compare("v")) {
			vx.push_back(x);
			vy.push_back(y);
			vz.push_back(z);
		}
		else break;
	}
	vnx.push_back(x);
	vny.push_back(y);
	vnz.push_back(z);
	while (!in.eof())
	{
		in >> line;
		if (!line.compare("vn")) {
			in >> x >> y >> z;
			vnx.push_back(x);
			vny.push_back(y);
			vnz.push_back(z);
		}
		else break;
	}
	while (!in.eof())
	{
		in >> line;
		if (!line.compare("f")) break;
	}
	in.getline(sp, 256);
	ss << sp;
	while (!ss.eof())
	{
		ss >> a >> sl >> sl >> b;
	}
	while (!in.eof())
	{
		in.getline(sp, 256);
		ss << sp;
		while (!ss.eof())
		{
			ss >> a >> sl >> sl >> b;
		}
	}
}