#include <iostream>
#include <stdexcept>

template<typename T>
class Vector{
    public:
    Vector(size_t size) : size_(size){
        data_ = new T[size_];
        for(int i =0;i<size_;i++){
            data_[i] = 3;
        }
    }
    //throw를 통한 index예외처리
    const T& at(size_t index) const{
        if(index >= size_){
            throw std::out_of_range("vector의 index가 범위초과");
        }
        return data_[index];
    }
    ~Vector() {delete[] data_;}


    private:
    T* data_;
    size_t size_;
};


//stack rewinding 

class Resource{
    public:
    Resource(int id) : id_(id){}
    ~Resource(){std::cout << "리소스 해제"<<id_<<std::endl;}
    private:
    int id_;
};
int func3(){
    Resource r(3);
    return 0;
    // throw std::runtime_error("Exception from 3!\n");
}
int func2(){
    Resource r(2);
    func3();
    std::cout << "실행2"<< std::endl;
    return 0;
}
int func1(){
    Resource r(1);
    func2();
    std::cout << "실행1"<<std::endl;
    return 0;
}

int main(){
    Vector<int> vec(3);
    int index, data = 0;
    //오류가 발생할만한 부분에 try catch를 구성해 예외처리한다
    std::cin >> index;
    try{
        data = vec.at(index);
    } catch(std::out_of_range& e){ // catch인 이유 >> throw된 오류를 catch하기 때문
        std::cout << "예외 발생 !"<<e.what() << std::endl;
    }
    std::cout << "읽은 데이터 : "<<data<<std::endl;



    std::cout<<std::endl;
    std::cout<<std::endl;
    try{
        func1();
    }catch(std::exception& e){
        std::cout << "Exception : "<<e.what();
    }
}