// Problem Link - https://www.hackerrank.com/challenges/java-string-reverse/problem?isFullScreen=true

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        int start = 0, end = A.length()-1;
        int flag = 1;
        while(start<=end)
        {
            if(A.charAt(start)!=A.charAt(end))
            {
                flag = 0;
                break;
            }
            start++;
            end--;
        }
        if(flag==1)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}



