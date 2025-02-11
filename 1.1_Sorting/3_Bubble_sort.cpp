#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>arr{10,1,7,6,14,9};
    int n = arr.size();

    cout<<"Before sorting: "<<endl;

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    for(int i = n-1;i>=1;i--)
    {
        for(int j = 0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    // printing
    

    cout<<"After sorting: "<<endl;

    for(int i= 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}