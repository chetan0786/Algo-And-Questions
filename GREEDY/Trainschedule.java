 class structure
{
 double val;
 int status;

}


class Trainschedule
{

 public static void main(String args[])
 {
    double a[]=new double[4];
    double p[]=new double[4];
    a[0]=10.00;
    a[1]=10.15;
    a[2]=10.30;
    a[3]=10.40;
    
    p[0]=10.20;
    p[1]=14.00;
    p[2]=15.00;
    p[3]=10.55;
    

    

    int max=schedule(a,p);
    System.out.println(max);
 }

static int schedule(double s[],double e[])
{
   structure arr[]=new structure[8];
   int k=0;
    for(int i=0;i<4;i++)
    {
        arr[k]=new structure();
        arr[k].val=s[i];
        arr[k].status=1;
        k++;
        arr[k]=new structure();
        arr[k].val=e[i];
        arr[k].status=-1;
        k++;
    }

    for(int i=0;i<8-1;i++)
    {
        for(int j=0;j<8-i-1;j++)
        {
            if(arr[j].val>arr[j+1].val)
            {
                structure temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
   
    int count=0;
    int max=0;
    for(int i=0;i<8;i++)
    {
        count=count+arr[i].status;
        if(count>max)
        max=count;
    }

    return max;
}

}