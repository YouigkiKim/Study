#include <iostream>
#include <memory>
#include <vector>
#include <string>
//weakPtr -> 참조 개수를 늘리지 않는 스마트포인터 유니크와 쉐어드 사이의 포인터

//트리구조의 노드 children은 포인터벡터, parent는 weakPtr
class Node {
    std::vector<std::shared_ptr<Node>> children;
    std::weak_ptr<Node> parent;
    public:
    Node(){};
    void AddChild(std::shared_ptr<Node> node){children.push_back(node);}
};

class A{
    std::string s;
    std::weak_ptr<A> other;

    public:
    A(const std::string& s): s(s) {std::cout << "자원을 획득함"<<std::endl;}
    ~A(){std::cout << "소멸자 호출"<<std::endl;}

    void set_other(std::weak_ptr<A> o){other = o;}
    void access_other(){
        std::shared_ptr<A> o  =other.lock();
        if(o){
            std::cout << "access : "<< o-> name()<<std::endl;
        }else{
            std::cout << "이미 삭제됨"<<std::endl;
        }
    }
    std::string name(){return s;}
};

int main(){
    std::vector<std::shared_ptr<A>> vec;
    vec.push_back(std::make_shared<A>(
        "자원 1")
    );
    vec.push_back(std::make_shared<A>(
        "자원 2")
    );

    vec[0] -> set_other(vec[1]);
    vec[1] -> set_other(vec[0]); // 서로 주소값을 weakptr로 설정
    std::cout << "vec[o] : "<<vec[0].use_count()<<std::endl;
    std::cout << "vec[1] : "<<vec[1].use_count()<<std::endl; // count는 늘지 않음


    vec[0] -> access_other(); // other로 vec[0]이 설정되어있음 .lock()을 통해 shared로 변환 weakptr은 그 자체로 원소참조 불가능
    vec.pop_back(); // vec[1]빼냄
    vec[0] -> access_other(); // 접근하는 vec[1]객체가 없음
    /*
    weakpointer의 개수 또한 제어블록에 기록됨 >> weakPtr이 가르킬 때 객체를 소멸시키지 않기 위해서 
    */
}