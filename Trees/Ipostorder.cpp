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
void Ipostorder(Node* root)
{

	stack<Node*>s1,s2;
	s1.push(root);
	Node *temp=root;
	while(!s1.empty())
	{
		temp=s1.top();
		s2.push(temp);
		s1.pop();
		
		if(temp->left)
		s1.push(temp->left);
		
		else if(temp->right)
		s1.push(temp->right);
		
	}
	
	while(!s2.empty())
	{
		temp=s2.top();
		cout<<temp->data;
		s2.pop();
	}
	
	
	
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
	Ipostorder(root);
}
