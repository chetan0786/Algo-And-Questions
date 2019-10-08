#include<bits/stdc++.h>
using namespace std;

void BinaryStrings(char *str,int s,int n)
{
    if(s==n)
    {
            cout<<str<<endl;
            return;
    }
    
    str[s]='0';
    BinaryStrings(str,s+1,n);
    str[s]='1';
    BinaryStrings(str,s+1,n);
    
}

int main()
{
    int n;
    cin>>n;

    char str[100];

    BinaryStrings(str,0,n); 
}
