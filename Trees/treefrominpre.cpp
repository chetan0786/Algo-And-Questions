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



int index(int in[],int s,int e,int data)
{
    for(int i=s;i<=e;i++)
    {
        if(in[i]==data)
        return i;
    }
    
}
Node* maketree(int in[],int pre[], int s, int e,int *p)
{
    if(s>e)
    return NULL;
    
    Node* temp=new Node(pre[(*p)++]);
    
    if(s==e)
    return temp;
    
    int i=index(in,s,e,temp->data);
    
    temp->left=maketree(in,pre,s,i-1,p);
    temp->right=maketree(in,pre,i+1,e,p);
    
    return temp;
}

void print(Node* root)
{
	if(root==NULL)
	return;
	
	print(root->left);
	cout<<root->data;
	print(root->right);
}

int main()
{
	int n;
	cin>>n;
	
	int in[n];
	int pre[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
		for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	int p=0;
	Node *root=maketree(in,pre,0,n-1,&p);
	print(root);
}
