#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6] = {10,20,30,40,50,60};
    int n =(sizeof(arr)/sizeof(arr[0]));
    // cout<<n;
    int start = 0;
    int end = 5;
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}