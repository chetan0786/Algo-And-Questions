#include<bits/stdc++.h>
using namespace std;
int  find(int arr[],int l,int r,int x)
{
	if (l<=r) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return find(arr, l, mid - 1, x); 
  
        return find(arr, mid + 1, r, x); 
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
