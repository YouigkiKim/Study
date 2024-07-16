#include <iostream>
#include <map>
#include <string>


template < typename K, typename V>
//map은 keytype과 valuetype 두가지 타입을 가지고있음 > template의 원소를 두개
void print_map(std::map<K,V>& m){
    for(auto itr = m.begin();itr != m.end();++itr){
        std::cout << itr -> first << " "<< itr -> second << std::endl;
    }
}

int main(){
    std::map<std::string, double> pitcher_list;
    //std::pair의 정의
    // template <class T1, class T2>
    // struct std::pair {
    // T1 first;                -> key
    // T2 second;               -> value
    // };
    pitcher_list.insert(std::pair<std::string,double>("박세웅",2.33));
    pitcher_list.insert(std::pair<std::string,double>("해커", 2.93));
    pitcher_list.insert(std::pair<std::string,double>("피어밴드",2.95));
    //위처럼 정의하기 귀찮아서 make_pair제공
    pitcher_list.insert(std::make_pair("차우찬",3.04));
    pitcher_list.insert(std::make_pair("장원준",3.05));
    pitcher_list.insert(std::make_pair("핵터",3.09));
    //map객체 안에서 연산자오버로딩가능
    pitcher_list["니퍼트"] = 3.56;
    pitcher_list["박종훈"] = 3.76;
    pitcher_list["켈리"] = 3.90;
    print_map(pitcher_list);
    //류현진은 등록이 안돼있어도 출력이 된다 >> operator[]는 없는 double값을 default생성자로 0 으로 초기화
    std::cout << "류현진의 방어율 : "<<pitcher_list["류현진"]<<std::endl;

    std::map<std::string, double>::iterator itr = pitcher_list.find("김영기");
    //map.end()는 맵의 범위르 벗어난 가상의 위치를 나타냄
    if(itr != pitcher_list.end()){
        std::cout << "김영기의 방어율 : " << pitcher_list["김영기"]<<std::endl;
    }else{
        std::cout << "김영기는 목록에 없습니다 " <<std::endl;
    }

    
}