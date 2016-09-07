#include <iostream>

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
	int* array = new int[size];
	parseInt(data,array);
	int posCount = 0;
	int negCount = 0;
	int zeroCount = 0;
	for(int i = 0; i < size; i++)
	{
		if(array[i] > 0)
			posCount++;
		else if(array[i] < 0)
			negCount++;
		else
			zeroCount++;
	}
	cout << (double)posCount/size << endl;
	cout << (double)negCount/size << endl;
	cout << (double)zeroCount/size << endl;

	return 0;
}