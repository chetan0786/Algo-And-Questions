
#include<bits/stdc++.h>
using namespace std;

int Stack[100],top=-1,top2=100;

bool isEmptyStack1()
{
	if(top==-1)
	return true;
	else
	return false;
}
bool isEmptyStack2()
{
	if(top==100)
	return true;
	else
	return false;
}

void push1(int item)
{
	if(top+1==top2)
	return;
	else
	Stack[++top]=item;
}

void push2(int item)
{
	if(top2-1==top)
	return;
	else
	Stack[--top2]=item;
}


int pop1()
{
	if(isEmptyStack1())
	return -1;
	else
	return Stack[top--];
}

int pop2()
{
	if(isEmptyStack2())
	return -1;
	else
	return Stack[top2++];
}

int main()
{
	
	for(int i=0;i<3;i++)
	{
		int x;
		cin>>x;
		push1(x);
		cin>>x;
		push2(x);
	}
	
	cout<<"Pop";
	cout<<pop1()<<"\n";
	cout<<"Pop";
	cout<<pop2()<<"\n";;

	
}

