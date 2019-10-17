import java.util.*;
class Median
{

	static void findMedian(int arr[],int n)
	{
		 PriorityQueue<Integer> max=new PriorityQueue<Integer>(Collections.reverseOrder());

		 PriorityQueue<Integer> min=new PriorityQueue<Integer>();

		 max.add(arr[0]);
		 	int median=arr[0];

		 	System.out.println(median);

		 for(int i=1;i<n;i++)
		 {
		 	if(max.size()>min.size())
		 	{
		 		if(arr[i]<median)
		 		{
		 			min.add(max.peek());
		 			max.remove();

		 			max.add(arr[i]);
		 		}
		 		else
		 		{
		 			min.add(arr[i]);
		 		}

		 		median=(max.peek()+min.peek())/2;
		 	}

		 	else if(max.size()<min.size())
		 	{
		 		if(arr[i]>median)
		 		{
		 			max.add(min.peek());
		 			min.remove();

		 			min.add(arr[i]);
		 		}
		 		else
		 			max.add(arr[i]);

		 		median=(max.peek()+min.peek())/2;
		 	}

		 	else
		 	{
		 		if(arr[i]<median)
		 		{
		 			max.add(arr[i]);

		 			median=max.peek();
		 		}
		 		else
		 		{
		 			min.add(arr[i]);

		 			median=min.peek();
		 		}
		 	}

		 	System.out.println(median);
		 }


	}

	public static void main(String args[])
	{
		int n;
		Scanner sc=new Scanner(System.in);

		n=sc.nextInt();

		int arr[]=new int[n];

		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}

		findMedian(arr,n);
	}
}