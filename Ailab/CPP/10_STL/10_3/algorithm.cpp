#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

template <typename Iter>
void print(Iter begin, Iter end){
    while (begin != end){
        std::cout << *begin << " ";
        begin ++;
    }
    std::cout << std::endl;
}
//함수개겣 생성 functor
struct int_compare{
    bool operator()(const int& a, const int& b){
        return a>b;
    }
};
template <typename T>
struct greater_comp{
    bool operator()(const T& a, const T& b){return a>b;}
};
struct User{
    std::string name;
    int age;

    User(std::string name, int age): name(name),age(age){};
    bool operator<(const User& a) const {return age< a.age;}
};
std::ostream& operator<<(std::ostream& o, const User& u){
    o<<u.name<<", " << u.age;
    return o;
}
struct is_odd{
    bool operator()(const int& i){ return i%2 == 1;}
};
int main(){
    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(7);
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(1);
    std::vector<int> vec2 = vec;    
    std::cout << "정렬 전 -----"<<std::endl;
    print(vec.begin(),vec.end());
    //randomaccessIterator반복자만 가능함 >> deque와 vector만 가능
    std::sort(vec.begin(), vec.end());
    std::cout << "정렬 후 -----"<<std::endl;
    print(vec.begin(), vec.end());

    auto vec3 = vec2;
    auto vec4 = vec3;
    auto vec5 = vec4;
    // 역순으로 정렬하고 싶을 떄
    std::cout << "내림차순 정렬 -----"<<std::endl;
    std::sort(vec2.begin(),vec2.end(),int_compare());
    print(vec2.begin(),vec2.end());
    std::cout << "template사용 정렬 -----"<<std::endl;
    std::sort(vec3.begin(),vec3.end(), greater_comp<int>());
    print(vec3.begin(),vec3.end());
    /*
    partial sort
    */
    std::cout<<"정렬전 ----"<<std::endl;
    print(vec4.begin(),vec4.end());
    std::cout<<"5번째까지 정렬"<<std::endl;
    std::partial_sort(vec4.begin(),vec4.begin()+5,vec4.end());
    print(vec4.begin(),vec4.end());
    /*
    stable sort
        */
    std::vector<User> vecu;
    for(int i=0;i<100;i++){
    std::string name = "";
        name.push_back('a'+i/26);
        name.push_back('a'+i&26);
        vecu.push_back(User(name,static_cast<int>(rand()%10)));
    }
    std::vector<User> vecu2 = vecu;
    std::cout << "before stable sort "<< std::endl;
    print(vecu.begin(),vecu.end());
    std::cout << "after sort"<<std::endl;
    std::sort(vecu.begin(),vecu.end());
    print(vecu.begin(), vecu.end());
    std::cout<<"after stabel sort"<<std::endl;
    std::stable_sort(vecu2.begin(),vecu2.end());
    print(vecu2.begin(),vecu2.end());

    // remove erase -> remove는 원소를 뒤로 이동, erase는 지우기 실행
    std::cout << "remove, erase 원래 벡터 "<<std::endl;
    vec5.push_back(3);
    vec5.push_back(3);
    vec5.push_back(3);
    auto vec6 = vec5;
    print(vec5.begin(),vec5.end());
    //remove는 해당 숫자를 마지막으로 옮기고 반복자 리턴 -> erase의 첫번째 인자로 사용
    vec5.erase(std::remove(vec5.begin(),vec5.end(),3),vec5.end());
    print(vec5.begin(),vec5.end());
    std::cout << "원래 벡터(remove if 이전 ) "<<std::endl;
    print(vec6.begin(),vec6.end());
    std::cout << "remove_if(시작, 끝, 조건functor)"<<std::endl;
    vec6.erase(remove_if(vec6.begin(),vec6.end(),is_odd()) ,vec6.end());
    print(vec6.begin(),vec6.end());

    
    return 0;
}
