#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> array(6,vector<int>(6));
    for(int j = 0; j < 6; j++)
    {
        for(int i = 0; i < 6; i++)
        {
            cin >> array[i][j];
        }
    }

    int maxSum = -999;
    int sum = 0;
    
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 4; i++){
            for(int y = 0; y < 3; y++){
                for(int x = 0; x < 3; x++){
                    if(y != 1) {
                        //cout << array[i+x][j+y] << " ";
                        sum += array[i+x][j+y];
                    }
                    else {
                        //cout << "  " << array[i+1][j+y];
                        sum += array[i+1][j+y];
                        break;
                    }
                }
                //cout << endl;
            }
            //cout << "\nSUM: " << sum << "\n" << endl;
            if(sum > maxSum)
                maxSum = sum;
            sum = 0;
        }
    }
    
    cout << maxSum << endl;
    return 0;