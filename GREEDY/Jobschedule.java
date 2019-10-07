class Jobschedule
{

 public static void main(String args[])
 {
    int  d[]=new int[6];
    int p[]=new int[6];
    d[0]=5;
    d[1]=3;
    d[2]=3;
    d[3]=2;
    d[4]=4;
    d[5]=2;
    
    p[0]=20;
    p[1]=18;
    p[2]=19;
    p[3]=30;
    p[4]=12;
    p[5]=10;
    

    

    int max=schedule(d,p);
    System.out.println(max);
 }

static int schedule(int d[],int p[])
{
  

    for(int i=0;i<6-1;i++)
    {
        for(int j=0;j<6-i-1;j++)
        {
            if(p[j]<p[j+1])
            
            {
              int temp=d[j];
              d[j]=d[j+1];
              d[j+1]=temp;
              
              temp=p[j];
              p[j]=p[j+1];
              p[j+1]=temp;
              
            }
        }
    }
   
   int arr[]=new int[12];
   for(int i=0;i<12;i++)
   {
       arr[i]=0;
   }

   for(int i=0;i<6;i++)
   {
    for(int j=d[i];j>=1;j--)
    {
        if(arr[j]==0)
        {
            arr[j]=p[i];
            break;
        }
    }
   }

   int max=0;

   for(int i=1;i<12;i++)
   {
       System.out.println(arr[i]);
       max=max+arr[i];
   }


    return max;
}

}