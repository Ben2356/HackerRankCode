#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int z = 0; z < t; z++)
    {
        int soln = 0;
        int n;
        int k;
        cin >> n >> k;
        for(int a = 1; a < n; a++)
        {
            for(int b = a+1; b <= n; b++)
            {
                int test = a & b;
                if(test > soln && test < k)
                    soln = test;
            }
        }
        cout << soln << "\n";
    }
    return 0;
}
