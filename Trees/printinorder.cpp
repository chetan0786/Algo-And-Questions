#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
	
};
void printinorder(Node* root)
{
	if(root==NULL)
	return;
	
	printinorder(root->left);
	cout<<root->data;
	printinorder(root->right);
}
Node* createbst(Node* root,int data)
{
	if(root==NULL)
	{
		Node* temp=new Node(data);
		return temp;
	}
	if(data<root->data)
	root->left=createbst(root->left,data);
	else
	root->right=createbst(root->right,data);
	
	return root;
}

int main()
{
	int n;
	cin>>n;
	int a;
	Node* root=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		root=createbst(root,a);
		
	}
	printinorder(root);
}
