#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using std::vector;


void add(int a, int b){ std::cout << a<<"+"<<b <<"= "<<a+b << std::endl;}
void subtract(int a, int b){ std::cout << a<<"-"<<b <<"= "<<a-b << std::endl;}

struct S{
    int data;
    S(int data) : data(data){std::cout << "생성자 호출"<<std::endl;}
    S(const S& s) : data(s.data){std::cout <<"복사 생성자 호출"<<std::endl;}
    S(S&& s) {
        data =  std::move(s.data);
        std::cout << "이동 생성자 호출 "<<std::endl;
    }
};

void do_something(S& s1, const S& s2) { s1.data = s2.data + 3; }

int main(){
    vector<int> a(1);
    vector<int> b(2);
    vector<int> c(3);
    vector<int> d(4);
    vector<int> e(5);

    vector<vector<int>> container;
    container.push_back(b);
    container.push_back(d);
    container.push_back(c);
    container.push_back(e);

    vector<int> size_vec(4);
    // 오류발생 >> 함수가들어가야하는 부분에 멤버함수가 들어가면 -> () ro .()형태로 호출해야함 std;:function이용해서 함수형태로 바꾸고 입력해주면됨
    // std::transform(container.begin(), container.end(), size_vec.begin(), &vector<int>::size);

    std::function<size_t(const vector<int>&)> sz_func = &vector<int>::size;
    std::transform(container.begin(), container.end(), size_vec.begin(), sz_func);

    std::cout << "std::function fucntion "<<std::endl;
    for(auto itr = size_vec.begin();itr != size_vec.end(); ++itr){
        std::cout << "벡터 크기 :"<< *itr << std::endl;
    }
    //memberfunciton을 바로 함수객체로 만들어주는 std::mem_fn(&class::function)
    std::transform(container.begin(), container.end(), size_vec.begin(), std::mem_fn(&vector<int>::size));
    std::cout << "std::mem_fn fucntion "<<std::endl;
    for(auto itr = size_vec.begin();itr != size_vec.end(); ++itr){
        std::cout << "벡터 크기 :"<< *itr << std::endl;
    }
    std::transform(container.begin(), container.end(), size_vec.begin(), [](const vector<int>& vec){return vec.size();});
    std::cout << "lambda fucntion "<<std::endl;
    for(auto itr = size_vec.begin();itr != size_vec.end(); ++itr){
        std::cout << "벡터 크기 :"<< *itr << std::endl;
    }


    //bind -> 함수의 인자가 고정된 함수 만들어준다.

    auto add_with_2 = std::bind(add,2,std::placeholders::_1);
    auto subtract_from_2 = std::bind(subtract,std::placeholders::_1,2);
    std::cout << "bind"<<std::endl;
    add_with_2(1);
    subtract_from_2(3);
    auto negate = std::bind(subtract,std::placeholders::_2,std::placeholders::_1);
    negate(4,2);
    //레퍼런스를 함수의 인자로 받을 때 bind

    S s1(1), s2(2);

    std::cout << "Before : " << s1.data << std::endl;

    auto do_something_with_s11 = std::bind(do_something, s1, std::placeholders::_1);
    std::cout << "객체를 바로 전달할 때 (객체를 복사해서 전달하기 때문에 객체데이터가 변하지 않음n) "<<std::endl;
    do_something_with_s11(s2);
    std::cout << "After :: "<<s1.data<<std::endl;
    // s1 이 그대로 전달된 것이 아니라 s1 의 복사본이 전달됨!
    std::cout << "객체를 레퍼런스로 전달할 때 std::ref(class)"<<std::endl;
    auto do_something_with_s1 =
    //std::ref(s1)을 통해 명시적으로 레퍼런스로 s1을 전달함
    std::bind(do_something, std::ref(s1), std::placeholders::_1);
    do_something_with_s1(s2);
 
    std::cout << "After :: " << s1.data << std::endl;
}