#include <iostream>

using namespace std;

int main()
{
	int chapters, probsPerPage,problems;
	int unique = 0;
	int currPage = 1;
	cin >> chapters >> probsPerPage;
	for(int z = 0; z < chapters; z++)
	{
		cin >> problems;
        int currProblem = 1;
		for(; currProblem <= problems; currPage++)
		{
			//loops through all the problems that can fit on a page
			for(int remProbs = (currProblem % probsPerPage == 0) ? 1 : (currProblem % probsPerPage); remProbs <= probsPerPage  && currProblem <= problems; currProblem++,remProbs++)
			{
				if(currProblem == currPage)
					unique++;
			}
		}
	}
    cout << unique << endl;
	return 0;
}