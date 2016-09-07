#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        int n;
        cin >> n;
        int height = 1;
        if(n <= 0)
        {
            cout << height << endl;
        }
        else
        {
            bool firstCycle = true;
            while(n != 0)
            {
                if(firstCycle)
                {
                    height *= 2;
                    firstCycle = false;
                }
                else
                {
                    height++; 
                    firstCycle = true;
                }
                n--;
            }
            cout << height << endl;
        }
    }
    return 0;
}
