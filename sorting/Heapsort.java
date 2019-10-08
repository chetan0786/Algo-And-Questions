class Heapsort
{
   static  void heapify(int arr[],int i,int n)
    {
        int l=2*i+1;
        int max=i;
        int r=2*i+2;
        if(l<n&&arr[l]>arr[max])
        {
            max=l;
        }
        if(r<n&&arr[r]>arr[max])
        {
            max=r;
        }

        if(max!=i)
        {
            int t=arr[i];
            arr[i]=arr[max];
            arr[max]=t;

            heapify(arr, max,n);
        }
    }
    static void sort(int arr[],int n)
    {
        for(int i=n/2;i>=0;i--)
        {
            heapify(arr, i,n);
        }
    for (int i=n-1; i>=0; i--) 
    { 
        int temp = arr[0]; 
            arr[0] = arr[i]; 
            arr[i] = temp;
        heapify(arr, 0, i); 
    } 
    }

    
    public static void main(String args[])
    {
        int n=7;
        int arr[]=new int[7];
        arr[0]=5;arr[1]=7;arr[2]=4;arr[3]=2;arr[4]=1;arr[5]=11;arr[6]=50;

       sort(arr,n);
        
       for(int i=0;i<n;i++)
       {
           System.out.println(arr[i]);
       }
    }
}