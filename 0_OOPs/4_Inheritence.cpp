#include<iostream>
using namespace std;

class Animal
{

/*
    private:
    int age ;
    int weight;

    */
    /*
    public:
    int age ;
    int weight;

    */

    // void eat()
    // {
    //     cout<<"Eating"<<endl;
    // }
};
/*
class Dog:public Animal
{
    public:
    void print()
    {
        cout<<this->age;
    }
};

*/
/*
error: 'int Animal::age' is private within this context
         cout<<this->age;
                     ^~~
4_Inheritence.cpp:8:9: note: declared private here
     int age ;
*/

/*
class Dog:public Animal
{

};




class Dog:protected Animal
{
    public:
    void print()
    {
        cout<<this->age;
    }
    
};

/*
class Dog:private Animal
{
    public:
    void print()
    {
        cout<<this->age;
    }
    
};



int main()
{
    Dog d1;
    // d1.eat();
    //  cout<<d1.age; // we can not access private data members from outside of class
    // same for private data members
    d1.print();
    return 0;
}
*/

