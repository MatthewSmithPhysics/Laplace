#include"grid.h"

using namespace std;

Grid::Grid()
{
	this->reset();
}

Grid::Grid(float x0, float y0, float L, int N)
{
	this->x0 = x0;
	this->y0 = y0;
	this->L = L;
	this->N = N;
	this->reset();
}

void Grid::discreteBound(vector<float> top, vector<float> bottom, vector<float> left, vector<float> right)
{
	for(int i = 0; i < this->N - 1; i++) 
	{
		this->u[0][i] = top[i];
		this->u[this->N - 1][this->N - i - 1] = bottom[i];
		this->u[this->N - i - 1][0] = left[i];
		this->u[i][this->N - 1] = right[i];
	}
}

void Grid::contBound(void(*a)(float, Grid&), void(*b)(float, Grid&), void(*c)(float, Grid&), void(*d)(float, Grid&))
{
	for(int i = 0; i < this->N - 1; i++) 
	{
		a(this->x[i], *this);
		this->u[i][this->N - 1] = this->dummy;
		b(this->x[i], *this);
		this->u[i][0] = this->dummy;
		c(this->y[i], *this);
		this->u[0][i] = this->dummy;
		d(this->y[i], *this);
		this->u[this->N - 1][i][this->N - 1] = this->dummy;
	}
}

void Grid::reset()
{
	this->u = {};
	this->x = {};
	this->y = {};
	for(int i = 0; i < this->N; i++)
	{
		vector<float> row = {};
		for(int j = 0; j < this->N; j++) row.push_back(0.0);
		this->u.push_back(row);
		this->x.push_back(this->x0 -0.5*this->L + L*i/(this->N - 1));
		this->y.push_back(this->y0 -0.5*this->L + L*i/(this->N - 1));
	}
}

Grid Grid::copy()
{
	Grid B = Grid(this->x0, this->y0, this->L, this->N);
	B.u = {};
	for(int i = 0; i < B.N; i++)
	{
		vector<float> row = {};
		for(int j = 0; j < B.N; j++)
		{
			row.push_back(this->u[i][j]);
		}
		B.u.push_back(row);
	}
	return B;
}
