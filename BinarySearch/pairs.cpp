#include<bits/stdc++.h>
using namespace std;
void getPairs(int arr[], int n, int sum)
{
  
   
  for(int i=0;i<n;i++)
  {
    int s=sum-arr[i];
    int l=i;
    int r=n;
    while(l<=r)
    {
      int mid=l+(r-l)/2;
      if(arr[mid]==s)
      {
        cout<<arr[i]<<" "<<arr[mid]<<endl;
         l=mid+1;
      }
      else if(arr[mid]<s)
      {
        l=mid+1;
      }
      else
      {
        r=mid-1;
      }
    }
  }
  
}
int main()
{
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int sum=0;
	cin>>sum;
	getPairs(arr,n,sum);
}
