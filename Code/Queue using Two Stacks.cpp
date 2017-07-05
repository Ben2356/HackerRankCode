#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s1;
	stack<int> s2;
	int queries;
	cin >> queries;
	for(int q = 0; q < queries; q++)
	{
		int type;
		cin >> type;

		//push command
		if(type == 1)
		{
			int val;
			cin >> val;

			//stack 2 is the receiving stack, all new entries go there first and then are sorted
			//onto stack 1
			s2.push(val);
		}
		//pop command
		else if(type == 2)
		{
			//perform the pop operation since stack 1 will always have an entry after the 
			//previous query finishes
			s1.pop();
		}
		//front command
		else if(type == 3)
		{
			cout << s1.top() << endl;
		}

		//update stack 1 with ordered entries if it is empty at the end of the queries
		if(s1.empty())
		{
			while(!s2.empty())
			{
				int tmp = s2.top();
				s2.pop();
				s1.push(tmp);
			}
		}
	}
	return 0;
}