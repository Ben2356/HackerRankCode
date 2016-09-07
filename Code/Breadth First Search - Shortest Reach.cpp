#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() 
{
	int cases; 
	cin >> cases;
	for(int z = 0; z < cases; z++)
	{
		int n, m, start;
		cin >> n >> m;
		vector<vector<int>> nodes(n);
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;

			//store connected nodes via adjacency vector
			//nodes are represented as index+1
			nodes[x-1].push_back(y-1);
			nodes[y-1].push_back(x-1);
		}
		cin >> start;

		/*for(int i = 0; i < nodes.size(); i++)
		{
			cout << "NODE " << i+1 << ": ";
			for(int j = 0; j < nodes[i].size(); j++)
			{
				cout << nodes[i][j]+1 << " ";
			}
			cout << endl;
		}*/

		//perform BFS traversal through the graph to find the paths
		vector<bool> visitedNodes(n,false);
		vector<int> nodeDistances(n,-1);
		queue<int> q;
		q.push(start-1);
        visitedNodes[start-1] = true;

		//since start node is reference it will not be printed
		nodeDistances[start-1] = 0;
		while(!q.empty())
		{
			int curr = q.front();
            //cout << "CURR NODE: " << curr+1 << endl;
			q.pop();

			//loop through each of the connected nodes and if unvisited add to queue
			for(int i = 0; i < nodes[curr].size(); i++)
			{
				if(!visitedNodes[nodes[curr][i]])
				{
					q.push(nodes[curr][i]);
                    visitedNodes[q.back()] = true;
                    //cout << "NODE " << q.back()+1 << " GOT PUSHED" << endl;
                        
                    if(nodeDistances[q.back()] == -1)
                        nodeDistances[q.back()] = 6 + nodeDistances[curr];
                    else
                        nodeDistances[q.back()] += 6;
				}
			}
		}
		for(int i = 0; i < nodeDistances.size(); i++)
		{
			//cout << "NODE " << i+1 << " has distance: " << nodeDistances[i] << endl;
            if(nodeDistances[i] != 0)
                cout << nodeDistances[i] << " ";
		}
        cout << endl;
	}
    return 0;
}