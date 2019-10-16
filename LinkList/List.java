import java.util.*;

  class SinglyLinkedList<E extends Comparable<E>> 
{
  //---------------- nested Node class ----------------
  /**
   * Node of a singly linked list, which stores a reference to its
   * element and to the subsequent node in the list (or null if this
   * is the last node).
   */
  private static class Node<E extends Comparable<E>> 
  {
    /** The element stored at this node */
    private E element;            // reference to the element stored at this node

    /** A reference to the subsequent node in the list */
    private Node<E> next;         // reference to the subsequent node in the list

    /**
     * Creates a node with the given element and next node.
     *
     * @param e  the element to be stored
     * @param n  reference to a node that should follow the new node
     */
    public Node(E e, Node<E> n) 
    {
      element = e;
      next = n;
    }

    // Accessor methods
    /**
     * Returns the element stored at the node.
     * @return the element stored at the node
     */
    public E getElement() 
    { 
      return element; 
    }
	
	
	public void setElement(E element) 
    { 
      this.element=element;
    }

    /**
     * Returns the node that follows this one (or null if no such node).
     * @return the following node
     */
    public Node<E> getNext() { return next; }

    // Modifier methods
    /**
     * Sets the node's next reference to point to Node n.
     * @param n    the node that should follow this one
     */
    public void setNext(Node<E> n) { next = n; }
  } //----------- end of nested Node class -----------


  // instance variables of the SinglyLinkedList
  /** The head node of the list */

  private Node<E> head = null;               // head node of the list (or null if empty)


  /** The last node of the list */
  private Node<E> tail = null;               // last node of the list (or null if empty)


  /** Number of nodes in the list */
  private int size = 0;                      // number of nodes in the list


  /** Constructs an initially empty list. */
  public SinglyLinkedList() { }              // constructs an initially empty list


  // access methods
  /**
   * Returns the number of elements in the linked list.
   * @return number of elements in the linked list
   */
  public int size() { return size; }


  /**
   * Tests whether the linked list is empty.
   * @return true if the linked list is empty, false otherwise
   */
  public boolean isEmpty() { return size == 0; }

  /**
   * Returns (but does not remove) the first element of the list
   * @return element at the front of the list (or null if empty)
   */
  public E first() {             // returns (but does not remove) the first element
    if (isEmpty()) return null;
    return head.getElement();
  }

  /**
   * Returns (but does not remove) the last element of the list.
   * @return element at the end of the list (or null if empty)
   */
  public E last() {              // returns (but does not remove) the last element
    if (isEmpty()) return null;
    return tail.getElement();
  }

  // update methods
  /**
   * Adds an element to the front of the list.
   * @param e  the new element to add
   */
  public void addFirst(E e) {                // adds element e to the front of the list
    head = new Node<>(e, head);              // create and link a new node
    if (size == 0)
      tail = head;                           // special case: new node becomes tail also
    size++;
  }

  /**
   * Adds an element to the end of the list.
   * @param e  the new element to add
   */
   public void addBetween(E e,int pos)
   {
	   if(pos==1)
	   {
		   addFirst(e);
	   }
	   else if(pos>size)
	   {
		   addLast(e);
	   }
	   
	   else{
		   
		   Node<E> walk=head;
		   int count=1;
		   while(count!=pos-1)
		   {
			   count++;
			   walk=walk.getNext();
			   
		   }
		   Node<E> temp=walk.getNext();
		   
		   Node<E> newest=new Node<>(e,temp);
		   
		   walk.setNext(newest);
		   
		   
	   }
	   
	   
   }
   
    public void reverse()
  {
    Node<E> temp=head;
    Node<E> prev=null;
    Node<E> current=head;
    Node<E> next=null;
    while(current!=null)
    {
      next=current.getNext();
      current.setNext(prev);
      prev=current;
      current=next;
    }
    head=prev;
    tail=temp;
  }
  
  
  
  public void sort()
  {
    Node<E> start=head;
    while(start!=null)
    {
      Node<E> next=start.getNext();
      while(next!=null)
      {
        E x=start.getElement();
        E y=next.getElement();
        if(x.compareTo(y)>0)
        {
          start.setElement(y);
          next.setElement(x);
        }
        next=next.getNext();
      }
      start=start.getNext();
    }
  }
  
