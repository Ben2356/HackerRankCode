#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        int n; 
        bool isPrime = true;
        cin >> n;
        if(n == 1)
            isPrime = false;
        else
        {
            for(int i = 2; i <= sqrt(n); i++)
            {
                if(n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime)
            cout << "Prime\n";
        else
            cout << "Not prime\n";
    }
    return 0;
}