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
void Ipreorder(Node* root)
{
	stack<Node *>st;
	st.push(root);
	Node *temp=root;
	while(!st.empty())
	{
		temp=st.top();
		cout<<st.top()->data;
		st.pop();
		
		if(temp->right)
		st.push(temp->right);
		
		else if(temp->left)
		st.push(temp->left);
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
	Ipreorder(root);
}
