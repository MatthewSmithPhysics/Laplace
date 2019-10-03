#include"report.h"

void writeTXT(Grid A, string filename)
{
	ofstream output;
	output.open(filename);
	for(int i = 0; i < A.N; i++)
	{
		for(int j = 0; j < A.N; j++)
		{
			output << A.x[i] << ", " << A.y[j] << ", " << A.u[i][j] << endl;
		}
	}
	output.close();
}
