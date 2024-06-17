#include<iostream>
using namespace std;

class Car{

    public:
    string name;
    int weight;
    int age;

    void speedUp()
    {
        cout<<"Speeding Up"<<endl;
    }
    void breakMarro()
    {
        cout<<"break Maro"<<endl;
    }
};

// single inheritence
class Scorpio:public Car{
    
};


// Multilevel inheritence
class Fortuner:public Scorpio{

};


// Multiple inheritence
class A{
    public:
    // int physics;
    // abiguity in multiple inheritence if both class has same member

    int chemistry;
    A(){
        this->chemistry = 101;
    }

    /*
    request for member 'chemistry' is ambiguous
    5_types_of_inheritence.cpp:45:9: note: candidates are: int B::chemistry
     int chemistry;
         ^~~~~~~~~
5_types_of_inheritence.cpp:39:9: note:                 int A::chemistry
     int chemistry;
         ^~~~~~~~~
    */

   // solution for this problem is use scope resolution operator(::) 


};
class B{
    public:
    int chemistry;
    B(){
        this->chemistry = 403;
    }
};

class C:public A, public B{
    public:
    int maths;
};

int main()
{
    /* // single level object
    Scorpio obj;
    obj.speedUp();
    */

   /*
   // Multi level object
    Fortuner obj;
    obj.breakMarro();
    */

   // Multiple inheritenc object

   C obj;
//    cout<<obj.physics<<" "<<obj.chemistry<<" "<<obj.maths<<endl;

// solution of ambiguity

    cout<<obj.A::chemistry<<" "<<obj.B::chemistry<<" "<<obj.maths<<endl;


    return 0;
}