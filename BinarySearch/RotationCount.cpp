#include<bits/stdc++.h>
using namespace std;
int find(int arr[], int n)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		if (high == low) 
        return low; 

    int mid = low + (high - low)/2; 
  
    if (mid < high && arr[mid+1] < arr[mid]) 
       return (mid+1); 
  
    if (mid > low && arr[mid] < arr[mid - 1]) 
       return mid; 
  
    if (arr[high] > arr[mid]) 
       high=mid-1;
  
    else
    low=mid+1;
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
