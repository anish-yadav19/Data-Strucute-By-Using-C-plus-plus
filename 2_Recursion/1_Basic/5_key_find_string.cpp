#include<iostream>
#include<vector>
using namespace std;


int checkKey(string str,int i,int n,char key,vector<int>&ans)
{
    if(i>=n) return -1;

    
    

    if(str[i] == key)
    {
        ans.push_back(i);
    }
    return checkKey(str,i+1,n,key,ans);
}
int main()
{
    string str = "AnishAnish";
    int n =str.length();

    char key = 'n';
    int i = 0;
    // bool ans =checkKey(str,i,n,key);  it will return either 0 or 1
    vector<int>ans;
    checkKey(str,i,n,key,ans);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;

}