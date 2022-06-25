// Problem Link - https://www.hackerrank.com/challenges/java-negative-subarray/problem?isFullScreen=true

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = in.nextInt();
        }
        int sum = 0;
        for(int i = 0;i<arr.length;i++)
        {
            int op = 0;
            for(int j = i;j<arr.length;j++)
            {
                op += arr[j];
                if(op<0)
                    sum++;
            }
        }
        System.out.println(sum);
    }
}