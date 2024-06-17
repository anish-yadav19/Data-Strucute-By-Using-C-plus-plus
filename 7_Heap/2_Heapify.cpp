#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int index = i;
    int largest = index;

    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest]< arr[left])
    {
        largest = left;
    }

     if(right <= n && arr[largest]< arr[right])
    {
        largest = right;
    }

    if(index != largest)
    {
        // left ya right child me se koi > hoga current node se

        swap(arr[index], arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}



void heapSort(int arr[], int n)
{
   
    while(n!=1)
    {
        swap(arr[1], arr[n--]);
        heapify(arr,n,1);
    }
}

int main()
{

    int arr[] = {-1,54,53,55,52,50};
    int n = 5;

    // build heap
    for(int i = n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }

    cout<<"Printing "<<endl;

    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout<<"Printing sorted heap "<<endl;

    for(int i = 1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}