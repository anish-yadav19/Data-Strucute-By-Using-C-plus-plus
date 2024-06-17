#include<iostream>
using namespace std;

class Animal
{
    public:
    //state or properties
    int age;
    string name;


    // method or behaviour
    void ear()
    {
        cout<<"dog is eating"<<endl;
    }


    void sleep()
    {
        cout<<"dog is sleeping"<<endl;
    }

};

int main()
{
    // size of empty class is 1 Byte
    // cout<<"size of Empty class is: "<<sizeof(Animal)<<endl;

    // object creation

    // by static allocation
    Animal dog;
    dog.age = 12;
    dog.name = "Labador";
    cout<<"The age of dog is: "<<dog.age<<endl;
    cout<<"The age of dog is: "<<dog.name<<endl;
    dog.ear();
    dog.sleep();


    return 0;
}