#include <iostream>

template < typename T>
//보편적 레퍼런스로 받음
//템플릿 타입의 우측값 레퍼런스 -> 보편적 레퍼런스 -> 좌측값도 받을 수 있음
void wrapper(T&& u){
    g(std::forward<T>(u));
}


class A{};

void g(A& a){std::cout <<"left ref called"<<std::endl;}
void g(const A& a){ std::cout << "left const ref called"<<std::endl;}
void g(A&& a){ std::cout << "right ref called"<<std::endl;}

int main(){
    A a;
    const A ca;
    std::cout << "원본 -----"<<std::endl;
    g(a);
    g(ca);
    g(A());

    std::cout << "wrapper -=-==="<<std::endl;
    wrapper(a);
    wrapper(ca);
    wrapper(A());
}