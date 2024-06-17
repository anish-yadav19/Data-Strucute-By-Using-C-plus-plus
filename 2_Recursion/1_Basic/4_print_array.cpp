//find no. of ways to reach destination

// steps allowed -> 1 stair at a time
//                  2 stairs at a time

#include<iostream>
#include<limits.h>
using namespace std;

void print(int arr[],int n,int i)
{
    if(i>=n) return;
    
    cout<<arr[i]<<" ";
    
    print(arr,n,i+1);
    
    // cout<<arr[i]<<" ";
    
    
} 

void findMax(int arr[],int n,int i, int& maxi)
{
    if(i>=n) return;

    if(arr[i]>maxi)
    {
        maxi = arr[i];
    }
    findMax(arr,n,i+1,maxi);
}

int main()
{
    
    int arr[5] = {10,20,30,40,50};
    int n = 5;
    int i = 0;
    print(arr,n,i);
    cout<<endl;
    int maxi = INT_MIN;
    findMax(arr,n,i,maxi);

    cout<<"Max element is: "<<maxi;

    return 0;
}
