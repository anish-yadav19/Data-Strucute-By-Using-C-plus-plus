#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int arr[],int n)
{
    
    unordered_map<int,int>mp;
    for(int i =0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto it:mp)
    {
        if(it.second == 2)
        {
            return it.first;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3,1,3,4,2};
    int n  = sizeof(arr)/sizeof(arr[0]);
    int ans = findDuplicate(arr,n);
    cout<<ans;

    return 0;
}