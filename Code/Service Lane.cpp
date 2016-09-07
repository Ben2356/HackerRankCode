#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++)
    {
       cin >> width[width_i];
    }
    for(int c = 0; c < t; c++)
    {
        int start;
        int end;
        cin >> start >> end;
        int min = width[start];
        for(int i = start; i <= end; i++)
        {
            if(width[i] < min)
                min = width[i];
        }
        cout << min << endl;
    }
    return 0;
}
