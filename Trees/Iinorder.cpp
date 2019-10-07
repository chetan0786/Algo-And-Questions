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
void Iinorder(Node* root)
{
	stack<Node *>st;
	
	Node* temp=root;
	
	while(temp!=NULL||!st.empty())
	{
		while(temp!=NULL)
		{
			st.push(temp);
			temp=temp->left;
		}
		cout<<st.top()->data;
		temp=st.top();
		st.pop();
		
		temp=temp->right;
		
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
	Iinorder(root);
}
