#include"main.h"

void parabola(float x, Grid& A)
{
	float y = -x*(x - 1.0);
	A.dummy = y;
}
void zero(float x, Grid& A)
{
	A.dummy = 0.0;
}

void simple_sin(float x, Grid& A)
[
	A.dummy = sin(x);
}

int main()
{
	Grid A = Grid(0.5, 0.5, 1.0, 40);
	A.contBound(parabola, zero, z
	Grid B = solve(A, 1000);
	writeTXT(B, "output.txt");
}
