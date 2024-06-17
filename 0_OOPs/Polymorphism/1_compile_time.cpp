#include<iostream>
using namespace std;

/*

// function overloading
 
class Maths
{
    public:
    
    int sum(int a,int b)
    {
        cout<<"I am the first signature"<<endl;
        return a+b;
    }
    int sum(int a,int b,int c)
    {
        cout<<"I am the second signature"<<endl;
        return a+b+c;
    }
    int sum(int a,float b)
    {
        cout<<"I am the third signature"<<endl;
        return a+b;
    }
};



int main()
{
    Maths obj;
    cout<<obj.sum(5,7);
    return 0;
}

*/


class Param
{
    public:
    int val;

    void operator +(Param& obj2)
    {
        int value1 = this->val;
        int value2 = obj2.val;

        cout<<(value2 - value1)<<endl;
    }

};

int main()
{
    Param obj1,obj2;
    obj1.val = 7;
    obj2.val = 2;

    // this should print the differenc between them

    obj1+obj2;

    return 0;
    
}