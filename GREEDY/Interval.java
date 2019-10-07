class Interval
{

 public static void main(String args[])
 {
    int w[]=new int[6];
    int p[]=new int[6];
    w[0]=10;
    w[1]=9;
    w[2]=7;
    w[3]=12;
    w[4]=20;
    w[5]=1;
    p[0]=13;
    p[1]=14;
    p[2]=11;
    p[3]=16;
    p[4]=25;
    p[5]=30;

    

    int max=interval(w,p);
    System.out.println(max);
 }

static int interval(int s[],int e[])
{
    for(int i=0;i<3-1;i++)
    {
        for(int j=0;j<3-i-1;j++)
        {
            
            if(e[j]>e[j+1])
            {
                int d=s[j];
                s[j]=s[j+1];
                s[j+1]=d;

                d=e[j];
                e[j]=e[j+1];
                e[j+1]=d;

            }
        }
    }

    int max=e[0];
    int count=1;
    for(int i=1;i<6;i++)
    {
        if(s[i]>max)
        {
            max=e[i];
            count++;
        }
    }

    return count;
}

 

}