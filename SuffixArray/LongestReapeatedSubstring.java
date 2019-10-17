import java.util.*;

class LongestReapeatedSubstring {


     static String get(String s) {
        int n = s.length();

    
        String[] suffies = new String[n];
        for (int i = 0; i < n; i++) {
            suffies[i] = s.substring(i);
        }

                Arrays.sort(suffies);

        // for (int i =0 ; i < suffies.length; i++){
        //     System.out.println(i + " :: " + suffies[i] );
        // }
        String result = "";

       
        for (int i = 0; i < n - 1; i++) {
            int len = getLongestCommonPrefix(suffies[i], suffies[i + 1]);

            if (len > result.length()) {
                result = suffies[i].substring(0, len);
            }
        }

        return result;
    }

     static int getLongestCommonPrefix(String s1, String s2) {
        int len = 0;
        for (int i = 0, j = 0; i < s1.length() && j < s2.length(); i++, j++) {
            if (s1.charAt(i) != s2.charAt(j)){
                break;
            }
            len++;
        }

        return len;
    }




    public static void main(String[] args) {
        String s = "abababa";
        String longestSuffix = get(s);

        System.out.println("String :" + s);
        System.out.println("Longest Suffix String: " + longestSuffix);
    }
}

