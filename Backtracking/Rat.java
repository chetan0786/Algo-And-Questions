import java.util.Scanner;

class Rat
{
    public static void main(String arg[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[][]=new int[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    arr[i][j]=sc.nextInt();
            }
        }


        checkpath(arr,0,0,n,"");

    }

    static void checkpath(int arr[][],int i,int j,int n,String a)
    {
        if(i==n-1&&j==n-1)
        {
            System.out.println(a);
            
        }

        else if(i>n-1||j>n-1)
        return ;

        else if(arr[i][j]==0)
        return ;

        else
        {
            a+=i;
            a+=j;
            a+=" ";
            checkpath(arr,i+1,j,n,a);
             
            checkpath(arr, i, j+1, n, a);

        

        }
    }
}