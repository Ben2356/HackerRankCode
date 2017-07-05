#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

//Kadane's Algorithm modified to handle cases of all negative numbers
int sumOfLongestSubarray(int* a, int size, int& maxSum)
{
	int largestNegNum = INT_MIN;
	int currMax = 0;
	int currSum = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] < 0 && a[i] > largestNegNum)
			largestNegNum = a[i];
		if (a[i] > 0)
			maxSum += a[i];
		currSum = currSum + a[i];
		if (currSum < 0)
			currSum = 0;
		if (currSum > currMax)
			currMax = currSum;
	}
	if(!currMax)
        maxSum = largestNegNum;
	return !currMax ? largestNegNum : currMax;
}

int main() 
{
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        int arraySize;
        cin >> arraySize;
        int* array = new int[arraySize];
        for(int i = 0; i < arraySize; i++)
        {
            cin >> array[i];
        }
        int maxSum = 0;
        cout << sumOfLongestSubarray(array, arraySize, maxSum); 
	    cout << " " << maxSum << endl;
        delete[] array;
    }
}
