import chetands.*;
class Html
{

	static boolean html(String str)
	{
        Stack<String> st = new LinkedStack<>();
	
        int i = 0;
        while(i < str.length() )
        {
            if(str.charAt(i) == '<' && str.charAt(i+1)=='/')
            {
                String res = str.substring(i+2,str.indexOf(">",i+2));
               // System.out.println(res);
                if(res.compareToIgnoreCase(st.top())==0)
                {
                    st.pop();
                }
                else
                    return false;
            }
            else if(str.charAt(i)=='<')
            {
                st.push(str.substring(i+1,str.indexOf('>',i+1)));
            }
            i++;
        }
        if(st.isEmpty())
            return true;
        return false;
	}

	public static void main(String[] args) {
		String check=new String();
        check+="<h1>abc </h1> ";
		System.out.println(html(check));

	  }






	// public static void main(String[] args) {
	// 	Queue<Integer> S = new ArrayQueue<>();  // contents: ()
	// 	S.enqueue(5);                              // contents: (5)
	// 	S.enqueue(3);                              // contents: (5, 3)
	// 	System.out.println(S.size());           // contents: (5, 3)     outputs 2
	// 	System.out.println(S.dequeue());            // contents: (5)        outputs 3
	// 	System.out.println(S.isEmpty());        // contents: (5)        outputs false
	// 	System.out.println(S.dequeue());            // contents: ()         outputs 5
	// 	System.out.println(S.isEmpty());        // contents: ()         outputs true
	// 	System.out.println(S.dequeue());            // contents: ()         outputs null
	// 	S.enqueue(7);                              // contents: (7)
	// 	S.enqueue(9);                              // contents: (7, 9)
	// 	System.out.println(S.first());            // contents: (7, 9)     outputs 9
	// 	S.enqueue(4);                              // contents: (7, 9, 4)
	// 	System.out.println(S.size());           // contents: (7, 9, 4)  outputs 3
	// 	System.out.println(S.dequeue());            // contents: (7, 9)     outputs 4
	// 	S.enqueue(6);                              // contents: (7, 9, 6)
	// 	S.enqueue(8);                              // contents: (7, 9, 6, 8)
	// 	System.out.println(S.dequeue());            // contents: (7, 9, 6)  outputs 8
	//   }
	
}