#include"solver.h"

using namespace std;

Grid pass(Grid A)
{
	Grid B = A.copy();
	for(int i = 1; i < A.N - 1; i++)
	{
		for(int j = 1; j < A.N - 1; j++)
		{
			B.u[i][j] = 0.25*(A.u[i - 1][j] + A.u[i + 1][j] + A.u[i][j - 1] + A.u[i][j + 1]);
		}
	}
	return B;
}

Grid solve(Grid A, int num_steps)
{
	Grid B = A.copy();
	for(int n = 0; n < num_steps; n++)
	{
		B = pass(B);
	}
	return B;
}
