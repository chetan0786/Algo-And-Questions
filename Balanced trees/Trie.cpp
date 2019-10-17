#include<bits/stdc++.h>
using namespace std;

struct Trie
{
	struct Trie* arr[26];
	bool end;
};

struct Trie* makenew()
{
	struct Trie *temp=(struct Trie*)malloc(sizeof(struct Trie));
	temp->end=false;
	
	for(int i=0;i<26;i++)
	{
		temp->arr[i]=NULL;
	}
	
	return temp;
}

void insert(string str,struct Trie* head)
{
	int l=str.length();
	int i=0;
	struct Trie* root=head;
	
	while(i<l)
	{
		if(root->arr[str[i]-'a']==NULL)
		root->arr[str[i]-'a']=makenew();
		
		root=root->arr[str[i]-'a'];
		
		i++;
	}
	
	root->end=true;
}

bool find(string str,struct Trie* head)
{
		int l=str.length();
	int i=0;
	struct Trie* root=head;
	
	while(i<l)
	{
		if(root->arr[str[i]-'a']==NULL)
		return false;
		
		root=root->arr[str[i]-'a'];
		
		i++;
	}
	if(root->end==true)
	return true;
	
	return false;

	
	
}
int main()
{
	int n;
	string str[n];
	
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	
	struct Trie* root=makenew();
	for(int i=0;i<n;i++)
	{
		insert(str[i],root);
	}
	
	cout<<find("hello",root)<<endl;
	cout<<find("world",root)<<endl;
}
