#include <iostream>
#include <memory>
#include <vector>

class A{
    int *data;
    public:
    A(){
        std::cout << "자원을 획득함!"<<std::endl;
        data = new int[100];
    }
    A(int a) {data = new int[a];
    std::cout << " 자원을 획득함! int input "<<std::endl;}
    void some() {std::cout << "일반 포인터와 동일하게 사용 가능"<<std::endl;}
    ~A(){
        std::cout << "자원 해제"<<std::endl;
        delete[] data;
    }
    void do_sth(int a){
        std::cout <<"무언가 한다"<<std::endl;
        data[0] = a;
    }
};

void do_something(){
    std::unique_ptr<A> pa(new A());
    pa ->some();
    //unique_ptr의 소멸자 호출
    //RAII패턴 준수
    // std::unique_ptr<A> pa = pb; -> 오류발생 복사생성지 = delete; 해놓음
    std::unique_ptr<A> pb = std::move(pa);
    pa-> some();
}
//포인터의유일한 소유권을 do_something도 가질 수 있게됨 -> 올바른 포인터 전달방법이 아님
void do_something(std::unique_ptr<A>& ptr){
    ptr -> do_sth(3);
}//올바른 방법 -> do_something(pa.get);
void do_something(A* ptr){
    ptr -> do_sth(3);
}

//unique)ptr을 원소로 가지는 컨테이너
int main(){
    do_something();
    std::unique_ptr<A> pc(new A());
    do_something(pc);
    do_something(pc.get());
    

    //smart pointer STL
    std::vector<std::unique_ptr<A>> vec;
    vec.push_back(std::move(pc));
    std::cout << " 스마트포인터 컨테이너 : "<<  std::endl;
    do_something(vec[0]);
    std::cout <<std::endl;
    std::cout << "emplace_back을 활용한 vector내부 unique_ptr생성"<<std::endl;
    std::vector<std::unique_ptr<A>> vec2;
    vec2.emplace_back(new A(1)); // A스마트포인터가 형성되면서 vec2[0]에 저장
    vec2.back() -> some();
    std::cout << "vec2의 원소개수 : "<<vec2.size() <<std::endl;
}