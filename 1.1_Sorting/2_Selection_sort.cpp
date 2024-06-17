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
    for(int i = 0;i<n-1;i++)
    {
        int mini = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]<arr[mini]) mini = j;
            
        }
        swap(arr[mini],arr[i]);
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