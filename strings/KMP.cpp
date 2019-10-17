#include<bits/stdc++.h>
using namespace std;

void findSubstr(char *str1 , char *str2)
{


	int lps[strlen(str2)];
	
	lps[0] = 0;
	int i=0,j=1;
	while(j<strlen(str2))												
	{
		if(str2[i] == str2[j])
		{
			lps[j] = i+1;
			i++;
			j++;
		}
		else if(i==0)
		{
			lps[j] = 0;
			j++;
		}
		else
		{
			i = lps[i-1];
		}
	}
	
	i = 0;
	j = 0;
	

	while(i<strlen(str1))
	{
		if(str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0)
			{
				i++;
			}		
			else
			{
				j = lps[j-1];
			}	
		}
		
		if(j == strlen(str2))
		{
			cout<<"FOUND AT"<<i-j<<endl;			
		}
	}
						
}

int main()
{
	char str1[100];
	char str2[50];
	
	cin>>str1>>str2;
	
	
 findSubstr(str1,str2);
	
	
}
