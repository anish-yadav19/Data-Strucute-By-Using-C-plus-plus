#include<iostream>
#include<queue>
using namespace std;

int getkthLargestElement(int arr[],int n, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;

    // insert initial k element
    for(int i = 0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    // for remaining elements, push only if they are less than top

    for(int i = k;i<n;i++)
    {
        int element = arr[i];
        if(element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;

}


int getkthSmallestElement(int arr[],int n, int k)
{
    priority_queue<int>pq;

    // insert initial k element
    for(int i = 0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    // for remaining elements, push only if they are less than top

    for(int i = k;i<n;i++)
    {
        int element = arr[i];
        if(element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;

}

int main()
{

    int arr[] = {10,5,20,4,15};
    int k = 1;
    int n = 5;

     int ans = getkthSmallestElement(arr,n,k);

    int largest = getkthLargestElement(arr,n,k);
    
     cout<<"Smallest element: "<<ans<<endl; 
    cout<<"Largest element: "<<largest<<endl; 


    return 0;
}