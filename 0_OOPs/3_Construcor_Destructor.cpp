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



    // construcor
    Animal()
    {
         cout<<"Constructor is called"<<endl;
        this->weight;
        this->age = 0;
        this->name = "";
    }

    // parameterized constructor
    Animal(int age , string name)
    {
        this->age = age;
        this->name = name;
        cout<<"Parameterized constructor is called"<<endl;
    }

    // copy constructor
    Animal(Animal &obj)
    {
        this->age = obj.age;
        this->name = obj.name;
        cout<<" I am inside copy constructor"<<endl;
    }


    // method or behaviour
    void ear()
    {
        cout<<"dog is eating"<<endl;
    }


    void sleep()
    {
        cout<<"dog is sleeping"<<endl;
    }
    ~Animal()
    {
        cout<<" I am inside destructor"<<endl;
    }

};

int main()
{
    

    // object creation

    // by static allocation
    // Animal dog;
    // Animal dog(10,"Labror");

    

    // dynamic array

    // Animal* dog1 = new Animal;

    /*

    // copy constructor

    Animal dog3 = dog;
    Animal* dog1 = new Animal(20,"Labror");

    Animal dog2(dog3); // copy constructor

    */
    Animal dog;
    dog.age = 56;
    Animal* dog1 = new Animal;
    dog1->age = 12;
    delete dog1;





    return 0;
}