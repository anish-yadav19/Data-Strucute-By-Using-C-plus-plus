
#include<iostream>
#include<limits.h>
using namespace std;

bool checkSorted(int arr[],int n,int i,int j)
{
    if(j>=n) return true;
    
    if(arr[i]>arr[j])
    {
        return false;
    }
    
     return checkSorted(arr,n,i+1,j+1);
    
    // cout<<arr[i]<<" ";
    
    
} 



int main()
{
    
    int arr[5] = {10,20,60,40,50};
    int n = 5;
    int i = 0;
    int j = 1;
    bool ans = checkSorted(arr,n,i,j);
    cout<<ans<<endl;
    
    

    return 0;
}
