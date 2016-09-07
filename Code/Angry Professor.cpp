#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int testCases;
	cin >> testCases;
	for(int t = 0; t < testCases; t++)
	{
		int totalStudents;
		int cancelThresh;
		cin >> totalStudents >> cancelThresh;
		vector<int> attendance(totalStudents);
		for(int i = 0; i < totalStudents; i++)
		{
			cin >> attendance[i];
		}
		int presentStudents = 0;
		for(int i = 0; i < totalStudents; i++)
		{
			if(attendance[i] <= 0)
				presentStudents++;
		}
		if(presentStudents >= cancelThresh)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}