// Problem Link - https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1

#define ll int

bool findPair(int arr[], int n, int x){
    sort(arr,arr+n);
    ll start=0,end=1;
    while(end<n)
    {
        if(arr[end]-arr[start]<x)
            end+=1;
        else if(arr[end]-arr[start]>x)
        {
            if(start+1!=end)
                start+=1;
            else
                end+=1;
        }
        else
            return 1;
    }
    return 0;
}