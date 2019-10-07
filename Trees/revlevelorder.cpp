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
	stack<Node *>s;
	Node* arr[100]={NULL};
    int k=0;
  	int ss=0;
  	arr[ss++]=root;
  	Node* temp=arr[k];
  	while(temp!=NULL)
    {
      int size=ss-k;
     
      while(size!=0&&temp!=NULL)
      {
      s.push(temp);
      if(temp->right)
      arr[ss++]=temp->right;
      if(temp->left)
      arr[ss++]=temp->left;
     temp=arr[++k];
        size--;
      }
     s.push(NULL);
      
      
    }
    while(!s.empty())
    {
    	if(s.top()==NULL)
    	cout<<"\n";
    	else
    	cout<<s.top()->data;
    	s.pop();
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
