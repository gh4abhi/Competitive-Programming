// Problem Link - https://www.codingninjas.com/codestudio/problems/630450?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

int search(int* arr, int n, int key) {
    ll start = 0, end = n-1;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(arr[mid]==key)
            return mid;
        if(arr[start]<=arr[mid])
        {
            if(key>=arr[start] and key<=arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if(key>=arr[mid] and key<=arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}