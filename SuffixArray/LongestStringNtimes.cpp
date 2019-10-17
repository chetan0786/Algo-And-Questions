#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,n1;
	string str;
	cin >> str;
	n1 = str.length();
	cin >> n;
	map <string,int> mp;
	for(int i=0;i<n1-1;i++)
	{
		for(int j=1;j<=n1-i;j++)
		{
			string temp = str.substr(i,j);
			//cout<<temp<<endl;
			mp[temp]++;
		}
	}
	
	int max = -1;
	string ans="";
	map <string,int> :: iterator it;
	for(it = mp.begin();it!=mp.end();it++)
	{
		//cout<<it->first<<endl;
		if(it->second==n)
		{
			int n2 = it->first.length();
			if(n2 > max)
			{
				ans = it->first;
				max = n2;
			}
		}
	}
	cout<< ans << endl;
}
