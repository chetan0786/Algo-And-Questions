#include<bits/stdc++.h>
using namespace std;
int  find(int arr[],int l,int r,int x)
{
	while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        if (arr[m] == x) 
            return m; 
  
        if (arr[m] < x) 
            l = m + 1; 
  
        else
            r = m - 1; 
    } 
  
    return -1;
}
int main()
{
	int arr[100];
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
	cout<<find(arr,0,n-1,k);
}
