#include <iostream>

class A{
    public:
    A(){std::cout << "ctor\n";}
    A(const A& a) {std::cout <<"copy ctor\n";}
    A(A&& a) {std::cout << "move ctor\n";}
};

class B{
    public:
    A a_;
    B(A&& a) :a_(std::move(a)){}
};

int main(){
    A a;
    B b(std::move(a));
    // B b(a);
}