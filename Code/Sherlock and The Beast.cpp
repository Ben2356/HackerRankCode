#include <iostream>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        int n;
        cin >> n;
        if(n == 0 || n == 1 || n == 2 || n == 4 || n == 7)
        {
            cout << -1 << endl;
            continue;
        }
        int r = n % 3;
        string soln;
        if(r == 0)
        {
            for(int i = 0; i < n/3; i++)
            {
                soln += "555";
            }
        }
        else if(r == 1)
        {
           while(n - 10 != 0)
           {
               n -= 3;
               soln += "555";
           }
           soln += "3333333333";
        }
        else
        {
            while(n - 5 != 0)
            {
                n -= 3;
                soln += "555";
            }
            soln += "33333";
        }
        cout << soln << endl;
    }
    return 0;
}
