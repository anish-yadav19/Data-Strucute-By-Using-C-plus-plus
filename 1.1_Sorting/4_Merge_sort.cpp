#include<bits/stdc++.h>
using namespace std;

void merge_fun(vector<int>&arr, int s, int e)
{
    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int>left(len1);
    vector<int>right(len2);

    // copy element;
    int k = s;
    for(int i = 0;i<len1;i++)
    {
        left[i] = arr[k];
        k++;
    }
    k = mid+1;
    for(int i = 0;i<len2;i++)
    {
        right[i] = arr[k];
        k++;
    }
    //merge logic

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex < len1 && rightIndex < len2)
    {
        if(left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
        while(leftIndex<len1)
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }

        while(rightIndex<len2)
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    

}

void merge_sort(vector<int>&arr,int s, int e)
{
    //base case
    // s == e -> single element
    // s > e -> invalid array

    if(s>=e) return; 

    int mid = (s+e)/2;
    //left part sort krdo recursion bhaiya
    
    merge_sort(arr,s,mid);

    // right part
    merge_sort(arr,mid+1,e);

    // merge two sorted array

    merge_fun(arr,s,e);
}

int main()
{
    vector<int>arr{4,13,5,13,2,12,22,10};
    int n = arr.size();

    cout<<"Before sorting: "<<endl;

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;


    
    merge_sort(arr,0,n-1);

    // printing
    
    cout<<"After sorting: "<<endl;
    for(int i= 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}