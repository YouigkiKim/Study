#include <iostream>

int& func1(int& a){return a;}
int func2(int b){return b;}
class A{
    const char* a_;
    public:
    A(const char* a) : a_(a) { std::cout <<"char* 생성자"<<std::endl;}
    A(A& a) : a_(a.a_){
        std::cout << "복사생성자 호출"<<std::endl;
    }
    A(A&& a) : a_(a.a_){
        std::cout << "이동생성자 호출"<<std::endl;
        a.a_= nullptr;
    }

};
A func(A a){
    return a;
}
int main(){
    int a = 3;
    func1(a) = 4;
    std::cout << &func1(a) << std::endl;

    int b = 2;
    a = func2(b);
    // func2(b) = 5;                      Error C2106'=': left operand must be l-value
    // std::cout<< &func2(b)<<std::endl;  Error C2102'&' requires l-value

    int&&c = 3;
    std::cout << c<< std::endl;
    c = 4;
    std::cout << c<< std::endl;
    const char* dd = "abcdef";
    // for(int i=0;i<3;i++){
    //     dd[i] = 'a'+i;
    // }

    std::cout << dd<<std::endl;
    // for(int i=0;i<3;i++){
    //     dd[i] = 'a';
    // }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"여러 생성지"<<std::endl;
    A aa(dd);
    A bb(aa);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"강제로 임시객체 넣기"<<std::endl;
    A cc(func(A("asdfasd")));


}