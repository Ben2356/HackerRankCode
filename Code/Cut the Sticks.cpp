#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++)
    {
       cin >> arr[arr_i];
    }
    int strawCount = n;
    while(strawCount > 0)
    {
    	cout << strawCount << "\n";
    	int min = arr[0];
    	for(int i = 0; i < arr.size(); i++)
    	{
            if(min == 0)
                min = arr[i];
    		if(arr[i] < min && arr[i] != 0)
    			min = arr[i];
    	}	
    	for(int i = 0; i < arr.size(); i++)
    	{
    		if(arr[i] - min == 0)
                strawCount--;
            if(arr[i] != 0)
                arr[i] -= min;
    	}
    }

    return 0;
}
