#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{

    string str = "thiruvananthapuram";
    unordered_map<char,int>mpp;

    for(int i = 0;i<str.length();i++)
    {
        char ch = str[i];
        mpp[ch]++;
    }

    for(auto i:mpp)
    {
        cout<<i.first <<" -> "<<i.second<<endl;
    }

    return 0;
}