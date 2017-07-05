#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
	Node(int num, Node* leftNode, Node* rightNode)
	{
		data = num;
		left = leftNode;
		right = rightNode;
	}
	Node* left;
	Node* right;
	int data;
};

void printInOrderTraversal(Node* root)
{
	if(root == NULL)
		return;
	printInOrderTraversal(root->left);
	cout << root->data << " ";
	printInOrderTraversal(root->right);
}

//swap left and right children of parent from a root node
void swapChildren(Node* root)
{
    if(root == NULL)
        return;
	Node* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

//find the nodes at a specified level
void findLevelNodes(vector<Node*> &v, Node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
    {
        v.push_back(root);
       return; 
    }
    findLevelNodes(v,root->left,level-1);
    findLevelNodes(v,root->right,level-1);
}

//root starts at 1
int findMaxHeight(Node* root)
{
    if(root == NULL)
        return 0;
    return 1 + max(findMaxHeight(root->left),findMaxHeight(root->right));
}

int main()
{
	int levelCount;
	cin >> levelCount;

	//create root node, 1
	Node* root = new Node(1,NULL,NULL);

	//construct binary tree whose construction data is presented level order
	queue<Node*> q;
	q.push(root);
	Node* curr;
	for(int i = 0; i < levelCount; i++)
	{
		curr = q.front();
        q.pop();
		int leftNodeVal, rightNodeVal;
		cin >> leftNodeVal >> rightNodeVal;
        if(leftNodeVal != -1)
		{
			curr->left = new Node(leftNodeVal,NULL,NULL);
			q.push(curr->left);
		}
		if(rightNodeVal != -1)
		{
			curr->right = new Node(rightNodeVal,NULL,NULL);
			q.push(curr->right);
		} 
	}
    
    int height = findMaxHeight(root);

	//retrieve swap information
	int swaps; 
	cin >> swaps;
	for(int i = 0; i < swaps; i++)
	{
        int swapLevel;
        vector<int> treeSwapLevels;
        vector<Node*> swapNodes;
		cin >> swapLevel;
        
        //if the level of the tree is divisible by the swapLevel then it must be swapped
        for(int j = 1; j <= height; j++)
        {
            if(j % swapLevel == 0)
            {
                treeSwapLevels.push_back(j);
            }
        }
        
        //find the nodes associated with the targeted swap levels
        for(int j = 0; j < treeSwapLevels.size(); j++)
        {
            findLevelNodes(swapNodes,root,treeSwapLevels[j]);
        }
        
        //swap the children of the swapLevel nodes
        for(int j = 0; j < swapNodes.size(); j++)
        {
            swapChildren(swapNodes[j]);
        }
        
	    //perform in order traversal
	    printInOrderTraversal(root);
        cout << endl;
    }
}