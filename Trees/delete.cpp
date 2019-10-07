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
void print(Node* root)
{
	if(root==NULL)
	return;
	
	print(root->left);
	cout<<root->data;
	print(root->right);
}

Node* minValueNode(Node* node)
{
  Node* current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}


Node* deleteNode(Node* root, int key)
{
  if (root == NULL)
  {
    printf("Node not found\n"); 
    return NULL;
  }

  
  if (key < root->data)
    root->left = deleteNode(root->left, key);

 
  else if (key > root->data)
    root->right = deleteNode(root->right, key);

  else
  {
    Node *temp = NULL;
    
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    else if(root->left == NULL)
    {
      temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      temp = root->left;
      free(root);
      return temp;
    }
 
    temp = minValueNode(root->right); 

    
    root->data = temp->data;

    
    root->right = deleteNode(root->right, temp->data);

  }
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
	cin>>a;
	Node * temp=deleteNode(root,a);
	print(root);
}
