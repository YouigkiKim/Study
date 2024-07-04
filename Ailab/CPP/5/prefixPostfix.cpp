#include<iostream>

class Test{
    int x;

    public:
    Test(int x) : x(x){}
    Test(const Test& t) : x(t.x){}
    //전위 연산자
    Test& operator++(){
        x++;
        std::cout<<"전위 증감 연산자"<<x<<std::endl;
        return *this;
    }
    //후위 연산자
    Test operator++(int){
        //이전 객체를 복사한 다음 x를 늘리고 이전 객체를 반환함
        Test temp(*this);
        x++;
        std::cout<<"후위 증감 연산자"<<std::endl;
        return temp;
    }
    int get_x()const{return x;}
};
void func(Test x){
    std::cout<<"x: "<<x.get_x()<<std::endl;
}
int main(){
    Test a(1);
    func(++a); // 증가한 채로 함수실행
    func(a++); // 함수실행 후 증가
    std::cout<< "최종 x: "<<a.get_x()<<std::endl;
    return 0;
}