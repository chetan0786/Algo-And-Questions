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
void vertical(Node* root,int number,map<int,vector<int> > *mp)
{
    if(root==NULL)
    return;
    
    (*mp)[number].push_back(root->data);
    
    vertical(root->left,number-1,mp);
    vertical(root->right,number+1,mp);
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
	map<int,vector<int> >mp;
	vertical(root,0,&mp);
	 map<int, vector <int> >::iterator i;
	for(i=mp.begin();i!=mp.end();i++)
	{
		vector<int>temp=i->second;
		cout<<temp[0];
		cout<<endl;
	}
}
