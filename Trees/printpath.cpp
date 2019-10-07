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
void printpath(Node* root,int arr[],int n)
{
	if(root==NULL)
	return;
	
	arr[n++]=root->data;
	if(root->left==NULL&&root->right==NULL)
	{
		for(int i=0;i<n;i++)
		{
			cout<<arr[i];
		}
		cout<<endl;
		
		return;
	}
	printpath(root->left,arr,n);
	printpath(root->right,arr,n);
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
	int arr[100];
	printpath(root,arr,0);
}
