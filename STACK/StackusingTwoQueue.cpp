#include<iostream>
#include<queue>
using namespace std;
  void Push(queue<int>&q1,queue<int>&q2,int item)
  {
    q2.push(item);
    while(!q1.empty())
    {
      int k=q1.front();
      q1.pop();
      q2.push(k);
    }
    while(!q2.empty())
    {
    q1.push(q2.front());
    q2.pop();
    }
  }

  int Pop(queue<int>q1)
  {
    if(q1.empty())
      return 0;

   int temp= q1.front();
    q1.pop();
    return temp;
  }
  int peek(queue<int>q1)
  {
      if(q1.empty())
        return 0;
      return q1.front();
  }
  int main()
  {
      queue<int>q1;
      queue<int>q2;
      Push(q1,q2,10);
      Push(q1,q2,15);
      cout<<"Remove front  "<<Pop(q1)<<endl;
      Push(q1,q2,42);
      cout<<"front"<<peek(q1)<<endl;
      Push(q1,q2,23);
      Push(q1,q2,78);
      cout<<"front  "<<peek(q1)<<endl;

  }

