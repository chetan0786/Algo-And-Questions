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
int diameter(Node* root,Node* base,int *temp)
{
    if(root==NULL)
    return 0;
    
    int l=diameter(root->left,base,temp);
    int r=diameter(root->right,base,temp);
    
    int d=l+r+1;
    if(d>*temp)
    *temp=d;
    
    if(root==base)
    return *temp;
    
    else
    return l>r?l+1:r+1;
    
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
	int temp=0;
	cout<<diameter(root,root,&temp);
}
