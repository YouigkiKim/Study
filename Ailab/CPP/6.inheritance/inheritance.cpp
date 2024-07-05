#include <iostream>

class Base{

    std::string s;
    protected:
    std::string parent_string;

    public:
    Base() : s("기반"){std::cout << "기반 클래스 "<<std::endl;
    }
    void what(){std::cout<<s<<std::endl;}
};

//base를 public형식으로 상속받겠다
class Derived : public Base{
    std::string s;

    public:
        //생성자의 경우 기반을 먼저 처리한 후 derived를 처리해야함
        Derived() : Base(), s("파생"){
            std::cout << "파생 클래스 "<< std::endl;
            parent_string = "바꾸기";
            what();
            
        }
        void what(){std::cout<<s<<parent_string<<std::endl;}
};


int main(){
    std::cout << "===기반 클래스 생성"<<std::endl;
    Base p;

    std::cout <<"=====Drived class created"<<std::endl;
    Derived c;

}