
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
	stack<int>s;
	s.push(l);
	s.push(r);
	while(!s.empty())
	{
		int high=s.top();
		s.pop();
		int low=s.top();
		s.pop();
		
		int p=partition(arr,low,high);
		if (p - 1 > low) { 
           s.push(low);
             s.push(p-1);
        } 
        if (p + 1 < high) { 
              s.push(p+1);
           s.push(high);
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
	quicksort(arr,0,n-1);
	
		for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
