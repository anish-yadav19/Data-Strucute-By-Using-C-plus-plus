#include<iostream>
#include<stack>
using namespace std;

void printMiddle(stack<int>&s, int &totalSize)
{
    if(s.size() == totalSize/2+1)
    {
        cout<<"Middle element is: "<< s.top()<<endl;
        return;
    }
    int temp = s.top();
    s.pop();

    
    printMiddle(s,totalSize);
}
int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
     
    int Size = st.size();
    printMiddle(st,Size);
    

    return 0;
}