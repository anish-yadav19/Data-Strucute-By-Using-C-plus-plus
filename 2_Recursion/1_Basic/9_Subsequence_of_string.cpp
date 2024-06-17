#include<iostream>
#include<vector>
using namespace std;


void printSubsequence(string str,string output,int i,vector<string>&v)
{
    if(i>=str.length())
    {
        // cout<< output<<endl;
        v.push_back(output);
        return;
    }

    //exclude
    printSubsequence(str,output,i+1,v);

    //include
    output = output + str[i];
    printSubsequence(str,output,i+1, v);
}

int main()
{

    vector<string>v;

    string str = "abc";
    string output = "";
    

    int i = 0;
    printSubsequence(str, output,i,v);

    cout<<"Printing all subsequences "<<endl;
    for(auto val: v)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Size of vector is: "<<v.size()<<endl;


    return 0;
}