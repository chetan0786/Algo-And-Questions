#include<bits/stdc++.h>
using namespace std;


int Heaparr[100]={0};

void insert(int temp,int i)
{
	if(Heaparr[i]==0)
	Heaparr[i]=temp;
	else{
	  if(Heaparr[i]>temp)
	  insert(temp,2*i+1);	
	  else
	  insert(temp,2*i+2);
	}
}

void buildTree(int t[], int n)
{

    int i=0;
     int root=t[0];
     i++;
     insert(root,0);
    while(i!=n)
    {
    	int temp=t[i];
    	insert(temp,0);
    	i++;
	}

}

void printData(int i)
{
	if(Heaparr[i]==0)
	return;
	else{
		printData(2*i+1);
		cout<<Heaparr[i]<<" ";
		printData(2*i+2);
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
	
	buildTree(arr,n);
	printData(0);
}
