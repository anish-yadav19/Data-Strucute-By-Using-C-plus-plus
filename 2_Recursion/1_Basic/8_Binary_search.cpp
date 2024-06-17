#include<iostream>
#include<limits.h>
using namespace std;

int binarySearch(int arr[],int s, int e,int key)
{
   
    if(s>e) return -1;
    int mid = (s+e)/2;

    if(arr[mid] == key) return mid;

    if(arr[mid]>key) 
    {
        return binarySearch(arr,s,mid-1,key);
    }
    else
    {
        return binarySearch(arr,mid+1,e,key);
    }
    
} 



int main()
{
    
    int arr[5] = {10,20,60,40,50};
    int n = 5;
    int s = 0;
    int e = n-1;
    int key = 60;

    int ans = binarySearch(arr,s,e,key);
    cout<<key<<" is present at " <<ans<<endl;
    
    

    return 0;
}
