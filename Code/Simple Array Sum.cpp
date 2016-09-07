#include <iostream>
#include <string>

using namespace std;

void parseInt(string data, int* array)
{
	int index = 0;
	bool isEnd = false;
	while(!isEnd)
	{
		int end = data.find(' ');
		if(end == -1)
			isEnd = true;
		string currVal = data.substr(0,end);
		array[index++] = atoi(currVal.c_str());
		data = data.substr(end+1);
	}
}

int main()
{
	int size; 
	string data; 
	cin >> size;
	cin.ignore();
	getline(cin,data);
	int* soln = new int[size];
	parseInt(data,soln);
	int sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum += soln[i];
	}
	cout << sum;
	delete[] soln;
	return 0;
}