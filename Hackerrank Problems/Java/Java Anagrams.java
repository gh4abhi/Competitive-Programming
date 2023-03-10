// Problem Link - https://www.hackerrank.com/challenges/java-anagrams/problem?isFullScreen=true

import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        for(int i=0; i<a.length();i++)
        {
            a = a.substring(0,i) + Character.toUpperCase(a.charAt(i)) + a.substring(i+1,a.length());
        }
        for(int i=0; i<b.length();i++)
        {
            b = b.substring(0,i) + Character.toUpperCase(b.charAt(i)) + b.substring(i+1,b.length());
        }
        // char[] op1 = a.toCharArray();
        // Arrays.sort(op1);
        // a = String(op1);
        // char[] op2 = b.toCharArray();
        // Arrays.sort(op2);
        // b = String(op2);
        char arr[] = a.toCharArray();
        for(int i=0;i<arr.length;i++)
        {
            for(int j = i+1;j<arr.length;j++)
            {
                if(arr[i]>arr[j])
                {
                    char temp=arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        String a1 = new String(arr);
        char arr2[] = b.toCharArray();
        for(int i=0;i<arr2.length;i++)
        {
            for(int j = i+1;j<arr2.length;j++)
            {
                if(arr2[i]>arr2[j])
                {
                    char temp = arr2[i];
                    arr2[i] = arr2[j];
                    arr2[j] = temp;
                }
            }
        }
        String b1 = new String(arr2);
        
        return a1.compareTo(b1)==0;
    }

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}