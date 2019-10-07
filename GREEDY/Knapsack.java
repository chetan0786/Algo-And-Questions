class Knapsack
{

 public static void main(String args[])
 {
    int w[]=new int[3];
    int p[]=new int[3];
    w[0]=18;
    w[1]=15;
    w[2]=10;
    p[0]=25;
    p[1]=24;
    p[2]=15;

    int c=20;

    Double max=nac(w,p,c);
    System.out.println(max);
 }



 static Double nac(int w[],int p[],int c)
 {
    for(int i=0;i<3-1;i++)
    {
        for(int j=0;j<3-i-1;j++)
        {
            double temp1=(double)p[j]/(double)w[j];
            double temp2=(double)p[j+1]/(double)w[j+1];
            if(temp1<temp2)
            {
                int d=p[j];
                p[j]=p[j+1];
                p[j+1]=d;

                d=w[j];
                w[j]=w[j+1];
                w[j+1]=d;

            }
        }
    }
  
    double ans=0.0;
    int i=0;
    while(c!=0)
    {
        if(w[i]<c)
        {
            c=c-w[i];
            
            ans=ans+p[i];
            i++;
        }
        else
        {
            
            

           double t=((double)c/(double)w[i]);
        
           ans=ans+(t*p[i]);
            i++;
            c=0;
        }
    }

return ans;

 }

}