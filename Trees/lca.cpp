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
Node *lca(Node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
  
   
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 
  
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 
  
    return root; 
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
	int n1,n2;
	cin>>n1>>n2;
	Node* temp=lca(root,n1,n2);
	cout<<temp->data;
}
