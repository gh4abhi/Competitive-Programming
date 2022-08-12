// Problem Link - https://www.codingninjas.com/codestudio/problems/1112654?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

int uniqueElement(vector<int> arr, int n)
{
    if(n==1)
        return arr[0];
    ll start = 0, end = n-2;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(arr[mid]==arr[mid^1])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return arr[start];
}
