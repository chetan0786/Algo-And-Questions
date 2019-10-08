#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int h)
{
	int pi=arr[h];
	int i=l-1;
	
	for(int j=l;j<h;j++)
	{
		if(arr[j]<pi)
		{
			i++;
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}

void quicksort(int arr[],int l,int r)
{
	if(l<r)
	{
	
	int p=partition(arr,l,r);
	
	quicksort(arr,l,p-1);
	quicksort(arr,p+1,r);
	}
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
	quicksort(arr,0,n-1);
	
		for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
