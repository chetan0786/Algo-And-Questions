#include<bits/stdc++.h>
using namespace std;

bool safe(int board[10][10], int row, int col,int n) 
{ 
    int i, j; 
  
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 

    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 





bool solve(int board[10][10],int n,int col)
{
	if(col>=n)
	return true;
	
	for(int i=0;i<n;i++)
	{
		if(safe(board,i,col,n))
		{
		
		board[i][col]=1;
		
		if(solve(board,n,col+1))
		return true;
		
		
		board[i][col]=0;
	}
		
	}
	
	return false;
}

void print(int board[10][10],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}	
		cout<<endl;
	} 
}

int main()
{
	int n;
	cin>>n;
	
	int board[10][10] ;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j]=0;
		}	
	} 
  
    if (solve(board,n,0) == false) { 
        printf("Solution does not exist"); 
       
    } 
    else
    print(board,n); 
    
}
