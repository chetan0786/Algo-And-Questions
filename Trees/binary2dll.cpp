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
void b2dll(Node *root,Node** head,Node** prev)
{
	if(root==NULL)
	return;
	
	b2dll(root->left,head,prev);
	
	if((*prev)==NULL)
	(*head)=root;
	else
	{
		root->left=*prev;
		(*prev)->right=root;
	}
	
	(*prev)=root;
	
	b2dll(root->right,head,prev);
	
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
	Node *head=NULL;
	Node *prev=NULL;
	b2dll(root,&head,&prev);
	while(head!=NULL)
	{
		cout<<head->data;
		head=head->right;
	}

}
