#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int s , int e)
{

    //step1: choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    // step2 : find right position for pivot element and place it there
    int count = 0;
    for(int i = s+1;i<=e;i++)
    {
        if(arr[i]<=pivotElement)
        {
            count++;
        }
    }
    //jab m loop se bahar aaya , tb mere pass pivot ki right poision ka index ready h   

    int correctIndex = s+count;

    swap(arr[pivotIndex],arr[correctIndex]);
    pivotIndex = correctIndex;

    // step3: left me chhote and right me bade

    int i = s;
    int j = e;
    while(i<pivotIndex && j > pivotIndex)
    {
        while(arr[i]<=pivotElement)
        {
            i++;
        }
        while(arr[j]>pivotElement)
        {
            j--;
        }

        if(i<pivotIndex && j > pivotIndex)
        {
            swap(arr[i],arr[j]);
        }
    }

    return pivotIndex;


}

void quickSort(int arr[], int s, int e)
{
    //base case
    if(s>=e) return;

    // partition logic returning pivot index
    int index = partition(arr,s,e);


    // recursive logic
    // pivot element -> left
    quickSort(arr,s,index-1);

    // pivot element->right
    quickSort(arr,index+1,e);
}

int main()
{
    int arr[] = {8,1,3,4,20,50,30,3,3,3,4,20,20};
    int n = 13;

    quickSort(arr,0,12);

    cout<<"printing sorted array: "<<endl;
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}