  public void merge(SinglyLinkedList<E> list)
  {
	  Node<E> i=head;
	  Node <E> j=list.head;
	  Node <E> prev=head;
	  while(i!=null&&j!=null)
	  {
		E x=i.getElement();
        E y=j.getElement();
		 if(x.compareTo(y)<0)
		 {
			prev=i;
			i=i.getNext();
		 }
		 else{
			 
			 Node <E> temp=j;
			 j=j.getNext();
			 if(prev==i)
			 {
				 temp.setNext(head);
				 head=temp;
				 prev=temp;
				 
			 }
			 else{
			 temp.setNext(prev.getNext());
			 prev.setNext(temp);
			 prev=temp;
			 }
		 }
		  
		  
	  }
	  if(i==null&&j!=null)
	  {
		  prev.setNext(j);
		  while(j.getNext()!=null)
		  {
			  j=j.getNext();
		  }
		  
		  tail=j;
		  
	  }
	  
	  
	  
	  
	  
  }
  
  
  
  public  E cycle()
  {
	  Node <E> slow=head;
	  Node <E> fast=head;
	  while(fast.getNext()!=null&&fast.getNext().getNext()!=null)
    {
        slow=slow.getNext();
     fast=fast.getNext().getNext();
    
        if(slow==fast)
        {
          slow=head;
          while(fast!=null)
          {
              if(slow==fast)
              {
                  return slow.getElement();
              }
              
              slow=slow.getNext();
              fast=fast.getNext();
          }
        }
         
        
    }
    return head.getElement();
	  
  }
  
  public E mergepoint(SinglyLinkedList<E> list)
  {
	  
	  Node <E>temp1=head;
	  Node <E>temp2=list.head;
	  int count1=0;
	  int count2=0;
	  while(temp1!=null)
	  {
		 temp1=temp1.getNext();
		  count1++;
		  
	  }
	 
	  while(temp2!=null)
	  {
		 temp2=temp2.getNext();
		  count2++;
		  
	  }
	  if(count1>count2)
	  {
		  count1=count1-count2;
		  temp1=head;
		  int i=0;
		  while(temp1!=null&&i!=count1)
		  {
			  temp1=temp1.getNext();
			  i++;
		  }
		  temp2=list.head;
	  }
	  else{
		   count2=count2-count1;
		  temp2=list.head;
		  int i=0;
		  while(temp2!=null&&i!=count2)
		  {
			  temp2=temp2.getNext();
			  i++;
		  }
		  temp1=head;
		  
	  }
	  while(temp1!=null&&temp1!=temp2)
	  {
		  E x=temp1.getElement();
		  E y=temp2.getElement();
		  if(x.compareTo(y)==0)
		  {
			  break;
		  }
		  temp1=temp1.getNext();
		  temp2=temp2.getNext();
	  }
	  
	  return temp1.getElement();
	  
  }
  
  
  
  
  
  
  
   
   
  public void addLast(E e) {                 // adds element e to the end of the list
    Node<E> newest = new Node<>(e, null);    // node will eventually be the tail
    if (isEmpty())
      head = newest;                         // special case: previously empty list
    else
      tail.setNext(newest);                  // new node after existing tail
    tail = newest;                           // new node becomes the tail
    size++;
  }

  /**
   * Removes and returns the first element of the list.
   * @return the removed element (or null if empty)
   */
  public E removeFirst() {                   // removes and returns the first element
    if (isEmpty()) return null;              // nothing to remove
    E answer = head.getElement();
    head = head.getNext();                   // will become null if list had only one node
    size--;
    if (size == 0)
      tail = null;                           // special case as list is now empty
    return answer;
  }


  /**
   * Produces a string representation of the contents of the list.
   * This exists for debugging purposes only.
   */
  public String toString() {
    StringBuilder sb = new StringBuilder("(");
    Node<E> walk = head;
    while (walk != null) {
      sb.append(walk.getElement());
      if (walk != tail)
        sb.append(", ");
      walk = walk.getNext();
    }
    sb.append(")");
    return sb.toString();
  }
  public E findMiddle()
  {
  	if(head==null)
  {
    return null;
  }

  Node<E> slow=head;
  Node<E> fast=head;
  while(fast!=null&&fast.getNext()!=null&&(fast.getNext()).getNext()!=null)
  {
    slow=slow.getNext();
    fast=(fast.getNext()).getNext();
    
  }
  if(fast.getNext()==null)
  {
    return slow.getElement();
  }
  return slow.getElement();
  }





  public E Nfromlast(int n)
  {
  	if(head==null)
    return null;
	Node<E> temp=head;
  int count=1;
  while(temp.getNext()!=null)
  {
    count++;
   temp=temp.getNext();
  }
  if(n>count)
   return  temp.getElement();
  
 
  int i=0;
  temp=head;
  while(i!=count-n)
  {
    temp=temp.getNext();
    i++;
  }
    return temp.getElement();
}

  



