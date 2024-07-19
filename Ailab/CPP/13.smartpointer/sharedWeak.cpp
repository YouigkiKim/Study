#include <iostream>
#include <memory>
#include <vector>

//shared_ptr
//여러개의 스마트 포인터가 하나의 객체를 가르킬 수 있다

class A : public std::enable_shared_from_this<A>{
    int *data;
    public:
    A(){
        data = new int[100];
        std::cout << "자원을 획득함"<<std::endl;
    }
    ~A(){
        std::cout << "소멸자 호출!"<<std::endl;
        delete[] data;
    }
    //자기 자신을 가르키는 sharedptr 생성할 때 shared_from_this사용
    //해당 객체의 제어블록을 확인만 한다 >> 이미 한개 이상 생성되어있어야함
    std::shared_ptr<A> get_shared_ptr() {return shared_from_this();}

};


int main(){
    std::vector<std::shared_ptr<A>> vec;
    vec.push_back(std::shared_ptr<A>(new A()));
    vec.push_back(std::shared_ptr<A>(vec[0]));
    vec.push_back(std::shared_ptr<A>(vec[1]));

    std::cout <<"첫번째 원소 소멸"<<std::endl;
    vec.erase(vec.begin());
    std::cout <<"두번째 원소 소멸"<<std::endl;
    vec.erase(vec.begin());
    std::cout <<"세번째 원소 소멸"<<std::endl;
    vec.erase(vec.begin());
    std::cout << "프로그램 종료"<<std::endl;


    //제어블록까지 동적할당 두 번 필요 >> make_shared는 두 동적할당을 합쳐 한번에 수행함
    //주의사항 shared_ptr<T> ptr(*ptr)형식으로 입력인자를 전달하면 제어블록을 새로 생성함 >> 주소값으로 생성하는 것 지양
    //이러한 방식으로 2개의 sharedptr을만들면 같은 주소값에 대해 제어블록이 2개
    std::shared_ptr<A> p1 = std::make_shared<A>();
    std::shared_ptr<A> p2(p1);
    std::cout << p1.use_count()<<std::endl;
    std::cout << p1.use_count()<<std::endl;

    
    //객체 내부에서 자신을 가르킬 때 >>sharedptr에 주소값 전달해ㅑ됨
    //std::enable_shared_from_this상속받기
}
