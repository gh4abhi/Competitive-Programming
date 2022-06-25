// Problem Link - https://www.hackerrank.com/challenges/java-strings-introduction/problem?isFullScreen=true

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        int a = A.length() + B.length();
        String check = "No";
        for(int i=0;i<A.length();i++)
        {
            if(i<B.length())
            {
                if(A.charAt(i)<B.charAt(i))
                {
                    break;
                }
                else if(A.charAt(i)>B.charAt(i))
                {
                     check = "Yes";
                    break;
                }
            }
        }
        char val = A.charAt(0);
        char val2 = B.charAt(0);
        for(int i=0;i<=31;i++)
            val--;
        for(int i=0;i<=31;i++)
            val2--;
        A = val + A.substring(1,A.length());
        B = val2 + B.substring(1,B.length());
        System.out.println(Integer.toString(a));
        System.out.println(check);
        System.out.println(A+' '+B);
    }
}



