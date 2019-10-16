#include<iostream>
#include<stack>
using namespace std;
  void Push(stack<int> &st1, stack<int> &st2, int item)
  {
    while(!st1.empty())
    {
      st2.push(st1.top());
      st1.pop();
    }
    st1.push(item);
    while(!st2.empty())
    {
      st1.push(st2.top());
      st2.pop();
    }
  }

  int Pop(stack<int> &st1)
  {
   if(!st1.empty())
   {
     int k=st1.top();
     st1.pop();
     return k;
   }
    return -1;
  }
  int Front(stack<int> &st1)
  {
      if(!st1.empty())
        return st1.top();
      return -1;
  }
  int main()
  {
      stack<int>s1;
      stack<int>s2;
      Push(s1,s2,15);
      Push(s1,s2,10);
      
      Push(s1,s2,2);
      Push(s1,s2,56);
      cout<<Front(s1)<<endl;

  }
