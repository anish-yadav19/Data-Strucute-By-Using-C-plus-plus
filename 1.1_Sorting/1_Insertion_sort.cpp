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
    
    for(int i = 1;i<n;i++)
    {
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                // shifting
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
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