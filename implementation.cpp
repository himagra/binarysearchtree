//Binary Search Tree
#include <iostream>
#include <queue>
#include <climits> //INT_MAX , INT_MIN
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* GetNewNode(int data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

node* Insert(node* root1 , int data) 
{
	if(root1 == NULL)
	{
		root1 = GetNewNode(data);
	}
	else if(data <= root1->data)
		root1->left = Insert(root1->left , data);
	else
		root1->right = Insert(root1->right , data);

	return root1;
}

bool IsUtil(node* root , int minValue , int maxValue)
{
	if(root == NULL) 
		return true;

	if(root->data > minValue && root->data <= maxValue && 
		IsUtil(root->left , minValue , root->data) &&
		IsUtil(root->right , root->data , maxValue))
		return true;
	else
		return false;
}
bool IsBinarySearchTree(node* root)
{
	return IsUtil(root , INT_MIN , INT_MAX);
}

bool Search(node*root , int data)
{
	if(root == NULL)
		return false;
	else if(root->data == data)
		return true;
	else if(data <= root->data)
		return(Search(root->left , data));
	else
		return(Search(root->right , data));
}

int FindMin(node* root) // Finding Minimum
{
	if(root == NULL)
		return -1;
	else if(root->left == NULL)
		return root->data;

	return FindMin(root->left);
}

void LevelOrder(node* root) // a.k.a Breadth First
{
	if(root == NULL)
		return; // Exit

	queue<node*> Q;
	Q.push(root);

	while(!Q.empty())
	{
		node* current = Q.front();
		cout << current->data << endl;
		if(current->left != NULL) 
			Q.push(current->left);
		if(current->right != NULL)
			Q.push(current->right);
		Q.pop();
	}
}
int main()
{
	node* root = NULL;
	root = Insert(root , 15);
	root = Insert(root , 10);
	root = Insert(root , 20);
	root = Insert(root , 25);
	root = Insert(root , 8);
	root = Insert(root , 12);
	LevelOrder(root);
	cout << "Minimum is " << FindMin(root) << endl;
	int n;
	cout << "Enter a number to search" ;
	cin >> n;
	if(Search(root , n) == true)
		cout << "YES It exists in the tree" << endl;
	else 
		cout << "NO" << endl;

	if(IsBinarySearchTree(root) == true)
		cout << "And Yes it is a bst" << endl;
	else 
		cout << "And No it is not a bst" << endl;	
}
