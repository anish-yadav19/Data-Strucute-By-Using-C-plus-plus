#include<iostream>
using namespace std;

class Animal
{
    private:
    int weight;

    public:
    //state or properties
    int age;
    string name;


    // method or behaviour
    void eat()
    {
        cout<<"dog is eating"<<endl;
    }


    void sleep()
    {
        cout<<"dog is sleeping"<<endl;
    }

    int getWeight()
    {
        return weight;
    }

    void setWeight(int w)
    {
        weight = w;
    }

};

// getter and setter is used to access the private data members 
int main()
{
    // size of empty class is 1 Byte
    // cout<<"size of Empty class is: "<<sizeof(Animal)<<endl;

    // object creation

    // by static allocation
    /*
    Animal dog;
    dog.age = 12;
    dog.name = "Labador";
    cout<<"The age of dog is: "<<dog.age<<endl;
    cout<<"The age of dog is: "<<dog.name<<endl;

    // cout<<dog.weight<<endl;
    dog.ear();
    dog.sleep();

    dog.setWeight(5);
    cout<<"Weight: "<<dog.getWeight()<<endl;

    */



    // dynamically object creation
     Animal* dog = new Animal;
     dog->age = 15;
     dog->name = "Desi";

     dog->sleep();
     dog->eat();

    return 0;
}