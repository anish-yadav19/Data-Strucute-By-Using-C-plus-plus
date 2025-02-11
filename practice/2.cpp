#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++)
    {
        cin>>arr[n];
    }
    int ans = 0;
    bool alter = false;
    for(int i = 0;i<n;i++)
    {
        int even = 0;
        int odd = 0;
        for(int j = 0;j<n;j++)
        {
            if(i == j)
            {
                alter = true;
                continue;
            }
            if((j -(j>i))%2 == 0)
            {
                odd += arr[j];
            }
            else
            {
                even += arr[j];
            }
        }
        if(odd == even) ans++;
    }
    cout<<"Output is: "<<ans;
    return 0;
}