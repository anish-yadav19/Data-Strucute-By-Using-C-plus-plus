//find no. of ways to reach destination

// steps allowed -> 1 stair at a time
//                  2 stairs at a time

#include<iostream>
using namespace std;

int stairs(int n)
{
    if(n == 0 || n == 1) return 1;
    
    int ans = stairs(n-1) + stairs(n-2);
    return ans;
} 

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;


    int ans = stairs(n);
    cout<<"Answert is: "<<ans;

    return 0;
}
