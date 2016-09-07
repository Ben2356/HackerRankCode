#include <math.h>
#include <iostream>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c++)
    {
        long lowerBound, upperBound;
        cin >> lowerBound; 
        cin >> upperBound;
        int count = 0;
        //look at the sqrt values between the min and max and the int values are perfect square results
        double sqrtLower = sqrt(lowerBound);
        double sqrtUpper = sqrt(upperBound);
        for(double i = ceil(sqrtLower); i <= floor(sqrtUpper); i++)
        {
            if(i == floor(i))
                count++;
        }
        cout << count << endl;
    }
    return 0;
}