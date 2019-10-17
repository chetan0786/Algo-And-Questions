#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string str[n];
	string temp;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		sort(temp.begin(),temp.end());
		str[i] = temp;
	}
	map <string,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[str[i]]++;
	}
	map<string,int> ::iterator it;
	for( it=mp.begin();it!=mp.end();it++)
	{ 
		cout << "Anagrams of " << it->first << " are " << it->second << endl; 
	} 
}
