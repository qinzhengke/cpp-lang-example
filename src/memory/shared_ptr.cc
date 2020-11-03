#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class Base{
public:
    int x;
    Base(int x = 0){
        this->x = x;
    }
    ~Base(){
        cout<<"~Base(), x:"<<x<<endl;
    }
    void f(){
        cout<<"This is Base::f()"<<endl;
    }
    virtual void g(){
        cout<<"Base::g()"<<endl;
    }
};

class Derived : public Base{
public:
    Derived(int x = 0) : Base(x){ }
    ~Derived(){
        cout<<"~Derived(),x:"<<x<<endl;
    }
    void g() override{
        cout<<"Derived::g()"<<endl;
    }
};

int main(int argc, char ** argv){

    // Initialization with a raw pointer.
    shared_ptr<Base> pa(new Base(0));

    // Assignment with make_shared. The parameters in () are for the constructor.
    // The last pointed object will execute deconstructor automatically.
    pa = make_shared<Base>(1);

    // Initialization with make_shared and auto type.
    auto pb = make_shared<Base>(2);

    // Assignment by another shared_ptr.
    pb = pa;

    // Access raw pointer.
    cout<<"raw pointer:"<<pa.get()<<endl;

    // Access member variable.
    cout<<"Base.x="<<pa->x<<endl;

    // Access memeber function.
    pa->f();

    // shared_ptr with containter
    vector<shared_ptr<Base>> list;
    list.push_back(make_shared<Base>(3));
    list.push_back(make_shared<Base>(4));
    list.push_back(make_shared<Base>(5));

    // The memory pointed by the poped shared pointer will be release
    // automatically.
    list.pop_back();

    // shared_ptr with polymorphism
    shared_ptr<Derived> pc = make_shared<Derived>(6);
    shared_ptr<Base> pd = dynamic_pointer_cast<Base>(pc);
    pd->g();

    cout<<"End of main"<<endl;
}