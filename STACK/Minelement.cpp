
#include<bits/stdc++.h>
using namespace std;

int Stack[100],top=-1;
int Min=1000;

bool isEmpty()
{
	if(top==-1)
	return true;
	else
	return false;
}


void push(int item)
{
	if(top==99)
	return;
	else
	Stack[++top]=item;
	if(item<Min)
		Min=item;
}
int getMin()
{
	return Min;
}



int pop()
{
	if(isEmpty())
	return -1;
	else
	return Stack[top--];
}



int main()
{
	
	for(int i=0;i<3;i++)
	{
		int x;
		cin>>x;
		push(x);
		cout<<"    "<<getMin()<<"   ";
		
	}
	
	

	
}