  public boolean CheckPalindrome()
  {
  	if(head==null)
    {
      return false;
    }
    if(head.getNext()==null)
    return true;
	Stack<E> a=new Stack<E>();
    Node<E> slow=head;
    Node<E> fast=head;
    while(fast!=null&&fast.getNext()!=null&&fast.getNext().getNext()!=null)
    {
      a.push(slow.getElement());
      slow=slow.getNext();
      fast=fast.getNext().getNext();
    }
    
 
   if(fast.getNext()!=null)
  {
      a.push(slow.getElement());
  }
        slow=slow.getNext();
    
 
   while(slow!=null)
    {
      E temp=a.peek();
      if(slow.getElement()!=temp)
      {
        return false;
      }
     a.pop();
      slow=slow.getNext();
    }
    return true;
  }

public  Node<E> work(Node<E>slow,Node<E> fast)
{
	if(fast==null)
		return slow;
	if(fast.getNext()==null)
		return slow.getNext();

	Node<E> temp=work(slow.getNext(),fast.getNext().getNext());
	
	temp.setElement(temp.getElement());
	slow.setElement(temp.getElement());
	return temp.getNext();


}

public void RecursiveADDalternate()
{
	Node<E>temp=head;
	temp=work(temp,temp);
}




public boolean detectLoop()
{
	
	Node<E> slow=head;
    Node<E> fast=head;
    while(fast!=null&&fast.getNext()!=null&&fast.getNext().getNext()!=null)
    {
      slow=slow.getNext();
      fast=fast.getNext().getNext();
      if(slow==fast)
        {
        	removeloop(slow);
        	return true;
        }
      
    }

    return false;
}

public int getCount(Node<E> ptr)
{
	Node<E> temp=ptr;
	int count=0;
    while(true)
    {
    	count++;
    	temp=temp.getNext();
    	if(temp==ptr)
    		break;
    }
    return count;
}

public boolean IsAccessible(Node<E> source,Node<E> target,int count)
{
	while(count!=0)
	{
		if(target==source)
			return true;
		source=source.getNext();
		count--;
	}
	return false;
}

public void removeloop(Node<E> ptr2)
{
  Node<E> temp=head;
  int count_Ele=getCount(ptr2);
  while(IsAccessible(ptr2,temp,count_Ele)==false)
  {
  	temp=temp.getNext();
  }
  while(count_Ele!=1)
  {
  	temp=temp.getNext();
  	count_Ele--;
  }
  temp.setNext(null);

}


public void createLoop(int loopPoint)
{
   Node<E> temp=head;
   int count=0;
   while(count!=loopPoint)
   {
   	count++;
   	temp=temp.getNext();
   	
   }
   tail.setNext(temp);
   System.out.println("TAIL : _ "+(tail.getNext()).getElement());
}


public void reverseusingStack()
{
	Stack<Node<E>> s=new Stack<Node<E>>();

	Node<E> temp=head;

	while(temp.getNext()!=null)
	{
		s.push(temp);
		temp=temp.getNext();
	}
	head=temp;

	while(!s.empty())
	{
		temp.setNext(s.peek());
		temp=temp.getNext();
		s.pop();
	}

	temp.setNext(null);

	tail=temp;
}



public Node<E> reverseRecursive(Node<E> temp)
{
		if (temp == null) 
            return null; 
        if (temp.getNext() == null) { 
            head = temp; 
            return temp; 
        } 
        Node<E> node1 = reverseRecursive(temp.getNext()); 
        node1.setNext(temp);
        temp.setNext(null);
        return temp; 
}

public void rrecursive()
{
	Node<E>temp=head;
	temp=reverseRecursive(temp);

}

public E mergepointusingHash(SinglyLinkedList<E> list)
{
	 Node <E>n1=head;
	  Node <E>n2=list.head;
	HashSet<Node<E>> hs = new HashSet<Node<E>>(); 
        while (n1 != null) { 
            hs.add(n1); 
            n1 = n1.getNext(); 
        } 
        while (n2 != null) { 
            if (hs.contains(n2)) { 
                return n2.getElement(); 
            } 
            n2 = n2.getNext(); 
        } 
        return null; 
}



}



public class List
{
	public static void main(String args[])
	{
		SinglyLinkedList<Integer>s =new SinglyLinkedList<Integer>();
		for(int i=1;i<=8;i++)
		{
			s.addLast(i);
		}

		System.out.println("Middle Element   "+s.findMiddle());
		System.out.println("4 from Last Element   "+s.Nfromlast(4));
		System.out.println("Checking Palindrome     "+s.CheckPalindrome());
		//s.RecursiveADDalternate();
		
       // s.createLoop(4);
	//	System.out.println(s.detectLoop());
	//	System.out.println(s.toString());

		s.reverseusingStack	();
		System.out.println(s.toString());

		System.out.println(s.mergepointusingHash(s));
	}
}
