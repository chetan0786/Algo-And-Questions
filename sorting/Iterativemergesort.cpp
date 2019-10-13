#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	
	int left[n1];
	int right[n2];
	
	for(int i=0;i<n1;i++)
	{
		left[i]=arr[i+l];
	}
	for(int i=0;i<n2;i++)
	{
		right[i]=arr[i+m+1];
	}
	
	int i=0,j=0,k=l;
	while (i < n1 && j < n2) 
    { 
        if (left[i] <= right[j]) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = left[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = right[j]; 
        j++; 
        k++; 
    } 
}


void mergesort(int arr[], int n) 
{ 
   int c;  
   int l; 
   for (c=1; c<=n-1; c = 2*c) 
   { 
       
       for (l=0; l<n-1; l += 2*c) 
       { 
          
           int mid = min(l + c - 1, n-1); 
  
           int r = min(l + 2*c - 1, n-1); 
   
           merge(arr, l, mid, r); 
       } 
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
	
	mergesort(arr,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
