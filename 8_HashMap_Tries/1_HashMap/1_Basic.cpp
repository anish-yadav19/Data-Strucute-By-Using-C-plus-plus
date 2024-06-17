#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    //creation
    unordered_map<string,int>mpp;

    //insertion
    pair<string,int>p=make_pair("Scorpio",9);
    mpp.insert(p);

    pair<string,int>p2("alto",2);
    mpp.insert(p2);

    mpp["fortuner"] = 10;
    
    cout<<mpp.at("alto")<<endl;

    cout<<mpp["fortuner"]<<endl;
    
    //searching
    cout<<mpp.count("Scorpio")<<endl;

    if(mpp.find("fortuner")!=mpp.end())
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }

    cout<<mpp.size()<<endl;

    cout<<"printing all entries: "<<endl;
    for(auto i: mpp)
    {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    return 0;
}