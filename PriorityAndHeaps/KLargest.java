import java.util.*;

class KLargest
{


	static void findLargest(int arr[],int n,int k)
	{

		PriorityQueue<Integer> p=new PriorityQueue<Integer>();

		for(int i=0;i<k-1;i++)
		{
			p.add(arr[i]);
			System.out.println("-1");
		}
		p.add(arr[k-1]);

		System.out.println(p.peek());
		for(int i=k;i<n;i++)
		{
			if(arr[i]>p.peek())
			{
				p.remove();
				p.add(arr[i]);
			}

			System.out.println(p.peek());
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
		int k;
		k=sc.nextInt();
		findLargest(arr,n,k);
	}
}