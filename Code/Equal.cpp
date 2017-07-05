#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

long minChocolateOperations(int* colleagues, int count)
{
	//find the min of the colleagues which will be the base
	int base = INT_MAX;
	for (int i = 0; i < count; i++)
	{
		if (colleagues[i] < base)
			base = colleagues[i];
	}
        
	//iterate through each base to find the min number of operations needed
	long minOp = LONG_MAX;
	for (int i = 0; i < 3; i++)
	{
		//find how many times n-5, n-2, and n-1 go into the delta
		long currOp = 0;
		for (int j = 0; j < count; j++)
		{
            int delta = colleagues[j] - base + i;
			currOp += (delta / 5 + delta % 5 / 2 + delta % 5 % 2 / 1);
		}
        
		//check to see if this is the least amount of operations
		minOp = min(currOp, minOp);
	}
	return minOp;
}

int main() 
{
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        int colleagueCount;
        cin >> colleagueCount;
        int* colleagues = new int[colleagueCount];
        for(int i = 0; i < colleagueCount; i++)
        {
            cin >> colleagues[i];
        }
        cout << minChocolateOperations(colleagues,colleagueCount) << endl;
        delete[] colleagues;
    }
    return 0;
}
