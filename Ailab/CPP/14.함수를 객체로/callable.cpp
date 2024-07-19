#include <iostream>
#include <functional>
#include <string>

struct S{
    void operator()(char c){std::cout << "func2 = "<< c <<std::endl;}
};
/// callable ()을 통해 호출할 수 있는 모든것

int some_func1(const std::string& s){
    std::cout << "func1  "<< s <<std::endl;
    return 0;
}


class A{
    int c;

    public:
    A(int c) : c(c){}
    int some_func(){
        std::cout << "비상수 함수"<<++c <<std::endl;
        return c;
    }
    int some_const_function() const{
        std::cout << "상수 함수 "<<c << std::endl;
        return c;
    }

    static void st(){}
};
int main(){
    //std::function의 사용
    std::function<int(const std::string&)> f1   = some_func1;
    std::function<void(char)> f2                = S();
    std::function<void()> f3                    = [](){std::cout << "func3 호출 "<<std::endl;};

    f1("hello");
    f2('c');
    f3();

    //멤버함수의 funtion            멤버함수가 아닌 경우 주소값으로 암시적 변환이 일어나지만 멤벼함수에서는 일어나지 않아 명시적으로 &변환해줘야함
    std::function<int(A&)> mf1 = &A::some_func;
    std::function<int(const A&)> mf2 = &A::some_const_function;
    A a(5);
    mf2(a);
    
    mf1(a);

}