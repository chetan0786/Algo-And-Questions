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
Node* work(int in[],int post[], int s, int e,int *p)
{
    if(s>e)
    return NULL;
    
    Node* temp=new Node(post[(*p)--]);
    
    
    if(s==e)
    return temp;
    
    int i=index(in,s,e,temp->data);
    temp->right=work(in,post,i+1,e,p);
    temp->left=work(in,post,s,i-1,p);
    
    
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
	int post[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
		for(int i=0;i<n;i++)
	{
		cin>>post[i];
	}
	int p=n-1;
	Node *root=work(in,post,0,n-1,&p);
	print(root);
}
