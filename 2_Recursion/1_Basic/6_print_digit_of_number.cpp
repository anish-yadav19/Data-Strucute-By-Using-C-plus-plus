#include<iostream>
using namespace std;


void printDigit(int n)
{
    if(n == 0) return;

    int digit = n%10;
    
    int rem = n/10;
    printDigit(rem);
    cout<<digit<<" ";
}
int main()
{


    int n = 6754000;
    

    printDigit(n);
    return 0;
}