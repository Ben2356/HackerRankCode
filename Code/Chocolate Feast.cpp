#include <iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for(int z = 0; z < cases; z++)
	{
		int n, c, m;
		cin >> n >> c >> m;
		int totalPieces = 0;
		totalPieces = n / c;
		int wrappers = totalPieces;
		int remainingWrappers = 0;
		while(wrappers >= m)
		{
			int wrapperPieces = wrappers / m;
			remainingWrappers = wrappers % m;
			totalPieces += wrapperPieces;
			wrappers = remainingWrappers+wrapperPieces;
		}
		cout << totalPieces << "\n";
	}

	return 0;
}