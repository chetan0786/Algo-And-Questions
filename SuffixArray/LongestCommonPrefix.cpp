#include<bits/stdc++.h>
using namespace std;
string prefix(string str1,string str2)
{
	int l1=str1.length();
	int l2=str2.length();
	int i=0;
	string ret;
	while(i<l1&&i<l2)
	{
		if(str1[i]!=str2[i])
		break;
		
		ret+=str1[i];
		
		i++;
	}
	return ret;
}
int main()
{
	int n;
	cin>>n;
	string str[n];
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	
	string temp=str[0];
	
	for(int i=1;i<n;i++)
	{
		temp=prefix(temp,str[i]);
	}
	cout<<temp;
}
