#include<iostream>
#include<queue>
using namespace std;

void solve(int arr[], int n, int k)
{
    queue<int>q;

    //process first window of size k

    for(int i = 0;i<k;i++)
    {
        if(arr[i]<0)
        {
            q.push(i);
        } 
    }

    // remaining window ko process kro

    for(int i= k;i<n;i++)
    {
        if(q.empty())
        {
            cout<< 0 <<" ";
        }
        else
        {
            cout<<arr[q.front()]<<" ";
        }

        // out of window of remove krdo

        while((!q.empty()) && (i-q.front()>=k))
        {
            q.pop();
        }

        // check current element for insertion

        if(arr[i]<0)
        {
            q.push(i);
        }
    
    }
        if(q.empty())
        {
            cout<< 0 <<" ";
        }
        else
        {
            cout<<arr[q.front()]<<" ";
        }


}

int main()
{
    // int arr[] = {12,-1,-7,8,-15,30,16,28};
    int arr[] = {-8,2,3,-6,10};
    int size = 5;

    int k = 2;
    solve(arr,size,k);

    return 0;
}