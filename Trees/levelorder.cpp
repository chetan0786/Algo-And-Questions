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
void levelorder(Node *root)
{
	Node* arr[100]={NULL};
    int k=0;
  	int s=0;
  	arr[s++]=root;
  	Node* temp=arr[k];
  	while(temp!=NULL)
    {
      int size=s-k;
     
      while(size!=0&&temp!=NULL)
      {
      cout<<temp->data;
      if(temp->left)
      arr[s++]=temp->left;
      if(temp->right)
      arr[s++]=temp->right;
     temp=arr[++k];
        size--;
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
	levelorder(root);
}
