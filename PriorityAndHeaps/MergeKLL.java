import java.util.*;

class Node
{
	int data;
	Node next;

	Node(int data)
	{
		this.data=data;

		next=null;
	}
}

class MergeKLL
{

	static Node merge(Node LL[],int k)
	{
		PriorityQueue<Node> p=new PriorityQueue<Node>(new Comparator<Node>() { 
            public int compare(Node a, Node b) 
            { 
                return a.data - b.data; 
            } 
        }); 


        for(int i=0;i<k;i++)
        {
        	p.add(LL[i]);
        }
        Node head=null;
        while(!p.isEmpty())
        {
        	Node ll=p.peek();
        	p.remove();

        	if(ll.next!=null)
        		p.add(ll.next);

        	if(head==null)
        	{
        		head=new Node(ll.data);
        	}
        	else
        	{
        		Node temp=head;

        		while(temp.next!=null)
        		{
        			temp=temp.next;
        		}
        		temp.next=new Node(ll.data);
        	}
        }

        return head;
	}

	public static void main(String args[])
	{
		int k;
		Scanner sc=new Scanner(System.in);
		k=sc.nextInt();
		Node LL[]=new Node[k];

		for(int i=0;i<k;i++)
		{
			int n;
			n=sc.nextInt();

			int x;
			x=sc.nextInt();

			LL[i]=new Node(x);

			for(int j=1;j<n;j++)
			{
				x=sc.nextInt();

				Node temp=LL[i];

				while(temp.next!=null)
					temp=temp.next;

				temp.next=new Node(x);
			}



		}

		
		Node head=merge(LL,k);

		while(head!=null)
		{
			System.out.print(head.data+" ");
			head=head.next;
		}
	}
}