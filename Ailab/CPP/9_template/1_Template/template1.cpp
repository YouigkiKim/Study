#include <iostream>
#include <string>

template <typename T>
class Vector{
    T* data;
    int capacity;
    int length;

    public:
    Vector(int n=1) : data(new T[n]), capacity(n), length(0) {}

    void push_back(T s){
        if(capacity <= length ){
            T* temp = new T[capacity*2];
            for(int i=0;i<length;i++){
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *=2;
        }

        data[length] = s;
        length++;
    }

    T operator[](int i) {return data[i];}

    void remove(int x){
        for(int i=x+1;i<length;i++){
            data[i-1] = data[i];
        }
        length--;
    }

    int size(){ return length; }

    void swap(int i, int j ){
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    ~Vector(){
        if(data){
            delete[] data;
        }
    }
};

// template specilization

template<>
class Vector<bool>{

    unsigned int* data;
    int capacity;
    int length;

    public:
    typedef bool value_type;

    Vector(int n=1)  : data(new unsigned int[n/32+1]), capacity(n/32+1),length(0){
        for(int i=0;i<capacity;i++){
            data[i] = 0;
        }
    }

    void push_back(bool s){
        if(capacity <= length){
            unsigned int* temp = new unsigned int[capacity *2];
            for(int i=0;i<capacity;i++){
                temp[i] = data[i];
            }
            for(int i=capacity; i<2*capacity; i++){
                temp[i] = 0;
            }
            delete[] data;
            data = temp;
            capacity *=2;
        }
        if(s){
            data[length/32] |= (1<<(length %32));
        }
        length ++;
    }

    bool operator[](int i) { return (data[i/32] & (1<<(i%32)))!=0; }

    void remove(int x){
        for(int i=x+1;i<length;i++){
            int prev = i-1;
            int curr = i;

            if( data[curr/32] & ( 1 << (curr%32) )){
                data[prev/32] |= (1 << (prev % 32));
            }else {
                unsigned int all_ones_except_prev = 0xFFFFFFFF;
                all_ones_except_prev ^= ( 1<< (prev%32));
                data[prev/32] &= all_ones_except_prev;
            }
        }
        length--;
    }

    int size(){ return length;}
    ~Vector(){
        if(data){ delete[] data;}
    }
};


template < typename Cont>
void bubble_sort(Cont& cont ){
    for(int i=0;i<cont.size();i++){
        for(int j=i+1;j<cont.size();j++){
            //객체함수의 도입
            if(cont[i]>cont[j]){
                cont.swap(i,j);
            }
        }
    }
}
template < typename Cont, typename Comp>
void bubble_sort(Cont& cont , Comp& comp){
    for(int i=0;i<cont.size();i++){
        for(int j=i+1;j<cont.size();j++){
            //객체함수의 도입
            if(!comp(cont[i],cont[j])){
                cont.swap(i,j);
            }
        }
    }
}

//객체함수 - 함수인 척을 하는 객체
//com1, com2에는 ()연산자가 오버로딩되어있다. Comp객체를 템플릿변수로 받아오게되면 ()가 오버로드된다
//()안에 두 변수가 들어가기 때문에 함수의 형태를 띄고있으며 이를 Functor라고한다
struct Comp1{
    //()오버로딩을 통해 함수의 사용법과 비슷해진 객체를 가짐.
    bool operator()(int a, int b){ return a>b;}
};
struct Comp2{
    bool operator()(int a, int b){ return a<b;}
};




int main(){
    //템플릿 실습
    Vector<std::string> str_vec;
    str_vec.push_back("youngki");
    str_vec.push_back("samacheon F");
    std::cout << str_vec[0]<<"  "<<str_vec[1]<<std::endl;
    //템플릿 클래스 실습, 버블정렬
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(1);
    int_vec.push_back(2);
    int_vec.push_back(8);
    int_vec.push_back(5);
    int_vec.push_back(3);
    std::cout << "정렬 이전 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl << "정렬 이후 ---- " << std::endl;
    bubble_sort(int_vec);
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;


    //객체함수 실습
    Comp2 comp2;
    bubble_sort(int_vec, comp2);
    std::cout << std::endl << "오름차순 정렬 이후 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }
    std::cout<<std::endl;

    Comp1 comp1;
    bubble_sort(int_vec, comp1);
    std::cout << std::endl << std::endl << "내림차순 정렬 이후 ---- " << std::endl;
    for (int i = 0; i < int_vec.size(); i++) {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;

    

    //템플릿 특수화 실습
    Vector<bool> bool_vec;
    bool_vec.push_back(true);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    bool_vec.push_back(true);
    bool_vec.push_back(false);
    std::cout << "-------- bool vector ---------" << std::endl;
    for (int i = 0; i < bool_vec.size(); i++) {
        std::cout << bool_vec[i];
    }
    std::cout << std::endl;
    return 0;
}