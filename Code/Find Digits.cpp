#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        int n,curr;
        cin >> n;
        curr = n;
        vector<int> digits; 
        int count = 0;
        while(curr != 0)
        {
            digits.push_back(curr%10);
            curr /= 10;
        }
        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] == 0)
                continue;
            if(n % digits[i] == 0)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
