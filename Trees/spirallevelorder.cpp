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
void spirallevelorder(Node *root)
{
	stack<Node*>s1,s2;
	s1.push(root);
	Node* temp=root;
	while(!s1.empty()||!s2.empty())
	{
		while(!s1.empty())
		{
			Node *temp=s1.top();
			cout<<temp->data;
			s1.pop();
			if(temp->right)
			s2.push(temp->right);
			if(temp->left)
			s2.push(temp->left);
			
		}
		cout<<"\n";
		while(!s2.empty())
		{
			Node *temp=s2.top();
			cout<<temp->data;
			s2.pop();
			if(temp->right)
			s1.push(temp->right);
			if(temp->left)
			s1.push(temp->left);
			
		}
		cout<<"\n";
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
	spirallevelorder(root);
}
