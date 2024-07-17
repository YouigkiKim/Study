#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
// done이라는 함수객체를 받아와서 논리값을 return해준다. -> 매 루프마다 done실행으로 조건검사한다.
void fill(std::vector<int>& v, T done){
    int i=0;
    while(!done()){
        v.push_back(i++);
        std::cout << v[i-1]<<" ";
    }
    std::cout << std::endl;
}
template<typename Iter>
void print(Iter begin, Iter end ){
    while(begin != end){
        std::cout<<"["<< *begin<<"] ";
        ++begin;
    }
    std::cout << std::endl;
}

int main(){

    int total_element = 1;
    std::vector<int> cardinal;
    cardinal.push_back(1);
    cardinal.push_back(4);
    cardinal.push_back(2);
    cardinal.push_back(4);
    cardinal.push_back(8);
    cardinal.push_back(4);
    
    for_each(cardinal.begin(), cardinal.end(), [&](int i) {total_element*= i;});
    std::cout<<total_element<<std::endl;

    std::vector<int> stuff;
    fill(stuff, [&]() -> bool{ return (stuff.size() >=8) ; } );
    
    print(cardinal.begin(), cardinal.end());
    auto result = std::find(cardinal.begin(), cardinal.end(),4);
    std::cout << "4의 위치 : "<< std::distance(cardinal.begin(), result)+1<<std::endl;


    std::cout <<"예제 2"<<std::endl;
    auto current = cardinal.begin();
    while(true){
        current = std::find(current, cardinal.end(),4);
        if(current == cardinal.end()) break;
        std::cout << "4의 위치 : "<< std::distance(cardinal.begin(), current)+1<<std::endl;
        current++;
    }

    std::cout << " 예제 3 나머지값을 만족하는 원소들" << std::endl;
    auto current2 = cardinal.begin();
    while(true){
        current2 = std::find_if(current2,cardinal.end(),[](int i){return i%3 ==1 ;});
        if(current2 == cardinal.end()) break;
        std::cout << "3으로 나눴을 때 나머지 1인 원소의 위치 : "<<std::distance(cardinal.begin(),current2)<<std::endl;
        current2++;
    }
}