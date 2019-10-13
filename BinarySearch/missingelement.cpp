#include<bits/stdc++.h>
using namespace std;
int find(int ar[], int n)
{
	int l = 0, r = n - 1; 
    while (l <= r) { 
  
        int mid = (l + r) / 2; 
  
        if (ar[mid] != mid + 1 && ar[mid - 1] == mid) 
            return mid + 1; 
  
        if (ar[mid] != mid + 1) 
            r = mid - 1; 
        else
            l = mid + 1; 
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

	cout<<find(arr,n);
}
