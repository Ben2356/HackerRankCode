#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> names;


    for(int a0 = 0; a0 < N; a0++)
    {
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        size_t found = emailID.find("@gmail.com");
        if(found != string::npos)
        {
        	names.push_back(firstName);
        }
        sort(names.begin(),names.end());
    }
    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << "\n";
    }
    return 0;
}