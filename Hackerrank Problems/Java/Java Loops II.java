// Problem Link - https://www.hackerrank.com/challenges/java-loops/problem?isFullScreen=true

import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int pro = 1;
            int sum = a;
            for(int j=0;j<n;j++)
            {
                sum += pro*b;
                System.out.print(Integer.toString(sum)+' ');
                pro*=2;
            }
            System.out.println();
        }
        in.close();
    }
}