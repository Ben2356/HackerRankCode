#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,q;
	cin >> n;
	cin >> q;
	int lastAnswer = 0;
	vector<vector<int>> seqList(n,vector<int>());
	for(int i = 0; i < q; i++)
	{
		int queryNum, x, y;
		cin >> queryNum;
		cin >> x;
		cin >> y;
		if(queryNum == 1)
		{
			seqList[(x^lastAnswer)%n].push_back(y);
		}
		if(queryNum == 2)
		{
			vector<int> seq = seqList[(x^lastAnswer)%n];
			lastAnswer = seq[y%seq.size()];
			cout << lastAnswer << endl;
		}
	}
}