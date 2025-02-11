#include<bits/stdc++.h>
using namespace std;

vector<string>ans;

void call(string str, int index, string temp)
{
    if(temp.size() == str.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i= 0;i<str.size();i++)
    {
        temp.push_back(str[i]);
        call(str,index,temp);
        temp.pop_back();
    }
    return ;
}
int main()
{
    string str;
    cin>>str;
    sort(str.begin(), str.end());
    string temp = "";
    call(str, 0, temp);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    return 0;
}