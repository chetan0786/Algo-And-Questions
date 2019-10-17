#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1;
	string s2;
	cin>>s1>>s2;
	string s3;
	
	s3=s2;
	s3+="$";
	s3+=s1;
	int size2=s2.length();
	int size=s3.length();
	
	int Z[size]={0};
//	cout<<size2<<endl;
	for(int i=1;i<size;i++)
	{
		if(s3[i]==s3[0])
		{
			int j=0;
			int k=i;
			int count=0;
			while(s3[j]==s3[k]&&k<size&&j<size)
			{
				count++;
				j++;
				k++;
			}
			
			Z[i]=count;
			
			if(count==size2)
			cout<<"Index AT"<<i-size2-1<<endl;
			
			
		}
		
	}

}
