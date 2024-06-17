#include<iostream>
using namespace std;

int fibonacci(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;

    int ans = fibonacci(n-1) + fibonacci(n-2);
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;


    int ans = fibonacci(n);
    cout<< n <<"th term is: "<<ans;

    return 0;
}
