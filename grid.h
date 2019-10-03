#pragma once
#include"includes.h"

using namespace std;

class Grid
{
	public:
	float x0 = 0.0;
	float y0 = 0.0;
	float L = 1.0;
	float N = 2;
	float dummy = 0.0;
	vector<float> x;
	vector<float> y;
	vector<vector<float>> u;
	Grid();
	Grid(float, float, float, int);
	void discreteBound(vector<float>, vector<float>, vector<float>, vector<float>);
	void contBound(void(*a)(float, Grid&), void(*b)(float, Grid&), void(*c)(float, Grid&), void(*d)(float, Grid&));
	void zero();
	Grid copy();
	void reset();
};
