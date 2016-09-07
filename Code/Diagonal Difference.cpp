#include <iostream>
#include <cmath>

using namespace std;

void parseInt(string data, int row, int** array)
{
	int index = 0;
	bool isEnd = false;
	while(!isEnd)
	{
		int end = data.find(' ');
		if(end == -1)
			isEnd = true;
		string currVal = data.substr(0,end);
		array[row][index++] = atoi(currVal.c_str());
		data = data.substr(end+1);
	}
}

int main()
{
	int size; 
	cin >> size; 
	cin.ignore();
	int** matrix = new int*[size];
	for(int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		string data; 
		getline(cin,data);
		parseInt(data,i,matrix);
	}
	int primaryDiagonalIndex = 0;
	int secondaryDiagonalIndex = size-1;
	int primaryDiagSum = 0;
	int secondaryDiagSum = 0;
	for(int i = 0; i < size; i++)
	{
		primaryDiagSum += matrix[i][primaryDiagonalIndex++];
		secondaryDiagSum += matrix[i][secondaryDiagonalIndex--];
	}

	cout << abs(primaryDiagSum-secondaryDiagSum) << endl;

	return 0;
}