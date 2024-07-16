#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T>
void print_vector(std::vector<T>& vec){
    for(typename std::vector<T>::iterator itr = vec.begin();itr != vec.end();itr++){
        std::cout<< *itr <<std::endl;
    }
}

//범위기반 for문
template <typename T>
void print_vector_rbl(std::vector<T>& vec){
    //auto, T
    for(const T& elem  : vec){
        std::cout<< elem <<std::endl;
    }
}


template <typename T>
void const print_list(std::list<T>& lst){
    std::cout<<"[";
    for(typename std::list<T>::iterator itr =lst.begin();itr != lst.end();++itr){
        std::cout << *itr<< " ";
    }
    std::cout << "]"<<std::endl;
}

template<typename T>
void const print_deque(std::deque<T>& dq){
    std::cout<< "[";
    for( T&  elem : dq){
        std::cout << elem << " ";
    }
    std::cout<< "]"<<std::endl;

}
int main(){
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    vec.push_back(70);
    vec.push_back(80);
    for(std::vector<int>::size_type i=0;i<vec.size();i++){
        std::cout << "vec으ㅣ "<< i+1<<"번째 원소 :: "<< vec[i]<<std::endl;
    }
    std::cout<<std::endl;
    print_vector(vec);
    std::cout<<std::endl;
    std::cout << "range based for loop"<<std::endl;
    print_vector_rbl(vec);
    std::cout<<std::endl;

    // 밑의 코드는 iterator의 의존성문제로 오류발생 
    // std::vector<int>::iterator itr = vec.begin();
    // for(;itr != vec.end();++itr){
    //     vec.erase(itr);
    //     itr = vec.begin();
    // }
    //수정된 코드 반복자 사용 x
    std::cout<<"erase 20"<<std::endl;
    for(std::vector<int>::size_type i = 0;i != vec.size();i++){
        if(vec[i] ==20){
            // erase의 입력인자 -> 반복자 -> vec.begin()으로 할당받음
            vec.erase(vec.begin() +i);
            i--;
        }
    }


    //역반복자 -> begin, end와 호환안됨 rbegin과 rend와 호환됨
    std::cout<<"reverse iterator"<<std::endl;
    std::vector<int>::reverse_iterator r_iter = vec.rbegin(); // rbegin은 벡터의 가장 마지막을 가르킨다
    for(;r_iter != vec.rend();r_iter++){
        std::cout << *r_iter<<std::endl;
    }

    /*
    


    list example


    
    */

    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"list example" <<std::endl;

    //리스트는 특정위치에 접근불가 begin, end의 반복자의 ++,--를 통해서만 접근가능
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    //반복자에 전위합을 사용하는 이유 >> 불필요한 객체의 복사를 방지할 수 있다.
    // 결과는 똑같기 때문에 전위합을 사용하는 것이 옳다

    for(std::list<int>::iterator itr = lst.begin();itr!= lst.end();++itr){
        std::cout << *itr <<" ";
    }
    std::cout<<std::endl;
    //erase이용해 특정 값 지우기
    for(std::list<int>::iterator itr = lst.begin();itr != lst.end();++itr){
        if(*itr == 30){
            lst.erase(itr);
            std::cout << "30 삭제 "<<std::endl;
            print_list(lst);
            break;
        }
    }



    /*
    


    deque example
    


    */
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"deque example";
    std::cout<<std::endl;

    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);
    print_deque(dq);
    
    return 0;
}