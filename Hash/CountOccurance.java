import java.util.*;
  
public class CountOccurance { 
  
static int countOccurences(String str, String word)  
{ 
    String a[] = str.split(" "); 
  
    int count = 0; 
    for (int i = 0; i < a.length; i++)  
    { 
    if (word.equals(a[i])) 
        count++; 
    } 
  
    return count; 
} 
  
public static void main(String args[])  
{ 
    String str; 
    String word ;
    Scanner sc=new Scanner(System.in);
    str=sc.nextLine();
    word=sc.nextLine();

    System.out.println(countOccurences(str, word)); 
} 
} 