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
void print(Node* root)
{
	if(root==NULL)
	return;
	
	print(root->left);
	cout<<root->data;
	print(root->right);
}
void findMirror( Node* root)
{
if(root==NULL)
  return;
  
  findMirror(root->left);
  findMirror(root->right);
  
   Node* t=root->left;
  root->left=root->right;
  root->right=t;
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
	findMirror(root);
	print(root);
}
